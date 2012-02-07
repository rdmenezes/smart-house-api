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

void cHouse::Print()
{
	cout << Name.str << "\n";
	for (size_t i=0; i < m_pFloors.size(); i++)
	{
		cout << "{" << endl;
		m_pFloors[i].Print();
		cout << "}" << endl;
	}
}