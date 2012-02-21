#include "main.h"

int main ()
{
	cString string;	
	cout << "\nWelcome to your Smart House Manager\n";
	cSocket socket;
	socket.Accept();
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
			DelHouse();
		}

		else if (string == "print")
		{
			Print();
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
			PrintHelp();
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