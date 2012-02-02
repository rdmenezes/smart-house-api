#pragma once
#include "vector"
#include "cFloor.h"
using namespace std;

class cHouse
{
public:
	cHouse();
	~cHouse();

	vector <cFloor> m_pFloors;
	
	void AddFloor(cFloor &floor);
	void AddFloor();
	void Print();
};

