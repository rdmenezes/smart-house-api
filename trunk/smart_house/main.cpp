#include "main.h"
DWORD WINAPI HandleClients(LPVOID Client);
int main ()
{
	//cout << "\nWelcome to your Smart House Manager\n";
	cSocket socket;
	int Client;
	while((Client = socket.Accept()) != -1)
	{
		DWORD thID;
		CreateThread(NULL,NULL,HandleClients,&Client,NULL,&thID);
	}
}

DWORD WINAPI HandleClients(LPVOID cl)
{
	SOCKET Client;
	Client = ((SOCKET *) cl)[0];
	cString string;	
	string.PutString(Client,"Welcome to your Smart-House Manager!\n>");
	while (string.ReadLine("", Client) && string != "exit")
	{		
		if (string == "add house")
		{			
			AddHouse(Client);
		}

		else if (string == "delete house")
		{
			DelHouse(Client);
		}

		else if (string == "print")
		{
			Print(Client);
		}
		else if (string == "add floor")
		{
			AddFloor(Client);
		}
		else if (string == "add room")
		{
			AddRoom(Client);
		}

		else if (string == "help")
		{
			PrintHelp(Client);
		}
		else if (string == "add window")
		{
			AddWindow(Client);
		}

		else
		{
			string.PutString(Client,"You've entered unknown command \n>");
			break;
		}
		string.PutString(Client, "");
	}

	return 0;
}