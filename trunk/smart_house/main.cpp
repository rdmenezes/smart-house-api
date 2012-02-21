#include "main.h"

int main ()
{
	cString string;	
	//cout << "\nWelcome to your Smart House Manager\n";
	cSocket socket;
	socket.Accept();
	socket.PutString("Welcome to your Smart House Manager\n");
	while (string.ReadLine(0, &socket) && string != "exit")
	{		
		if (string == "")
		{
			socket.Accept();
			continue;
		}
		if (string == "add house")
		{			
			AddHouse(&socket);
		}

		else if (string == "delete house")
		{
			DelHouse(&socket);
		}

		else if (string == "print")
		{
			Print(&socket);
		}
		else if (string == "add floor")
		{
			AddFloor(&socket);
		}
		else if (string == "add room")
		{
			AddRoom(&socket);
		}

		else if (string == "help")
		{
			PrintHelp(&socket);
		}
		else if (string == "add window")
		{
			AddWindow(&socket);
		}

		else
		{
			cout << "You've entered unknown command " << endl;
		}
	}

	#ifdef _WIN32
	system ("pause"); 
	#endif
}