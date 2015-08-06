/*
 * BotConnection.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: root
 */
#include "BotConnection.h"
#include "stdlib.h"
#include "BotMonitor.h"

BotConnection::BotConnection(void)
{
	m_nPackageIndex = 0;
	m_nPackageKey = 0;
}

BotConnection::~BotConnection(void)
{

}

int BotConnection::send(Buffer *buf)
{
	if (buf->Length() == 0)
	{
		return -1;
	}

	m_nPackageIndex++;
	unsigned int bufLen = buf->Length();
	tdzm::ClientNetPacketHeader header;
	Buffer *pEncodeBuffer = new Buffer();
	Buffer *pSendBuffer = new Buffer();
	*pSendBuffer = *buf;

	pEncodeBuffer->expand(sizeof(header) + bufLen);

	void *data = malloc(bufLen);
	pSendBuffer->removeData(data, bufLen);


	header.dwIdent = 0xAA8899BC;
	header.wPacketSize = bufLen;
	header.dwPacketIndex = tdzm::encrpytPacketIndex(m_nPackageIndex, m_nPackageKey, bufLen);
	header.wVerification = tdzm::calcPacketDataVerify(data, bufLen, m_nPackageKey);
	*pEncodeBuffer << header;

	tdzm::encryptClientPacket(data, bufLen, m_nPackageIndex);

	pEncodeBuffer->addData(data, bufLen);
	free(data);

	*buf = *pEncodeBuffer;

//	buf->move()

	delete pSendBuffer;
	delete pEncodeBuffer;

	return super::send(buf);
}

int BotConnection::receive(Buffer *buffer)
{
	if (m_nPackageKey == 0)
	{
		//first message
		uint firstLen = 128;
		if (buffer->Length() != firstLen)
		{
			printf("first message error\n");
			return -1;
		}

		unsigned char *keyBuf = (unsigned char*)malloc(firstLen);

		buffer->removeData((void*)keyBuf, firstLen);
		//保存通信数据包验证KEY
		m_nPackageKey = keyBuf[2 + keyBuf[0]] | (keyBuf[2 + keyBuf[1]] << 8);
		//printf("packKey = %d\n", m_nPackageKey);

		free(keyBuf);

		return 0;
	}

	return 0;
}
