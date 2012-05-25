#pragma once
#include "clist.h"
class cClientsList :
	public cList<cClient>
{
public:
	cClientsList(void);
	~cClientsList(void);

	cClient* FindByUsername(string sUsername);
	cClient* FindBySocketID(SOCKET SocketID);
};

