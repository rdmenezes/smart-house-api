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
		else if (string == "add floor")
		{
			cout << "Enter the house you want to add a floor to" << endl;
			string.GetString();
			for (size_t i = 0; i < rHouses.size(); ++i)
			{
				if (rHouses[i].Name == string)
				{
					rHouses[i].AddFloor();
				} 
			}
		}
		else if (string == "add room")
		{
			cout << "Enter the house you want to add a room to" << endl;
			string.GetString();
			for (size_t i = 0; i < rHouses.size(); ++i)
			{
				if (rHouses[i].Name == string)
				{
					cout << "Enter the floor number you'd like to add a room to " << endl;
					//THIS MAGIC ONLY WORKS BECAUSE GetSting is BOOLEAN, So gives back "1" if true, and "0" if false!!! 
					//REPLACE!! THIS CODE doesn't work properly!! What an idiot declarates int = bool ? FUCK YOURSELF! (PUNISHER) 
					int n = string.GetString()-1;
					rHouses[i].m_pFloors[n].AddRoom();
				}
			}
		}

		else if (string == "help")
		{
			cout << "\"add house\" - add a house; " << endl <<
				"\"delete house\" - deletes a house; " << endl <<
				"\"print\" - prints all information about your house's configuration" << endl <<
				"\"exit\" - exit from the application " << endl;
		}

		else
		{
			cout << "You've entered unknown command " << endl;
		}

		cout << ">";
	}
	#ifdef _WIN32
	system ("pause"); 
	#endif
}