/*
 * GameBot.h
 *
 *  Created on: Mar 10, 2015
 *      Author: root
 */

#ifndef BOTMANAGER_GAMEBOT_H_
#define BOTMANAGER_GAMEBOT_H_
#include <string>
#include <Buffer.h>
#include "BotLogin.h"
#include "BotChat.h"
#include "BotBattle.h"
#include "BaseTimer.h"

class GameBot
{
public:
	class SecondTimer : public BaseTimer
	{
	public:
		SecondTimer(GameBot *bot);
		virtual  ~SecondTimer(void);

		virtual void handleTimeOut(void);

	private:
		GameBot *m_pBot;
	};
public:
	GameBot(const int fd, const std::string strAccout);
	~GameBot(void){};

	int send(Buffer *buffer);

	int dealMessage(Buffer *buffer);

	int startTimer(void);

	int loginOut(void);

	BotLogin m_CLogin;
	BotChat m_CChat;
	BotBattle m_CBattle;

	SecondTimer m_CSecondTimer;

	int m_nFd;
	std::string m_strAccout;

	int m_nState;

	long long int m_nCharId;
	char m_sCharName[48];
	unsigned short m_nLevel;
	char m_cJob;// 0 , 1
	char m_cGender;// 0 -4
};



#endif /* BOTMANAGER_GAMEBOT_H_ */
