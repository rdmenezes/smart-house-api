#include "iostream"
#include "string"
#include "cHouse.h"
#include "cWindow.h"
#include "cRoom.h"
#include "cFloor.h"

using namespace std;


int main ()
{

	cHouse house;
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

	
	house.Print();

	system ("pause"); 
}