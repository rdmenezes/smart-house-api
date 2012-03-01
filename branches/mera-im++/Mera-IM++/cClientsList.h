#pragma once
#include "cClient.h"
using namespace std;

class cClientsList
{
public:
	cClientsList();
	~cClientsList();

private:

	cClient* m_pHead;

public:
	
	void Insert(cClient* Client);
	cClient* Begin();
	cClient* FindByUserName(string sUserName);
};