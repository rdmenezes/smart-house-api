#pragma once
#include <vector>
#include "cWindow.h"
#include "cSocket.h"
#include "iostream"
#include "cString.h"
using namespace std;

class cRoom
{
public:
	cRoom();
	~cRoom();

	vector<cWindow> m_pWindows;

	void AddWindow(cWindow &window);
	void AddWindow();
	void Print(int socket);
};
