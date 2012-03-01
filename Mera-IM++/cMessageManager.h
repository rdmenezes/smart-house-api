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

	SOCKET Server;	//delete
	int StartServer();

	sockaddr_in m_ClientAddr;//delete!!!!!

	int m_nClientSocketAddrSize;//delete!!!!

	eMessageType ProcessMessageType(char x);
	bool ProcessRegisterRequest(SOCKET ClientSocket, char* sMessage);
	bool ProcessLoginRequest(SOCKET ClientSocket, char* sMessage);
	bool ProcessLogoutRequest(SOCKET ClientSocket, char* sMessage);
	bool IsUserRegistered(string sUsername);
	bool ProcessIMRequest(SOCKET ClientSocket,char* sMessage);
	SOCKET FindSocketByUsername(string sUsername);

	cClientsList* ClientsList;

public:

	static void Initialize();
	static cMessageManager& Instance();
	SOCKET GetClient();
	bool ProcessDialog(SOCKET Client);

};