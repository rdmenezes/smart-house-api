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

void cFloor::Print(cSocket* socket)
{	
	for(size_t i=0; i< m_pRooms.size();i++)
	{
		socket->PutString("      {\n");
		m_pRooms[i].Print(socket);
		socket->PutString("      }\n");
	}
}