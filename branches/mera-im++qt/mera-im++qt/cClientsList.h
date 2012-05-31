#pragma once
#include "clist.h"
#include "qstring.h"
#include <QtNetwork/QtNetwork>
class cClientsList :
	public cList<cClient>
{
public:
	cClientsList(void);
	~cClientsList(void);

	cClient* FindByUsername(QString sUsername);
	cClient* FindBySocketID(QTcpSocket* SocketID);
};

