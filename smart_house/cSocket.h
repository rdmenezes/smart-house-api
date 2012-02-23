#pragma once
#include "iostream"
#include "winsock2.h"
#include "string"

class cSocket
{
public:
	cSocket();
	~cSocket();

	char buffer[13];					//socket init date (used for SOcket version)
	WORD SocketVersion;
	sockaddr_in LocalAddr;
	int ServerSocket;
	int BindResult;
	int ListenResult;
	int ClientSocket;
	sockaddr_in ClientSocketAddr;
	int ClientSocketAddrSize;

	char str[1024];


	int cSocket::Accept();
};