#include "cMessageManager.h"
cMessageManager* cMessageManager::self = 0;

cMessageManager& cMessageManager::Instance()
{
	if(!self)
	{
		self = new cMessageManager;
	}
	return *self;
}

void cMessageManager::Initialize()
{
	delete self;
	self = new cMessageManager;
}


cMessageManager::cMessageManager ()
{
	StartServer();
}

cMessageManager::~cMessageManager()
{
	delete self;
}

int cMessageManager::StartServer()
{
	SocketVersion = MAKEWORD (2,2);
	result = WSAStartup (SocketVersion,(WSADATA *) &buf[0]);
	Server = socket (AF_INET, SOCK_STREAM, 0);

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(1234);
	ServerAddr.sin_addr.s_addr = 0;

	if ((BindResult = bind(Server,(sockaddr *) &ServerAddr, sizeof(ServerAddr))) < 0)
	{
		cout << "Socket Bind Error" << endl;
		return -1;
	}
	if ((ListenResult = listen(Server, 100)) < 0)
	{
		cout << "Socket Listen Error" << endl;
		return -1;
	}

	ClientSocketAddrSize = sizeof(ClientAddr);

	return 1;
}

SOCKET cMessageManager::GetClient()
{
	return accept(Server, (sockaddr *) &ClientAddr, &ClientSocketAddrSize);
}

void cMessageManager::ProcessDialog(SOCKET Client)
{
	char DialogLength[3];
	recv(Client,&DialogLength[0],sizeof(DialogLength),0);
	int n = atoi(DialogLength);
	buffer = new char [n+1];
	recv(Client,&buffer[0],n,0);
	buffer[n] = 0;
	
	MessageType Type;
	Type = ProcessMessageType();

	switch (Type)
	{
		case LoginRequest: { send(Client,"Login Request\n",strlen("Login Request\n"),0);break;}
		case LogoutRequest: {send(Client,"Logout Request\n",strlen("Logout Request\n"),0);break;}
		case IM: {send(Client,"IM\n",strlen("IM\n"),0);break;}
		case StatusChanged: {send(Client,"Status Changed\n",strlen("Status Changed\n"),0);break;}
	}
}

cMessageManager::MessageType cMessageManager::ProcessMessageType()
{
	switch (buffer[0])
	{
		case '0': {return LoginRequest;}
		case '1': {return LogoutRequest;}
		case '2': {return IM;}
		case '3': {return StatusChanged;}
	}
}