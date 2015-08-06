/*
 * GameBot.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: root
 */

#include "GameBot.h"
#include "BotMonitor.h"

GameBot::SecondTimer::SecondTimer(GameBot *bot)
	: m_pBot(bot)
{

}

GameBot::SecondTimer::~SecondTimer(void)
{

}

void GameBot::SecondTimer::handleTimeOut(void)
{
	//printf("SecondTimer::handleTimeOut\n");
	m_pBot->m_CBattle.SecondTimeOut();
}

GameBot::GameBot(const int fd, const std::string strAccout)
	: m_CLogin(this), m_CChat(this), //
	  m_CBattle(this),m_CSecondTimer(this)
{
	m_nFd = fd;
	m_strAccout = strAccout;
	m_nState = 0;

	m_nCharId = 0;
	memset(m_sCharName, 0, sizeof(m_sCharName));
	m_nLevel = 0;
	m_cJob = 0;// 0 , 1
	m_cGender = 0;// 0 -4
}

int GameBot::send(Buffer *buffer)
{
	return BOT_MONITOR->send(m_nFd, buffer);
}

int GameBot::dealMessage(Buffer *buffer)
{
	if (m_nState == 0)
	{
		return m_CLogin.login();
	}

	tdzm::NetPacketMessage head;
	*buffer >> head;

	switch (head.btSysId)
	{
	case tdzm::SystemId::sysLogin:
		m_CLogin.dealCmd(head.btCmd, buffer);
		break;
	case tdzm::SystemId::sysChat:
		m_CChat.dealCmd(head.btCmd, buffer);
		break;

	case tdzm::SystemId::sysBattle:
		m_CBattle.dealCmd(head.btCmd, buffer);
		break;

	default:
	{
		//LOG_DEBUG << "not registe sysId " << (int)head.btSysId << " cmd: " << (int)head.btCmd;
		if (head.btSysId == 31 && head.btCmd == 7)
		{
			m_CLogin.readyRunNty();
		}
	}
		return -1;
	}

	return 0;
}

int GameBot::startTimer(void)
{
	m_CSecondTimer.event_base(BOT_MONITOR->eventBase());
	m_CSecondTimer.scheduleTimer(1);

	return 0;
}

int GameBot::loginOut(void)
{
	m_CSecondTimer.cancelTimer();

	return 0;
}


