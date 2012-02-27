#pragma once

#include "iostream"
#include "winsock2.h"
#include "windows.h"

using namespace std;

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
	enum MessageType {LoginRequest, LogoutRequest, IM, StatusChanged};

	cMessageManager::MessageType ProcessMessageType();
	char * buffer;

public:

	static void Initialize();
	static cMessageManager& Instance();
	SOCKET GetClient();
	void ProcessDialog(SOCKET Client);

};