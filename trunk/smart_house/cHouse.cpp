#include "cHouse.h"
#include "iostream"
using namespace std;

cHouse::cHouse()
{
	Name = "Default";
}

cHouse::cHouse(const cHouse &copy)
{
	Name = new char [10];
	for (size_t i=0; i <= strlen(copy.Name); i++)
	{
		Name[i] = copy.Name[i];
	}
	m_pFloors = copy.m_pFloors;
}

cHouse &cHouse::operator = ( const cHouse &copy )
{
	Name = new char [10];
	for (size_t i=0; i <= strlen(copy.Name); i++)
	{
		Name[ i ] = copy.Name[ i ];
	}
	m_pFloors = copy.m_pFloors;
	return *this;
}


cHouse::~cHouse()
{
	delete [] Name;
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
	cout << Name << "\n";
	for (size_t i=0; i < m_pFloors.size(); i++)
	{
		cout << "{" << endl;
		m_pFloors[i].Print();
		cout << "}" << endl;
	}
}