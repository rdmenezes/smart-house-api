#pragma once

#include <iostream>
#include "cClient.h"
#include "cUtils.h"
#include "cClientsList.h"

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
	bool ProcessRegisterRequest(SOCKET ClientSocket, char* sMessage);
	bool ProcessLoginRequest(SOCKET ClientSocket, char* sMessage);
	bool ProcessLogoutRequest(SOCKET ClientSocket);
	bool IsUserRegistered(string sUsername);
	bool ProcessIMRequest(SOCKET ClientSocket,char* sMessage);
	bool ProcessStatusChangedRequest(SOCKET ClientSocket,char* sMessage);
	SOCKET FindSocketByUsername(string sUsername);
	//cClient* FindClientByUsername(string sUsername);
	//cClient* FindClientBySocketID(SOCKET SocketID);
	cClientsList* m_pClientsList;

public:

	static cMessageManager* Instance();
	SOCKET cMessageManager::GetClient(SOCKET Server);
	bool ProcessDialog(SOCKET Client);
	//int StartServer();
};