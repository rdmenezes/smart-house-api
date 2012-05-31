#pragma once

#include <iostream>
#include "cClient.h"
#include "cUtils.h"
#include "cClientsList.h"
#include <QtNetwork>

using namespace std;

enum eMessageType {
	eMESSAGE_RegisterRequest,
	eMESSAGE_LoginRequest,
	eMESSAGE_LogoutRequest, 
	eMESSAGE_IM,
	eMESSAGE_StatusChanged};

class cMessageManager 
{
private:

	cMessageManager();
	~cMessageManager();
	static cMessageManager* m_pSelf; 
	eMessageType ProcessMessageType(char x);
	bool ProcessRegisterRequest(QTcpSocket* ClientSocket, QString* sMessage);
	bool ProcessLoginRequest(QTcpSocket* ClientSocket, QString* sMessage);
	bool ProcessLogoutRequest(QTcpSocket* ClientSocket);
	bool IsUserRegistered(QString sUsername);
    bool ProcessIMRequest(QString *sMessage);
	bool ProcessStatusChangedRequest(QTcpSocket* ClientSocket,QString* sMessage);
    int FindSocketByUsername(QString sUsername);
	//cClient* FindClientByUsername(string sUsername);
	//cClient* FindClientBySocketID(SOCKET SocketID);
	cClientsList* m_pClientsList;

public:

	static cMessageManager* Instance();
    int cMessageManager::GetClient(int Server);
	bool ProcessDialog(QTcpSocket* Client, QString* Message);
	//int StartServer();
};
