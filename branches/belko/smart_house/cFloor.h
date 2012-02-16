#pragma once
#include "cRoom.h"
#include <vector>
#include "cString.h"
#include "tinyxml.h"

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
	cString Serialize();
	void Deserialize(cString data);
};

