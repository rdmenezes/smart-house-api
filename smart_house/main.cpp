#include "main.h"

int main ()
{
	cString string;	
	cout << "\nWelcome to your Smart House Manager\n";
	cout << ">";

	while ((string.GetString()) && (string != "exit"))
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

		cout << ">";
	}
	#ifdef _WIN32
	system ("pause"); 
	#endif
}

