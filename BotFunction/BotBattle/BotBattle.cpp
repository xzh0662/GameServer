/*
 * BotBattle.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: root
 */
#include "BotBattle.h"
#include "GameBot.h"
#include "string.h"

#define FIRST_MAP_MIN_X 71
#define FIRST_MAP_MAN_X 2921

BotBattle::BotBattle(GameBot *bot)
	: super(bot)
{
	m_nSceneId = 0;
	m_nX = 0;
	m_nY = 0;
	m_nMoveTick = 0;
	m_nStopSecond = 0;
	m_nRuning = rtStop;
	m_nSpeedX = 0;
	m_nSpeedY = 0;
}

BotBattle::~BotBattle(void)
{

}

int BotBattle::dealCmd(const int cmd, Buffer *buffer)
{
	switch(cmd)
	{
	case tdzm::NetCmd::sStartRun :
		this->startRunRet(buffer);
		break;

	case tdzm::NetCmd::sStopRun :
		this->stopRunRet(buffer);
		break;

	case tdzm::NetCmd::sSetPosition:
		this->setPositionNty(buffer);
		break;

	case tdzm::NetCmd::sSwitchScene:
		this->switchSceneRet(buffer);
		break;

	default:
		//LOG_DEBUG << "not registe battle sys cmd: " << (int)cmd;
		break;
	}

	return 0;
}

int BotBattle::SecondTimeOut(void)
{
	if (!BOT_DATA->m_boBotMove)
	{
		return -1;
	}

	m_nMoveTick++;
	if (m_nRuning == rtStop)
	{
		if (m_nStopSecond >= BOT_DATA->m_nMoveStopSecond + m_pBot->m_nCharId % 3)
		{
			this->startRun();
		}
		else
		{
			m_nStopSecond++;
		}
	}
	else
	{
		m_nX += m_nSpeedX;
		m_nY += m_nSpeedY;

		//LOG_DEBUG << "x "<< m_pBot->m_iX;

		if(m_nRuning == rtRigth)
		{
			if (m_nX >= FIRST_MAP_MAN_X)
			{
				m_nX = FIRST_MAP_MAN_X;
				this->stopRun();
			}
		}
		else if (m_nRuning == rtLeft)
		{
			if (m_nX <= FIRST_MAP_MIN_X)
			{
				m_nX = FIRST_MAP_MIN_X;
				this->stopRun();
			}
		}
	}

	return 0;
}

int BotBattle::startRun(void)
{
	if (m_nX > (FIRST_MAP_MAN_X - FIRST_MAP_MIN_X) / 2)
	{
		m_nSpeedX = -500;
		m_nRuning = rtLeft;
	}
	else
	{
		m_nSpeedX = 500;
		m_nRuning = rtRigth;
	}
	int mx = m_nX;
	int my = m_nY;
	short sx = m_nSpeedX;
	short sy = m_nSpeedY;
	unsigned short accTime = 0;
	unsigned int clientTick = m_nMoveTick;

	Buffer *buf = new Buffer;

	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysBattle;
	head.btCmd =tdzm::NetCmd::cStartRun;

	*buf << head;

	*buf << mx << my << sx << sy << accTime << clientTick;

	return this->send(buf);
}

int BotBattle::stopRun(void)
{
	m_nRuning = rtStop;

	int mx = m_nX;
	int my = m_nY;
	unsigned int clientTick = m_nMoveTick;

	Buffer *buf = new Buffer;

	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysBattle;
	head.btCmd =tdzm::NetCmd::cStopRun;

	*buf << head;

	*buf << mx << my << clientTick;

	return this->send(buf);
}

int BotBattle::startRunRet(Buffer *buffer)
{
//	起跑：
//	sysid:4 cmd:6
	long long userId;
	int mx;
	int my;
	short sx;
	short sy;
	unsigned short accTime;

	*buffer >> userId;
	*buffer >> mx;
	*buffer >> my;
	*buffer >> sx;
	*buffer >> sy;
	*buffer >> accTime;

//	LOG_DEBUG << " userId " << userId;
//	LOG_DEBUG << " mx " << mx;
//	LOG_DEBUG << " my " << my;
//	LOG_DEBUG << " sx " << sx;
//	LOG_DEBUG << " sy " << sy;
//	LOG_DEBUG << " accTime " << accTime;

	return 0;
}

int BotBattle::switchSceneRet(Buffer *buffer)
{
	char sceneName[100], mapFileName[100];
	char *pSceneName = sceneName;
	char *pMapFileName = mapFileName;
	memset(sceneName, 0, sizeof(sceneName));
	memset(mapFileName, 0, sizeof(mapFileName));

	int DuplicateId = 0;

	*buffer >> m_nSceneId;
	*buffer >> pSceneName;
	*buffer >> pMapFileName;
	*buffer >> DuplicateId;
	*buffer >> m_nX;
	*buffer >> m_nY;

	LOG_DEBUG << "scene " << m_nSceneId << " x " << m_nX << " y " << m_nY;

	this->sceneReady();

	return 0;
}

int BotBattle::stopRunRet(Buffer *buffer)
{
//	停跑：
//	sysid:4 cmd:7
	long long userId;
	int mx;
	int my;

	*buffer >> userId;
	*buffer >> mx;
	*buffer >> my;

//	LOG_DEBUG << " userId " << userId;
//	LOG_DEBUG << " mx " << mx;
//	LOG_DEBUG << " my " << my;

	return 0;
}

int BotBattle::setPositionNty(Buffer *buffer)
{
//	pack << m_pActor->m_EntityId.llid;
//		pack << m_pActor->m_nX;
//		pack << m_pActor->m_nY;
	long long llid;
	int m_nX = 0;
	int m_nY = 0;

	*buffer >> llid;
	*buffer >> m_nX;
	*buffer >> m_nY;

//	LOG_DEBUG << " llid " << llid;
//	LOG_DEBUG << " m_nX " << m_nX;
//	LOG_DEBUG << " m_nY " << m_nY;

	return 0;
}

int BotBattle::sceneReady(void)
{
	int nSceneId = m_nSceneId, nDupId = 0, nDupGUID = 0;

	Buffer *buf = new Buffer;

	tdzm::NetPacketMessage head;
	head.btSysId = tdzm::SystemId::sysBattle;
	head.btCmd =tdzm::NetCmd::cSceneReady;

	*buf << head;

	*buf << nSceneId << nDupId << nDupGUID;

	return this->send(buf);
}


