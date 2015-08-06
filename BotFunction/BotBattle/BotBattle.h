/*
 * BotBattle.h
 *
 *  Created on: Mar 12, 2015
 *      Author: root
 */

#ifndef BOTFUNCTION_BOTBATTLE_BOTBATTLE_H_
#define BOTFUNCTION_BOTBATTLE_BOTBATTLE_H_
#include "BotFunctionBase.h"

enum RuningType
{
	rtLeft = 1,
	rtRigth = 2,
	rtStop = 3
};

class BotBattle : public BotFunctionBase
{
public:
	BotBattle(GameBot *bot);
	~BotBattle(void);

	virtual int dealCmd(const int cmd, Buffer *buffer);

	int SecondTimeOut(void);

	int startRun(void);
	int stopRun(void);

	int startRunRet(Buffer *buffer);
	int stopRunRet(Buffer *buffer);

	int switchSceneRet(Buffer *buffer);

	int setPositionNty(Buffer *buffer);

	int sceneReady(void);

	int m_nSceneId;
	int m_nX;
	int m_nY;

	int m_nMoveTick;
	int m_nStopSecond;
	int m_nRuning;
	short m_nSpeedX;
	short m_nSpeedY;
};



#endif /* BOTFUNCTION_BOTBATTLE_BOTBATTLE_H_ */
