#include "iostream"
#include "cHouse.h"
#include "cWindow.h"
#include "cRoom.h"
#include "cFloor.h"
#include "cString.h"
#include "cSocket.h"


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

void AddHouse(cSocket* Socket)
{
	cString Name;
	Name.ReadLine("Enter your house name", Socket);

	while (Name == "")
	{
		Name.ReadLine("Enter your house name", Socket);
	}

	if (IsNameAvailable(Name))
	{
		cHouse house;
		house.Name = Name;
		rHouses.push_back(house);
		Socket->PutString("You've created a house ");
		Socket->PutString(Name.str);
		Socket->PutString("\n");
	}
}

//--------------------------------------------------------------------------------

void DelHouse(cSocket* socket)
{
	cString Name;
	Name.ReadLine("Enter the house name you want to delete", socket);
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

void Print(cSocket* socket)
{
	socket->PutString("\nYou Smart-House objects:\n");
	if (rHouses.size() != 0)
	{
		for (size_t i=0; i < rHouses.size(); ++i)
		{
			rHouses[i].Print(socket);
		}
	}
}

//--------------------------------------------------------------------------------

void AddRoom(cSocket* socket) 
{
	cString string;	
	string.ReadLine("Enter the house you want to add a room to", socket);
	for (size_t i = 0; i < rHouses.size(); ++i)
	{
		if (rHouses[i].Name == string)
		{
			string.ReadLine("Enter the floor number you'd like to add a room to", socket);
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

void AddWindow(cSocket* socket) 
{
	cString string;	
	string.ReadLine("Enter the house you want to add a window to", socket);
	for (size_t i = 0; i < rHouses.size(); ++i)
	{
		if (rHouses[i].Name == string)
		{
			string.ReadLine("Enter the floor number you'd like to add a window to", socket);
			unsigned int n = string.ToInt();
			if (rHouses[i].m_pFloors.size() <= n)
			{
				cout << "Invalid floor\n";
				return;
			}
			else
			{
				string.ReadLine("Enter the room number you'd like to add a window to", socket);
				unsigned int k = string.ToInt();
				if (rHouses[i].m_pFloors[n].m_pRooms.size() <= k)
				{
					socket->PutString("Invalid room\n");
					return;
				}
				else
				{
					rHouses[i].m_pFloors[n].m_pRooms[k].AddWindow();
					socket->PutString("Window is added\n");
				}
			}			
		}
	}
}

//--------------------------------------------------------------------------------

void AddFloor(cSocket* socket)
{
	cString string;
	string.ReadLine("Enter the house you want to add a floor to", socket);
	for (size_t i = 0; i < rHouses.size(); ++i)
	{
		if (rHouses[i].Name == string)
		{
			rHouses[i].AddFloor();
		} 
	}
}

//--------------------------------------------------------------------------------

void PrintHelp(cSocket* socket)
{
	socket->PutString("\"add house\" - add a house;\n\"delete house\" - deletes a house;\n\"print\" - prints all information about your house's configuration\n\"exit\" - exit from the application\n");
}