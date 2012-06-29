#pragma once
#include "List.h"
#include "qstring.h"
#include <QtNetwork>
class cClientsList :
	public cList<cClient>
{
public:
	cClientsList(void);
	~cClientsList(void);

	cClient* FindByUsername(QString sUsername);
	//cClient* FindBySocketID(QTcpSocket* SocketID);
};

