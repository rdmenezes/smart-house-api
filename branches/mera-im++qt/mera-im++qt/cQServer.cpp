#pragma once
#include "cQServer.h"

//////////////////////////////////////////////////////////////////////////////////////////
cQServer::cQServer()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
cQServer::~cQServer(void)
{
}

//////////////////////////////////////////////////////////////////////////////////////////
void cQServer::Start(int nPort)
{
	m_pTcpServer = new QTcpServer;
	StartServer (nPort);
}

//////////////////////////////////////////////////////////////////////////////////////////
void cQServer::StartServer (int nPort)
{
	if (!m_pTcpServer->listen(QHostAddress::Any, nPort)) 
	{
        emit ServerMessage("Unable to start server. Reason: " + QString("%1").arg(m_pTcpServer->errorString()) + "\n");
    }

	else
	{
		emit ServerMessage("Server is successfully started on port " + QString("%1").arg(nPort) + "\n");
		connect (m_pTcpServer, SIGNAL (newConnection()),this, SLOT (OnClientConnected(void)) );
//		while(nConnections <= 2)
//		{	
//			if(m_pTcpServer->waitForNewConnection(-1))
//			{
//				nConnections++;
//				QTcpSocket* pClient = m_pTcpServer->nextPendingConnection();
//				OnClientConnected (pClient);
//			}
//		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
void cQServer::OnClientConnected()
{
	QTcpSocket* pClient = new QTcpSocket();
	pClient = m_pTcpServer->nextPendingConnection();
	connect (pClient, SIGNAL (readyRead()),this, SLOT(OnDataFromClient()));
	pClient->write("You're connected to the server");
	emit ServerMessage("New client connected with socketID " +  QString("%1").arg(pClient->socketDescriptor()) + "\n");
}

//////////////////////////////////////////////////////////////////////////////////////////
void cQServer::OnDataFromClient()
{
	QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_2);
	QString buffer =  pClientSocket->readAll();
	cMessageManager::Instance()->ProcessDialog(pClientSocket,&buffer);
}

//////////////////////////////////////////////////////////////////////////////////////////
