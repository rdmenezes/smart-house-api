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
bool cQServer::Start(int nPort)
{
	m_pTcpServer = new QTcpServer;
	return StartServer (nPort);
}

//////////////////////////////////////////////////////////////////////////////////////////
bool cQServer::StartServer (int nPort)
{
	if (!m_pTcpServer->listen(QHostAddress::Any, nPort)) 
	{
        emit ServerMessage("Unable to start server. Reason: " + QString("%1").arg(m_pTcpServer->errorString()) + "\n");
		return false;
    }

	else
	{
		emit ServerMessage("Server is successfully started on port " + QString("%1").arg(nPort) + "\n");
		connect (m_pTcpServer, SIGNAL (newConnection()),this, SLOT (OnClientConnected(void)));
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////
void cQServer::OnClientConnected()
{
	QTcpSocket* pClient = new QTcpSocket();
	pClient = m_pTcpServer->nextPendingConnection();
	connect (pClient, SIGNAL (readyRead()),this, SLOT(OnDataFromClient()));
	connect (pClient, SIGNAL (disconnected()),this, SLOT (OnClientDisconnected()));
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

void cQServer::OnClientDisconnected()
{
	QTcpSocket* pClient = (QTcpSocket*)sender();
	
	if(!pClient)
	{
		return;
	}

	emit ServerMessage ("Client " +  QString("%1").arg(pClient->peerAddress().toString()) + " disconnected from the server\n" );
	pClient->deleteLater();
}