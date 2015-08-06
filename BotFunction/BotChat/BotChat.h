/*
 * BotChat.h
 *
 *  Created on: Mar 11, 2015
 *      Author: root
 */

#ifndef BOTFUNCTION_BOTCHAT_BOTCHAT_H_
#define BOTFUNCTION_BOTCHAT_BOTCHAT_H_
#include "BotFunctionBase.h"

class BotChat : public BotFunctionBase
{
public:
	BotChat(GameBot *bot);
	virtual ~BotChat(void);

	virtual int dealCmd(const int cmd, Buffer *buffer);

	int chatWorld(const char *str);
};



#endif /* BOTFUNCTION_BOTCHAT_BOTCHAT_H_ */
