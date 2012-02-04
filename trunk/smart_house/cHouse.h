#pragma once
#include "vector"
#include "cFloor.h"
#include "string"
using namespace std;

class cHouse
{
public:
	cHouse();
	cHouse(const cHouse &copy);
	cHouse &cHouse::operator = ( const cHouse &copy );
	~cHouse();
	vector <cFloor> m_pFloors;
	char* Name;

	void AddFloor(cFloor &floor);
	void AddFloor();
	void Print();
};

