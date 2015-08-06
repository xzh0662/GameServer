/*
 * BotData.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */
#include "BotData.h"
#include "stdio.h"
#include "stdlib.h"

#define RECEIVE_THREAD 0
#define SEND_THREAD 0
#define BOT_AMOUT 5000
#define CONNECT_HZ 500
#define SERVER_IP "192.168.15.246"
//#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 1989
#define BOT_ACCOUNT_PRE "move"
#define BOT_ACCOUNT_INDEX 2
#define GAME_VERSION 17761030
#define GAME_SERVER_ID -1
#define BOT_MOVE 0

#define BOT_MOVE_STOP_SECOND 2

BotData* BotData::instance_ = 0;
BotData* BotData::instance(void)
{
    if (instance_ == 0)
    {
        instance_ = new BotData();
    }
    return instance_;
}

int BotData::inData(int argc, char **argv)
{
	if (argc >= 1)
	{
		printf("argv0 = %s\n", argv[0]);
	}
	if (argc >= 2)
	{
		printf("RECEIVE_THREAD = %s\n", argv[1]);
		m_nReceiveThread = atoi(argv[1]);
	}
	if (argc >= 3)
	{
		printf("SEND_THREAD = %s\n", argv[2]);
		m_nSendThread = atoi(argv[2]);
	}
	if (argc >= 4)
	{
		printf("BOT_AMOUT = %s\n", argv[3]);
		m_nBotAmout= atoi(argv[3]);
	}
	if (argc >= 5)
	{
		printf("IP = %s\n", argv[4]);
		m_strIp = argv[4];
	}
	if (argc >= 6)
	{
		printf("port = %s\n", argv[5]);
		m_nPort = atoi(argv[5]);
	}
	if (argc >= 7)
	{
		printf("BOT_ACCOUNT_PRE = %s\n", argv[6]);
		m_strAccountPre= argv[6];
	}
	return 0;
}

int BotData::configCheck(void)
{
	if (m_nSendThread < 0 || m_nReceiveThread < 0)
	{
		printf("thread config error\n");
	}

	if (m_nBotAmout <= 0)
	{
		printf("BOT_AMOUT config error\n");
	}

	if (m_nConnectHz <= 0)
	{
		printf("CONNECT_HZ config error\n");
	}

	if (m_nPort <= 0)
	{
		printf("Port config error\n");
	}

	if (m_nAccountIndex < 0)
	{
		printf("AccountIndex config error\n");
	}

	return 0;
}

BotData::BotData(void)
{
	// 暂时使用宏定义，以后改成读配置表
	m_nSendThread = SEND_THREAD;
	m_nReceiveThread = RECEIVE_THREAD;
	m_nBotAmout = BOT_AMOUT;
	m_nConnectHz = CONNECT_HZ;
	m_strIp = SERVER_IP;
	m_nPort = SERVER_PORT;
	m_strAccountPre = BOT_ACCOUNT_PRE;
	m_nAccountIndex = BOT_ACCOUNT_INDEX;
	m_nVersionId = GAME_VERSION;
	m_nGameServerId = GAME_SERVER_ID;
	m_nLoginAmount = 0;
	m_nMoveStopSecond = BOT_MOVE_STOP_SECOND;
	m_boBotMove = BOT_MOVE;

}
