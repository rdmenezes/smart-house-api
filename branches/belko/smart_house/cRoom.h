#pragma once
#include <vector>
#include "cWindow.h"
#include "cString.h"
#include "tinyxml.h"
using namespace std;

class cRoom
{
public:
	cRoom();
	~cRoom();

	vector<cWindow> m_pWindows;

	void AddWindow(cWindow &window);
	void AddWindow();
	void Print();
	cString Serialize();
};
