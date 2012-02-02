#include "iostream"
#include "cstring"
#include "cHouse.h"
#include "cWindow.h"
#include "cRoom.h"
#include "cFloor.h"

using namespace std;

vector<cHouse> rHouses;
bool bNameIsNotAvailable = false;

int main ()
{
//	rHouses.reserve(sizeof(cHouse)*6);

	/* cHouse house;
	house.AddFloor();
	house.AddFloor();
	house.m_pFloors[0].AddRoom();
	house.m_pFloors[0].AddRoom();
	house.m_pFloors[1].AddRoom();
	house.m_pFloors[1].AddRoom();
	house.m_pFloors[0].m_pRooms[0].AddWindow();
	house.m_pFloors[0].m_pRooms[1].AddWindow();
	house.m_pFloors[1].m_pRooms[0].AddWindow();
	house.m_pFloors[0].m_pRooms[1].m_pWindows[0].Open();
	house.Print(); */
	
	char  string[20];
	
	cout << "\nWelcome to your Smart House Manager\n";
	cout << ">";
	while ( ((cin.getline (string, 20)) && ((strcmp (string, "exit")) != 0) ))
	{
		if (((strcmp (string, "add house")) == 0))
		{			
			char* Name = new char [10];
			cout << "\nEnter your house name\n" << ">";
			cin.getline (Name, 10);

			while ((strcmp (Name, "") == 0))
				{
					cout << "\nEnter your house name\n" << ">";
					cin.getline (Name, 10);
				}

			if (rHouses.size() != 0)
			{
				bNameIsNotAvailable = false;
				for (size_t i = 0; i < rHouses.size(); ++i)
				{
					if (strcmp (rHouses[i].Name, Name) == 0)
					{
						cout << "\nThere's already a house with the same name\n";
						bNameIsNotAvailable = true;
					}

				}
			}

			if (!bNameIsNotAvailable)
			{
				cHouse house;
				house.Name = Name;
				rHouses.push_back(house);
				cout << "\nYou've created a House\n" << endl;
				rHouses[rHouses.size()-1].Print();
			}
		}

		cout << ">";

		if (((strcmp (string, "delete house")) == 0))
		{
			cout << "\nEnter the house name you want to delete\n>";
			char* Name = new char [10];
			cin.getline (Name, 10);
			if (rHouses.size() != 0)
			{
				for (size_t i = 0; i < rHouses.size(); ++i)
				{
					if (strcmp (rHouses[i].Name, Name))
					{
						rHouses.erase(rHouses.begin()+i);
					}

				}
			}


		}
	}

	system ("pause"); 
}