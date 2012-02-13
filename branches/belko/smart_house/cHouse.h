#pragma once
#include "vector"
#include "cFloor.h"
#include "cString.h"
using namespace std;

class cHouse
{
public:
	cHouse();
	cHouse(const cHouse &copy);
	cHouse &operator = ( const cHouse &copy );
	~cHouse();
	vector <cFloor> m_pFloors;
	cString Name;

	void AddFloor(cFloor &floor);
	void AddFloor();
	void Print();
};

