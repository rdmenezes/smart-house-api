#include "cFloor.h"
#include "iostream"
using namespace std;

cFloor::cFloor()
{
}


cFloor::~cFloor()
{
}

void cFloor::AddRoom(cRoom &room)
{
	m_pRooms.push_back(room);
}

void cFloor::AddRoom()
{
	cRoom room = cRoom();
	m_pRooms.push_back(room);
}

void cFloor::Print()
{
	
	for(int i=0; i< m_pRooms.size();i++)
	{
		cout<<"\t{"<<endl;
		m_pRooms[i].Print();
		cout<<"\t}"<<endl;
	}
}