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
	unsigned int nConnections = 0; //Number of connected clients
	if (!m_pTcpServer->listen(QHostAddress::Any, Port)) 
	{
        qDebug() <<  QObject::tr("Unable to start the server: %1.")
                            .arg(m_pTcpServer->errorString());
    }

	else
	{
	//	while(nMaxConnections <= 2)
	//	{	
			if(m_pTcpServer->waitForNewConnection(5000000000))
			{
				nConnections++;
				OnClientConnected (m_pTcpServer);
			}
	//	}
	}
}

void cQServer::OnClientConnected (QTcpServer* Server)
{
	QTcpSocket* pClientSocket = Server->nextPendingConnection();
	connect (pClientSocket, SIGNAL (readyRead()),this, SLOT(OnDataFromClient()));
	pClientSocket->write("You're connected to the server");
	emit StartServerResponce("New client connected with socketID " +  QString("%1").arg(pClientSocket->socketDescriptor()));
}
void cQServer::OnDataFromClient()
{
	QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_2);
	QString buffer =  pClientSocket->readAll();
	cMessageManager::Instance()->ProcessDialog(pClientSocket,&buffer);
}
