/*
 * BotFunctionBase.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: root
 */

#include "BotFunctionBase.h"
#include "GameBot.h"

int BotFunctionBase::send(Buffer *buffer)
{
	if (m_pBot == NULL)
	{
		return -1;
	}
	return m_pBot->send(buffer);
}


