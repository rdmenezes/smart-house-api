#pragma once

#include <QtNetwork>
#include "cMessageManager.h"

class cQServer : public QObject
{
	Q_OBJECT

public:
	cQServer(void);
	~cQServer(void);

	
	void Start (int nPort);


private:
	QTcpServer* m_pTcpServer;

	void StartServer (int nPort);
	
private slots:
	void OnDataFromClient();
	void OnClientConnected ();

signals:
	void ServerMessage(QString responce);
	void ServerStarted();
};