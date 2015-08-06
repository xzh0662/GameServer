/*
 * BotLogin.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: root
 */
#include "BotLogin.h"
#include "GameBot.h"
#include "BotMonitor.h"

BotLogin::BotLogin(GameBot* bot)
	: super(bot)
{
}

BotLogin::~BotLogin(void)
{

}

int BotLogin::dealCmd(const int cmd, Buffer *buffer)
{
	switch(cmd)
	{
	case tdzm::NetCmd::sLoginRet :
		this->loginRet(buffer);
		break;

	case tdzm::NetCmd::sSendCharList :
		this->queryCharListRet(buffer);
		break;

	case tdzm::NetCmd::sCreateCharRet:
		this->createCharRet(buffer);
		break;

	case tdzm::NetCmd::sEnterGameRet:
		this->enterGameRet();
		break;

//	case tdzm::NetCmd::sReadyForRun:
//		this->readyRunNty();
//		break;

	default:
		LOG_DEBUG << "not registe login sys cmd: " << (int)cmd;
		break;
	}
	return 0;
}

int BotLogin::login(void)
{
	//		unsigned short Accountlen;
	//			char *Accountstr;
	//			unsigned short PasswdLen;
	//			char *Passwd;
	//			unsigned int version;
	//			unsigned int platform;
	//			int serverid;
	// char *session id

	Buffer *buf = new Buffer;
	std::string pwd = "e10adc3949ba59abbe56e057f20f883e";
	std::string sessionId = "";
	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysLogin;
	head.btCmd = tdzm::NetCmd::cRequestLogin;
	*buf << head			//
			<< m_pBot->m_strAccout.c_str() //
			<< pwd.c_str() //
			<< BOT_DATA->m_nVersionId //
	<< 1//
	<< BOT_DATA->m_nGameServerId//
	<< sessionId.c_str();

	m_pBot->m_nState = 1;

	return this->send(buf);
}

int BotLogin::readyRunNty(void)
{
	LOG_DEBUG<< "login sucess amount : " << ++BOT_DATA->m_nLoginAmount;

	m_pBot->m_CChat.chatWorld("@level 11");

	m_pBot->m_CChat.chatWorld("@duppass 119");

	m_pBot->startTimer();

	return 0;
}

int BotLogin::loginRet(Buffer *buffer)
{
//	packet.writeCmd(tdzm::SystemId::sysLogin, tdzm::NetCmd::sLoginRet);
//	packet << (int)pData->login.nErrorCode;
//	packet << (int)pData->login.nUserId;
//	packet << (int)g_LogicServer->getServerId();
//	packet << (bool)g_LogicDataConfig->m_boOpenRecharge;
//	packet << (bool)g_LogicDataConfig->m_boOpenAutoAttack;

	int error = 0, severId = 0, accoutId = 0;
	bool isRecharge, isAutoAttack;
	*buffer >> error >> accoutId >> severId >> isRecharge >> isAutoAttack;

	//LOG_DEBUG << "error " << error << " accoutId " << accoutId << " serverId " << severId;

	if (error == 0)
	{
		this->queryCharList();
	}

	return 0;
}

int BotLogin::queryCharList(void)
{
	Buffer *buf = new Buffer;

	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysLogin;
	head.btCmd =tdzm::NetCmd::cQueryCharList;

	*buf << head;

	return this->send(buf);
}

int BotLogin::queryCharListRet(Buffer *buffer)
{
//	S：
//	Head;
//	Msghead;
//	Int charCount;
//	for i=0 to charcount
//	{
//	pack << pDesc->nCharId; à long long int
//	pack << pDesc->sCharName; à 先有一个short类型字符串长度，再有字符串信息
//	pack << pDesc->wLevel; àunsigned short
//	pack << pDesc->btJob;  à char
//	pack << pDesc->btGender; à char
//	pack << nLastCharIdx;  àint
//	}
//	pack << sRandomName;  à 随机玩家名字，先有一个short类型字符串长度，再有字符串信息

	int charCount = 0;
	*buffer >> charCount;
	//LOG_DEBUG << "charCount " << charCount;

	if (charCount == 0)
	{
		return this->createChar();
	}
	//only use first

	char *name = m_pBot->m_sCharName;
	*buffer >> m_pBot->m_nCharId;//
	*buffer >> name;
	*buffer >> m_pBot->m_nLevel;
	*buffer >> m_pBot->m_cJob;
	*buffer >> m_pBot->m_cGender;

//	LOG_DEBUG << " nCharId "<< m_pBot->m_nCharId;//
//	LOG_DEBUG <<" sCharName "<< m_pBot->m_sCharName;//6
//	LOG_DEBUG << " wLevel "<< m_pBot->m_wLevel;//
//	LOG_DEBUG <<" btJob " << (int)m_pBot->m_btJob;//
//	LOG_DEBUG <<" btGender " << (int)m_pBot->m_btGender;

	return this->enterGame();
}

int BotLogin::createChar(void)
{
//	C:
//	char sCharName[48];
//	char btJob
//	char btGender

	std::string strCharName = m_pBot->m_strAccout;
	strCharName[strCharName.length() - 1] = '\0';
	char btGender = rand() % 2;
	char btJob = rand() % 4;

	Buffer *buf = new Buffer;

	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysLogin;
	head.btCmd =tdzm::NetCmd::cCreateChar;

	*buf << head;

	*buf << strCharName.c_str()  << btJob << btGender;

	return this->send(buf);
}

int BotLogin::createCharRet(Buffer *buffer)
{
	//	S:
	//	pack << (int)errcode;
	//	pack << (long int)pDesc->nCharId;
	//	pack << (char *)pDesc->sCharName;
	//	pack << (unsigned short)pDesc->wLevel;
	//	pack << (char)pDesc->btJob;
	//	pack << (char)pDesc->btGender;

	int errcode = 0;

	*buffer >> errcode;//

	//LOG_DEBUG <<" errcode "<< errcode;//
	if (errcode == 0)
	{
		char *name = m_pBot->m_sCharName;
		*buffer >> m_pBot->m_nCharId;//
		*buffer >> name;
		*buffer >> m_pBot->m_nLevel;
		*buffer >> m_pBot->m_cJob;
		*buffer >> m_pBot->m_cGender;

//		LOG_DEBUG << " nCharId "<< m_pBot->m_nCharId;//
//		LOG_DEBUG <<" sCharName "<< m_pBot->m_sCharName;//
//		LOG_DEBUG << " wLevel "<< m_pBot->m_wLevel;//
//		LOG_DEBUG <<" btJob " << (int)m_pBot->m_btJob;//
//		LOG_DEBUG <<" btGender " << (int)m_pBot->m_btGender;
	}
	else
	{
		return -1;
	}

	return this->enterGame();
}

int BotLogin::enterGame(void)
{
//	C:
//	inPacket >> (unsigned long long)pSession->PlayerId
//	sCharName 48字节

	Buffer *buf = new Buffer;

	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysLogin;
	head.btCmd =tdzm::NetCmd::cEnterGame;

	*buf << head;

	*buf << m_pBot->m_nCharId;
	*buf << m_pBot->m_sCharName;

	return this->send(buf);
}

int BotLogin::enterGameRet(void)
{
	//return m_pBot->m_CChat.chatWorld("@duppass 119");
	return 0;
}


