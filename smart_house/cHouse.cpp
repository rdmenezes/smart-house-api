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

void cHouse::Print(cSocket* socket)
{
	socket->PutString(Name.str);
	socket->PutString("\n");
	for (size_t i=0; i < m_pFloors.size(); i++)
	{
		socket->PutStringFormated(" %d\n  {\n", i);
		m_pFloors[i].Print(socket);
		socket->PutString("  }\n");
	}
}

