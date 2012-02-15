#pragma once
#include "cString.h"
#include "tinyxml.h"

class cWindow
{
public:
	cWindow();
	~cWindow();

	void Open();
	void Close();
	cString Serialize();
	bool m_bOpened;
};

