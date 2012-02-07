#include "iostream"
#include "cHouse.h"
#include "cWindow.h"
#include "cRoom.h"
#include "cFloor.h"
#include "cString.h"

using namespace std;

vector<cHouse> rHouses;

bool IsNameAvailable(cString Name);
void DelHouse();
void AddHouse();
void Print();


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

		if (string == "delete house")
		{
			DelHouse();
		}

		if (string == "print")
		{
			Print();
		}

		cout << ">";
	}

	system ("pause"); 
}

//--------------------------------------------------------------------------------

bool IsNameAvailable(cString Name)
{
	if (rHouses.size() != 0)
	{
		for (size_t i = 0; i < rHouses.size(); ++i)
		{
			if (rHouses[i].Name == Name)
			{
				cout << "\nThere's already a house with the same name\n";
				return false;
			}

		}
	}
	return true;
}

//--------------------------------------------------------------------------------

void AddHouse()
{
	cString Name;
	cout << "\nEnter your house name\n" << ">";
	Name.GetString();

	while (Name == "")
	{
		cout << "\nEnter your house name\n" << ">";
		Name.GetString();
	}

	if (IsNameAvailable(Name))
	{
		cHouse house;
		house.Name = Name;
		rHouses.push_back(house);
		cout << "\nYou've created a House \"" << Name.str << "\"" << endl;
	}
}

//--------------------------------------------------------------------------------

void DelHouse()
{
	cout << "\nEnter the house name you want to delete\n>";
	cString Name;
	Name.GetString();
	if (rHouses.size() != 0)
	{
		for (size_t i = 0; i <= rHouses.size(); ++i)
		{
			if (rHouses[i].Name == Name)
			{
				rHouses.erase(rHouses.begin()+i);
				cout << "\nHouse " << Name.str << " is deleted\n";
				return;
			}
		}

		cout << "\nCan't delete house \"" << Name.str << "\". Reason: Not found\n"; 
	}
	else
	{
		cout << "\nYou don't have any houses yet. Please create a house\n";
	}
}

//--------------------------------------------------------------------------------

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