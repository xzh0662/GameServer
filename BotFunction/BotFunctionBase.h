/*
 * BotFunctionBase.h
 *
 *  Created on: Mar 11, 2015
 *      Author: root
 */

#ifndef BOTFUNCTION_BOTFUNCTIONBASE_H_
#define BOTFUNCTION_BOTFUNCTIONBASE_H_

#include "SSTNetCmd.h"
#include "SSTSysId.h"
#include "Buffer.h"
#include "LogClient.h"
#include "BotData.h"
#include "stdlib.h"

class GameBot;
class BotFunctionBase
{
public:
	BotFunctionBase(GameBot *bot)
	{
		m_pBot = bot;
	}
	virtual ~BotFunctionBase(void)
	{
	}

	virtual int dealCmd(const int cmd, Buffer *buffer) = 0;

protected:
	typedef BotFunctionBase super;

	int send(Buffer *buffer);

	GameBot *m_pBot;
};



#endif /* BOTFUNCTION_BOTFUNCTIONBASE_H_ */
