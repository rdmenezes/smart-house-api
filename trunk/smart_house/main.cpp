#include "iostream"
#include "cstring"
#include "cHouse.h"
#include "cWindow.h"
#include "cRoom.h"
#include "cFloor.h"

using namespace std;


int main ()
{

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

	while ( ((cin.getline (string, 20)) && ((strcmp (string, "exit")) != 0) ))
	{
		if (((strcmp (string, "create")) == 0))
		{
			cHouse house;
			cout << "\nYou've created a House\n" << endl;
			house.Print();
		}
	}

	system ("pause"); 
}