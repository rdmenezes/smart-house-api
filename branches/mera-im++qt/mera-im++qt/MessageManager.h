#pragma once

#include <iostream>
#include "Client.h"
#include "Utils.h"
#include "ClientsList.h"
#include <QtNetwork>
#include <QMainWindow>
#include "QServer.h"
#include "Message.h"

using namespace std;

enum eMessageType {
	eMESSAGE_RegisterRequest,
	eMESSAGE_LoginRequest,
	eMESSAGE_LogoutRequest, 
	eMESSAGE_IM,
	eMESSAGE_StatusChanged};

class cMessageManager : public QObject
{

	Q_OBJECT

private:

	cMessageManager();
	~cMessageManager();
	eMessageType ProcessMessageType(char x);
	bool ProcessRegisterRequest(QTcpSocket* ClientSocket, QString* sMessage);
	bool ProcessLoginRequest(QTcpSocket* ClientSocket, QString* sMessage);
	bool ProcessLogoutRequest(QTcpSocket* ClientSocket);
	bool IsUserRegistered(QString sUsername);
    bool ProcessIMRequest(QString *sMessage);
	bool ProcessStatusChangedRequest(QTcpSocket* ClientSocket,QString* sMessage);
    QTcpSocket* FindSocketByUsername(QString sUsername);
	cClientsList* m_pClientsList;

	void OnRegisterRequest(cRegisterRequest* pRequest);


public:

	static cMessageManager* Instance();
    int GetClient(int Server);
	bool ProcessDialog(QTcpSocket* Client,int nType, QString* Message);
	cClientsList* GetClientsList();
	void OnMessage(cBaseMessage* pMessage, QTcpSocket* pSenderSocket);

signals:
	void SendToClient(QTcpSocket* pClientSocket, QString sMessage);
};
