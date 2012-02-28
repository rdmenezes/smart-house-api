#pragma once
#include "cClient.h"
class cClientsList
{
public:
	cClientsList();
	~cClientsList();

private:

	cClient* Head;

public:
	
	void Insert(cClient* Client);
	cClient* Begin();
};