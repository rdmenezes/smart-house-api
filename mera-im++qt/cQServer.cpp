#pragma once
#include "cQServer.h"

cQServer* cQServer::Instance()
{
	static cQServer pSelf;
	return &pSelf;
}

//////////////////////////////////////////////////////////////////////////////////////////
cQServer::cQServer() : m_nNextBlockSize(0)
{
		m_pTcpServer = new QTcpServer;
}

//////////////////////////////////////////////////////////////////////////////////////////
cQServer::~cQServer(void)
{
}

//////////////////////////////////////////////////////////////////////////////////////////
bool cQServer::Start(int nPort)
{
	//cMessageManager* pMSGManager = ;
	connect (cMessageManager::Instance(), SIGNAL (SendToClient(QTcpSocket*, QString)), SLOT (OnSendToClient(QTcpSocket*, QString)));
	return StartServer (nPort);
}

bool cQServer::Stop(void)
{
	// TODO: Error cases must be handled below
	m_pTcpServer->close();
	emit ServerMessage("Server is stopped\n");
	return true;
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
	OnSendToClient(pClient, "You're connected to the server");
	emit ServerMessage("New client connected with socketID " +  QString("%1").arg(pClient->socketDescriptor()) + "\n");
}

//////////////////////////////////////////////////////////////////////////////////////////
void cQServer::OnDataFromClient()
{
	/*QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_2);
	QString buffer =  pClientSocket->readAll();
	cMessageManager::Instance()->ProcessDialog(pClientSocket,&buffer);
	*/

	QTcpSocket* pClientSocket = (QTcpSocket*)sender();
	QDataStream in(pClientSocket);
	in.setVersion(QDataStream::Qt_4_2);
	for (;;) 
	{
		if (!m_nNextBlockSize) {
			if (pClientSocket->bytesAvailable() < sizeof(quint16)) {
				break;
			}
			in >> m_nNextBlockSize;
		}

		if (pClientSocket->bytesAvailable() < m_nNextBlockSize) {
			break;
		}
		int Type;
		QString str;
		in >> Type >>str;

		m_nNextBlockSize = 0;
		cMessageManager::Instance()->ProcessDialog(pClientSocket,Type,&str);
	}
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

//////////////////////////////////////////////////////////////////////////////////////////

void cQServer::OnSendToClient (QTcpSocket* pClientSocket, QString sMessage)
{
	QByteArray  arrBlock;
	QDataStream out(&arrBlock, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_2);
	out << quint16(0) << sMessage;

	out.device()->seek(0);
	out << quint16(arrBlock.size() - sizeof(quint16));

	pClientSocket->write(arrBlock);
}