#pragma once

#include <QtNetwork>
#include "MessageManager.h"

class cQServer : public QObject
{
	Q_OBJECT

public:

	static cQServer* Instance();
	
	bool Start (int nPort);
	bool Stop (void);


private:
	QTcpServer* m_pTcpServer;
	quint16 m_nNextBlockSize;
	cQServer(void);
	~cQServer(void);

	bool StartServer (int nPort);
	
public slots:
	void OnDataFromClient();
	void OnClientConnected ();
	void OnClientDisconnected();
	
public slots:
	void OnSendToClient(QTcpSocket* pClientSocket, QString sMessage);

signals:
	void ServerMessage(QString responce);
	void ServerStarted();
};