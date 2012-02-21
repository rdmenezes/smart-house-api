#include "main.h"

int main ()
{
	cString string;	
	cout << "\nWelcome to your Smart House Manager\n";

	while (string.ReadLine())//((string = GetStringFromSocket()) != "exit") //AS we don't have a Socket Client yet, use TCP/IP Bulder. Port 1234
	{
		if (string == "add house")
		{			
			AddHouse();
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
			AddFloor();
		}
		else if (string == "add room")
		{
			AddRoom();
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