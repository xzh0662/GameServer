/*
 * BotConnection.h
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */

#ifndef BOTMANAGER_BOTCONNECTION_H_
#define BOTMANAGER_BOTCONNECTION_H_
#include "TcpConnection.h"

class BotConnection : public TcpConnection
{
	typedef TcpConnection super;
public:
	BotConnection(void);
	virtual ~BotConnection(void);

	virtual int send(Buffer *buf);
	int receive(Buffer *buffer);

private:
	unsigned int m_nPackageIndex;
	unsigned int m_nPackageKey;
};



#endif /* BOTMANAGER_BOTCONNECTION_H_ */
