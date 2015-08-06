/*
 * BotData.h
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */

#ifndef BOTMANAGER_BOTDATA_H_
#define BOTMANAGER_BOTDATA_H_
#include <string>

class BotData
{
	//暂时使用宏定义，以后改成读配置表
public:
	static BotData* instance(void);

public:
	int m_nSendThread;
	int m_nReceiveThread;
	int m_nBotAmout;
	int m_nConnectHz;
	std::string m_strIp;
	int m_nPort;
	std::string m_strAccountPre;
	int m_nAccountIndex;
	unsigned int m_nVersionId;
	int m_nGameServerId;

	int m_nLoginAmount;

	int m_nMoveStopSecond;
	bool m_boBotMove;

	int inData(int argc, char **argv);
	int configCheck(void);

private:
	BotData(void);
    virtual ~BotData(void){};

private:
	static BotData* instance_;
};

#define BOT_DATA BotData::instance()



#endif /* BOTMANAGER_BOTDATA_H_ */
