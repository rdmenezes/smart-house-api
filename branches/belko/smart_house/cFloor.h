#pragma once
#include "cRoom.h"
#include <vector>
using namespace std;

class cFloor
{
public:
	cFloor();
	~cFloor();

	vector<cRoom> m_pRooms;

	void AddRoom(cRoom &room);
	void AddRoom();
	void Print();
};

