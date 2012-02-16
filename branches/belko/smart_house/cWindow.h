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
	void Deserialize(cString data);
	bool m_bOpened;
};

