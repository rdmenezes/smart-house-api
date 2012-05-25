#include "cServer.h"

cServer* cServer::m_pSelf = 0;

cServer::cServer(void)
{
}

cServer::~cServer(void)
{
}

cServer* cServer::Instance ()
{
	if (!m_pSelf)
	{
		m_pSelf = new cServer;
	}
	return m_pSelf;
}

DWORD WINAPI Run(LPVOID CL)
{
	cUtils* Utils = new cUtils;
	SOCKET ClientSocket;
	ClientSocket = *(SOCKET *)CL;
	int nSocketLength = Utils->IntLenInChar((int)ClientSocket);
	char * a = "Hello, Client! your ID is ";
	char * b = new char[nSocketLength+1];
	_itoa_s(ClientSocket,b,nSocketLength+1,10);
	send (ClientSocket,a, strlen(a),0);
	send (ClientSocket,b, sizeof(b),0);
	send (ClientSocket,"\n",2,0);

	int MCount = 0;

	while (cMessageManager::Instance()->ProcessDialog(ClientSocket))
	{
		MCount++;
	}
	closesocket(ClientSocket);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

int cServer::StartServer()
{
	SOCKET Server;
	int nResult, nBindResult, nListenResult;
	char buf[512];
	sockaddr_in ServerAddr;
	WORD SocketVersion;

	SocketVersion = MAKEWORD (2,2);
	nResult = WSAStartup (SocketVersion,(WSADATA *) &buf[0]);
	Server = socket (AF_INET, SOCK_STREAM, 0);

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(1234);
	ServerAddr.sin_addr.s_addr = 0;

	if ((nBindResult = bind(Server,(sockaddr *) &ServerAddr, sizeof(ServerAddr))) < 0)
	{
		cout << "Socket Bind Error" << endl;
		return -1;
	}
	if ((nListenResult = listen(Server, 100)) < 0)
	{
		cout << "Socket Listen Error" << endl;
		return -1;
	}

	SOCKET* ClientSocket = new SOCKET;
	DWORD thID;

	while((*ClientSocket = GetClient(Server)) != -1)
	{		
		CreateThread(NULL,NULL,Run,ClientSocket,NULL,&thID);
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

SOCKET cServer::GetClient(SOCKET Server)
{
	sockaddr_in m_ClientAddr;
	int m_nClientSocketAddrSize = sizeof(m_ClientAddr);
	return accept(Server, (sockaddr *) &m_ClientAddr, &m_nClientSocketAddrSize);
}