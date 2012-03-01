#include "iostream"
#include "cMessageManager.h"
using namespace std;

DWORD WINAPI Run(LPVOID CL);

int main ()
{
	cMessageManager::Initialize();
	SOCKET ClientSocket;
	DWORD thID;
	
	while((ClientSocket = cMessageManager::Instance().GetClient()) != -1)
	{		
		CreateThread(NULL,NULL,Run,&ClientSocket,NULL,&thID);
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

DWORD WINAPI Run(LPVOID CL)
{
	SOCKET ClientSocket;
	ClientSocket = *(SOCKET *)CL;


	char * a = "Hello, Client! your ID is ";
	char * b = new char[sizeof(ClientSocket)+1];
	_itoa(ClientSocket,b,10);
 	send (ClientSocket,a, strlen(a),0);
	send (ClientSocket,b, sizeof(b),0);
	send (ClientSocket,"\n",2,0);

	unsigned int MCount = 0;

	while (cMessageManager::Instance().ProcessDialog(ClientSocket))
	{
		MCount++;
	}
	closesocket(ClientSocket);
	return 0;
}