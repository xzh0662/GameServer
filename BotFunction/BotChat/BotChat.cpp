/*
 * BotChat.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: root
 */
#include "BotChat.h"

BotChat::BotChat(GameBot *bot)
	: super(bot)
{

}

BotChat::~BotChat(void)
{
}

int BotChat::dealCmd(const int cmd, Buffer *buffer)
{
	switch(cmd)
	{
//	case tdzm::NetCmd::sLoginRet :
//		this->loginRet(buffer);
//		break;

	default:
		LOG_DEBUG << "not registe chat sys cmd: " << (int)cmd;
		break;
	}
	return 0;
}

int BotChat::chatWorld(const char *str)
{
	Buffer *buf = new Buffer;

	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysChat;
	head.btCmd =tdzm::NetCmd::cChatReqWorld;

	*buf << head;

	*buf << str;

	return this->send(buf);
}


