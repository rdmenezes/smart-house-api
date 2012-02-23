#include "cHouse.h"
#include "iostream"
using namespace std;

cHouse::cHouse()
{
	Name = "Default";
}

cHouse::cHouse(const cHouse &copy)
{
	Name = copy.Name;
	m_pFloors = copy.m_pFloors;
}

cHouse &cHouse::operator = ( const cHouse &copy )
{
	Name = copy.Name;
	m_pFloors = copy.m_pFloors;
	return *this;
}


cHouse::~cHouse()
{
}

void cHouse::AddFloor(cFloor &floor)
{
	m_pFloors.push_back(floor);
}
void cHouse::AddFloor()
{
	m_pFloors.push_back(cFloor());
}

void cHouse::Print(int socket)
{
	cString s;
	s.PutString(socket, Name.str);
	s.PutString(socket, "\n");
	for (size_t i=0; i < m_pFloors.size(); i++)
	{
		s.PutStringFormated(socket, " %d\n  {\n", i);
		m_pFloors[i].Print(socket);
		s.PutString(socket, "  }\n");
	}
}

