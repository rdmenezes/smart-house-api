#pragma once

#include "iostream"
#include "winsock2.h"
#include "windows.h"
#include "cClientsList.h"
#include "cClient.h"

using namespace std;

enum eMessageType {RegisterRequest, LoginRequest, LogoutRequest, IM, StatusChanged};
class cMessageManager 
{
private:

	cMessageManager();
	~cMessageManager();
	static cMessageManager* self; 

	SOCKET Server;	
	int StartServer();
	char buf[512];

	WORD SocketVersion;
	sockaddr_in ServerAddr;
	sockaddr_in ClientAddr;
	int BindResult;
	int ListenResult;
	int result;
	int ClientSocketAddrSize;

	eMessageType ProcessMessageType(char x);
	bool ProcessRegisterRequest(SOCKET Client, char* buffer);
	bool IsUserRegistered(std::string Username);
	bool ProcessIMRequest(SOCKET Client,char* buffer);
	SOCKET FindSocketByUsername(std::string Username);

	cClientsList ClientsList;

public:

	static void Initialize();
	static cMessageManager& Instance();
	SOCKET GetClient();
	bool ProcessDialog(SOCKET Client);

};