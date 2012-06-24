#pragma once

#include <QtNetwork>
#include "cMessageManager.h"

class cQServer : public QObject
{
	Q_OBJECT

public:
	cQServer(void);
	~cQServer(void);

	
	bool Start (int nPort);
	bool Stop (void);


private:
	QTcpServer* m_pTcpServer;

	bool StartServer (int nPort);
	
private slots:
	void OnDataFromClient();
	void OnClientConnected ();
	void OnClientDisconnected();

signals:
	void ServerMessage(QString responce);
	void ServerStarted();
};