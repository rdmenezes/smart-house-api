#include "iostream"
#include "cMessageManager.h"
using namespace std;

DWORD WINAPI Run(LPVOID CL);

int main ()
{
	cMessageManager::Initialize();
	SOCKET Client;
	DWORD thID;
	
	while((Client = cMessageManager::Instance().GetClient()) != -1)
	{		
		CreateThread(NULL,NULL,Run,&Client,NULL,&thID);
	}
	return 0;
}

DWORD WINAPI Run(LPVOID CL)
{
	SOCKET Client;
	Client = *(SOCKET *)CL;


	char * a = "Hello, Client! your ID is ";
	char * b = new char[sizeof(Client)+1];
	_itoa(Client,b,10);
 	send (Client,a, strlen(a),0);
	send (Client,b, sizeof(b),0);
	send (Client,"\n",2,0);

	unsigned int MCount = 0;

	while (cMessageManager::Instance().ProcessDialog(Client))
	{
		MCount++;
	}
	closesocket(Client);
	return 0;
}