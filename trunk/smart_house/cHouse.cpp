#include "cHouse.h"
#include "iostream"
using namespace std;

cHouse::cHouse()
{
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
	for (int i=0; i < m_pFloors.size(); i++)
	{
		cout << "{" << endl;
		m_pFloors[i].Print();
		cout << "}" << endl;
	}
}