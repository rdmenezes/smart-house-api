#include "iostream"
#include "cstring"
#include "cHouse.h"
#include "cWindow.h"
#include "cRoom.h"
#include "cFloor.h"

using namespace std;

vector<cHouse> rHouses;

bool IsNameAvailable(char* Name);
void DelHouse();
void AddHouse();
void Print();

int main ()
{
	char  string[20];
	
	cout << "\nWelcome to your Smart House Manager\n";
	cout << ">";
	while ( ((cin.getline (string, 20)) && ((strcmp (string, "exit")) != 0) ))
	{
		if (((strcmp (string, "add house")) == 0))
		{			
			AddHouse();
		}

		if (((strcmp (string, "delete house")) == 0))
		{
			DelHouse();
		}

		if (((strcmp (string, "print")) == 0))
		{
			Print();
		}

		cout << ">";
	}

	system ("pause"); 
}

bool IsNameAvailable(char* Name)
{
	if (rHouses.size() != 0)
	{
		for (size_t i = 0; i < rHouses.size(); ++i)
		{
			if (strcmp (rHouses[i].Name, Name) == 0)
			{
				cout << "\nThere's already a house with the same name\n";
				return false;
			}

		}
	}
	return true;
}

void DelHouse()
{
	cout << "\nEnter the house name you want to delete\n>";
	char* Name = new char [10];
	cin.getline (Name, 10);
	if (rHouses.size() != 0)
	{
		for (size_t i = 0; i <= rHouses.size(); ++i)
		{
			if (strcmp (rHouses[i].Name, Name) == 0)
			{
				rHouses.erase(rHouses.begin());
				cout << "\nHouse " << Name << " is deleted\n";
				return;
			}
		}

		cout << "\nCan't delete house \"" << Name << "\". Reason: Not found\n"; 
	}
	else
	{
		cout << "\nYou don't have any houses yet. Please create a house\n";
	}
}

void AddHouse()
{
	char* Name = new char [10];
	cout << "\nEnter your house name\n" << ">";
	cin.getline (Name, 10);

	while ((strcmp (Name, "") == 0))
	{
		cout << "\nEnter your house name\n" << ">";
		cin.getline (Name, 10);
	}

	if (IsNameAvailable(Name))
	{
		cHouse house;
		house.Name = Name;
		rHouses.push_back(house);
		cout << "\nYou've created a House \"" << Name << "\"" << endl;
	}
}

void Print()
{
	cout << "\nYou Smart-House objects:" << endl;
	if (rHouses.size() != 0)
	{
		for (size_t i=0; i < rHouses.size(); ++i)
		{
			rHouses[i].Print();
		}
	}
}