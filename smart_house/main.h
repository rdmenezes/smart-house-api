#include "iostream"
#include "cHouse.h"
#include "cWindow.h"
#include "cRoom.h"
#include "cFloor.h"
#include "cString.h"

using namespace std;

vector<cHouse> rHouses;

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
	Name.ReadLine("Enter your house name");

	while (Name == "")
	{
		Name.ReadLine("Enter your house name");
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
	cString Name;
	Name.ReadLine("Enter the house name you want to delete");
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

//--------------------------------------------------------------------------------

void AddRoom() 
{
	cString string;	
	string.ReadLine("Enter the house you want to add a room to");
	for (size_t i = 0; i < rHouses.size(); ++i)
	{
		if (rHouses[i].Name == string)
		{
			cout << "Enter the floor number you'd like to add a room to " << endl;
			string.ReadLine();
			unsigned int n = string.ToInt();
			if (rHouses[i].m_pFloors.size() <= n)
			{
				cout << "Invalid floor\n";
				return;
			}
			else
			{
				rHouses[i].m_pFloors[n].AddRoom();				
			}			
		}
	}
}

//--------------------------------------------------------------------------------

void AddFloor()
{
	cString string;
	string.ReadLine("Enter the house you want to add a floor to");
	for (size_t i = 0; i < rHouses.size(); ++i)
	{
		if (rHouses[i].Name == string)
		{
			rHouses[i].AddFloor();
		} 
	}
}

//--------------------------------------------------------------------------------

void PrintHelp()
{
	cout << "\"add house\" - add a house; " << endl <<
		"\"delete house\" - deletes a house; " << endl <<
		"\"print\" - prints all information about your house's configuration" << endl <<
		"\"exit\" - exit from the application " << endl;
}