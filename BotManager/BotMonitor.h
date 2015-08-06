/*
 * BotMonitor.h
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */

#ifndef BOTMANAGER_BOTMONITOR_H_
#define BOTMANAGER_BOTMONITOR_H_

#include "TcpMonitor.h"
#include "InetAddr.h"
#include "BotConnection.h"

class GameBot;
class BotMonitor : public TcpMonitor
{
	typedef std::map<int, BotConnection*> ConnMap;
	typedef std::map<int, GameBot*> BotMap;
public:
	static BotMonitor* instance(void);

	virtual int start(void);
	virtual int stop(void);

	int allSend(Buffer *buffer);
	virtual int receive(int fd, Buffer *buffer);
	virtual void handleClosed(int fd);

	int connect(const InetAddr& serverAddr);

	GameBot* findBot(const int fd);

protected:
	BotConnection* findConnection(int fd);
	virtual int sendMessage(int fd, Buffer *buffer);

private:
    BotMonitor(void){};
    virtual ~BotMonitor(void){};

private:
	static BotMonitor* instance_;

	MutexLock m_mutex;
	ConnMap m_connMap;//need to lock
	BotMap m_botMap;//need to lock
};

#define BOT_MONITOR BotMonitor::instance()

#endif /* BOTMANAGER_BOTMONITOR_H_ */
