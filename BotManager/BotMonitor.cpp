/*
 * BotMonitor.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */

#include "BotMonitor.h"
#include "BotConnection.h"
#include "BotData.h"
#include "LogClient.h"
#include "SSTSysId.h"
#include "SSTNetCmd.h"
#include "GameBot.h"

BotMonitor* BotMonitor::instance_ = 0;
BotMonitor* BotMonitor::instance(void)
{
    if (instance_ == 0)
    {
        instance_ = new BotMonitor();
    }
    return instance_;
}

int BotMonitor::start(void)
{
	if (TcpMonitor::start() != 0)
	{
		return -1;
	}

	InetAddr serverAddr(BOT_DATA->m_strIp, BOT_DATA->m_nPort);
	BOT_MONITOR->connect(serverAddr);

	Buffer *buffer = new Buffer();
	*buffer << 0;

	BOT_MONITOR->allSend(buffer);

	return 0;
}

int BotMonitor::stop(void)
{
	if (TcpMonitor::stop() != 0)
	{
		return -1;
	}

	MutexLockConditionGuard lock(this->m_mutex, this->threadType() == TT_multi_thread);
	this->m_connMap.clear();
	for (BotMap::iterator iter = this->m_botMap.begin(); iter != this->m_botMap.end(); ++iter)
	{
		if (iter->second != NULL)
		{
			delete iter->second;
		}
	}
	this->m_botMap.clear();

	return 0;
}

int BotMonitor::allSend(Buffer *buffer)
{
	for (ConnMap::iterator iter = this->m_connMap.begin(); iter != this->m_connMap.end();++iter)
	{
		BotConnection *conn = iter->second;

		Buffer *sendBuffer = new Buffer();
		*sendBuffer = *buffer;

		TcpMonitor::send(conn->fd(), sendBuffer);
	}

	return 0;
}

int BotMonitor::receive(int fd, Buffer *buffer)
{//如果有接收线程则由接收线程回调，否则由event_base 线程调用
	BotConnection* conn = this->findConnection(fd);
	if (conn == NULL)
	{
		return -1;
	}

	//printf("receive fd = %d buf size = %d\n", fd, (int)buffer->Length());

	if (conn->receive(buffer) != 0)
	{
		return -1;
	}

	GameBot* bot = this->findBot(fd);
	if (bot == NULL)
	{
		LOG_DEBUG << "connot find bot fd" << fd;
		return -1;
	}

	return bot->dealMessage(buffer);
}

void BotMonitor::handleClosed(int fd)
{//event_base 线程调用
	MutexLockConditionGuard lock(this->m_mutex, this->threadType() == TT_multi_thread);
	this->m_connMap.erase(fd);

	BotMap::iterator iter = m_botMap.find(fd);

	GameBot *bot = iter->second;
	if (iter != m_botMap.end())
	{
		bot->loginOut();
	}

	delete bot;
	m_botMap.erase(iter);
}

int BotMonitor::connect(const InetAddr& serverAddr)
{
	MutexLockConditionGuard lock(this->m_mutex, this->threadType() == TT_multi_thread);
	for (int i = BOT_DATA->m_nAccountIndex; //
			i < BOT_DATA->m_nAccountIndex + BOT_DATA->m_nBotAmout; ++i)
	{
		BotConnection *conn = new BotConnection();
		conn->init(i, this, true);
		bufferevent_socket_connect(conn->bevent(),//
				(struct sockaddr *)&serverAddr.addr_,//
				sizeof(serverAddr.addr_));

		std::string strIndex = convert<std::string>(i);
		std::string strAccount = BOT_DATA->m_strAccountPre + strIndex + "&";

		this->m_connMap.insert(std::make_pair(i, conn));
		GameBot* bot = new GameBot(i, strAccount);
		this->m_botMap.insert(std::make_pair(i, bot));

		int hz = BOT_DATA->m_nConnectHz > 0 ? BOT_DATA->m_nConnectHz : 10;
		usleep(1000000 / hz);
	}

	return 0;
}

GameBot* BotMonitor::findBot(const int fd)
{
	MutexLockConditionGuard lock(this->m_mutex, this->threadType() == TT_multi_thread);
	BotMap::iterator iter = this->m_botMap.find(fd);
	if (iter == this->m_botMap.end())
	{
		return NULL;
	}
	else
	{
		return iter->second;
	}
}

BotConnection* BotMonitor::findConnection(int fd)
{
	MutexLockConditionGuard lock(this->m_mutex, this->threadType() == TT_multi_thread);
	ConnMap::iterator iter = this->m_connMap.find(fd);
	if (iter == this->m_connMap.end())
	{
		return NULL;
	}

	return iter->second;
}

int BotMonitor::sendMessage(int fd, Buffer *buffer)
{//如果有发送线程则由发送线程回调，否则由event_base 线程调用
	BotConnection* conn = this->findConnection(fd);
	if (conn == NULL)
	{
		return -1;
	}

	return conn->send(buffer);
}

