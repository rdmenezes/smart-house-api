#include "cSocket.h"

cSocket::cSocket()
{
	//Configure Server Socket	
	SocketVersion = MAKEWORD(2,2);
	WSAStartup (SocketVersion,(WSADATA *) &buffer[0]);
	ServerSocket = socket (AF_INET, SOCK_STREAM, 0);
	LocalAddr.sin_family = AF_INET;
	LocalAddr.sin_port = htons(1234);
	LocalAddr.sin_addr.s_addr = 0;
	//initialize server socket
	BindResult = bind(ServerSocket,(sockaddr *) &LocalAddr, sizeof(LocalAddr));
	ListenResult = listen(ServerSocket, 100);
	//Configure Client Socket
	ClientSocketAddrSize = sizeof(ClientSocketAddr);
	//Initialize Client Socket and listening 
}
cSocket::~cSocket()
{
	closesocket(ClientSocket);
	closesocket(ServerSocket);
	WSACleanup();
}

int cSocket::Accept()
{
	ClientSocket = accept(ServerSocket, (sockaddr *) &ClientSocketAddr, &ClientSocketAddrSize);
	return ClientSocket;
}
