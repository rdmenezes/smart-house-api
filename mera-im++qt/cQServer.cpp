#pragma once
#include "cQServer.h"


cQServer::cQServer(void)
{
	m_pTcpServer = new QTcpServer();
}


cQServer::~cQServer(void)
{
}

void cQServer::StartServer (int Port)
{
	unsigned int nMaxConnections = 2;
	unsigned int nConnections = 0; //Number of connected clients
	if (!m_pTcpServer->listen(QHostAddress::Any, Port)) 
	{
        qDebug() <<  QObject::tr("Unable to start the server: %1.")
                            .arg(m_pTcpServer->errorString());
    }

	else
	{
		while(nMaxConnections <= 2)
		{	
			if(m_pTcpServer->waitForNewConnection())
			{
				nConnections++;
				OnClientConnected (m_pTcpServer);
			}
		}
	}
}

void cQServer::OnClientConnected (QTcpServer* Server)
{
	QTcpSocket* pClientSocket = Server->nextPendingConnection();
	QDataStream in(pClientSocket);
	QString sData;
	quint16 blockSize = 2;

	in.setVersion(QDataStream::Qt_4_8);

	while (pClientSocket->bytesAvailable() < blockSize)
	{
		pClientSocket->readyRead();
	}
	

	in >> blockSize;
	in >> sData;
}