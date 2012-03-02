#pragma once

#include "iostream"
#include "winsock2.h"
#include "windows.h"
#include "cClientsList.h"
#include "cClient.h"

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
	
	//delete!!!!! - WE CANNOT DELETE THIS because this parameter is being filled by accept function

	
	eMessageType ProcessMessageType(char x);
	bool ProcessRegisterRequest(SOCKET ClientSocket, char* sMessage);
	bool ProcessLoginRequest(SOCKET ClientSocket, char* sMessage);
	bool ProcessLogoutRequest(SOCKET ClientSocket, char* sMessage);
	bool IsUserRegistered(string sUsername);
	bool ProcessIMRequest(SOCKET ClientSocket,char* sMessage);
	SOCKET FindSocketByUsername(string sUsername);
	cClientsList* ClientsList;

public:

	static cMessageManager* Instance();
	SOCKET cMessageManager::GetClient(SOCKET Server);
	bool ProcessDialog(SOCKET Client);
	int StartServer();
};