/*
 * main.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */
#include "GlobalInfo.h"
#include "event2/event.h"
#include "BotData.h"
#include "BotMonitor.h"
#include "SSTNetProtocol.h"
#include "Buffer.h"

void eventCallback(int fd, short which, void *arg)
{
	event_base *base = (event_base*)arg;
	event_base_loopexit(base, NULL);

	printf("bot event base stop!\n");
}

int main(int argc, char **argv)
{
	GlobalInfo::useThreads();

	BOT_DATA->inData(argc, argv);

	struct event_base *base = event_base_new();

	event *ev = evsignal_new(base, 2, eventCallback, (void* )base);
	if (!ev || event_add(ev, NULL) < 0)
	{
		event_del(ev);
		return false;
	}

	BOT_MONITOR->eventBase(base);
	BOT_MONITOR->init(BOT_DATA->m_nReceiveThread, BOT_DATA->m_nSendThread);
	BOT_MONITOR->start();

	event_base_dispatch(base);
	event_base_free(base);

	BOT_MONITOR->stop();
	BOT_MONITOR->final();

	printf("bot main stop!\n");

	return 0;
}


