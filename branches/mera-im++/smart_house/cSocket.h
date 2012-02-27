#pragma once
#include "iostream"
#include "winsock2.h"
#include "string"

class cSocket
{
public:
	cSocket();
	~cSocket();

	char buffer[1024];
	char buff[1024];
	WORD SocketVersion;
	sockaddr_in LocalAddr;
	int ServerSocket;
	int BindResult;
	int ListenResult;
	SOCKET ClientSocket;
	sockaddr_in ClientSocketAddr;
	int ClientSocketAddrSize;
	int Bites_receaved;
	char str[1024];

	std::string GetString();
	void PutString(const char* string);
	void PutString(std::string string);
	void PutStringFormated(const char * format, ...);
	int cSocket::Accept();
};