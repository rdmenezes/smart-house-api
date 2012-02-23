#include "cFloor.h"
#include "iostream"
#include "cString.h"
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

void cFloor::Print(int socket)
{	
	for(size_t i=0; i< m_pRooms.size();i++)
	{
		cString s;
		s.PutString(socket, "      {\n");
		m_pRooms[i].Print(socket);
		s.PutString(socket, "      }\n");
	}
}