/*
 * BotLogin.h
 *
 *  Created on: Mar 10, 2015
 *      Author: root
 */

#ifndef BOTFUNCTION_LOGIN_BOTLOGIN_H_
#define BOTFUNCTION_LOGIN_BOTLOGIN_H_

#include "BotFunctionBase.h"

class BotLogin : public BotFunctionBase
{
public:
	BotLogin(GameBot* bot);
	virtual ~BotLogin(void);

	virtual int dealCmd(const int cmd, Buffer *buffer);
	int login(void);
	int readyRunNty(void);

private:
	int loginRet(Buffer *buffer);
	int queryCharList(void);
	int queryCharListRet(Buffer *buffer);
	int createChar(void);
	int createCharRet(Buffer *buffer);
	int enterGame(void);
	int enterGameRet(void);

};



#endif /* BOTFUNCTION_LOGIN_BOTLOGIN_H_ */
