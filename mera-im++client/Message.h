#pragma once

#include "Definitions.h"
#include "QtNetwork"

class cBaseMessage {
public:

	cBaseMessage();
	~cBaseMessage();

	virtual cBaseMessage* Deserialize(QDataStream in){return 0;};

	int m_nID;
};

/////////////////////////////////////////////////////////////////////////////////////////
//																					   //
//				Class cRegisterRequest is used for registration a user on the server   //
//																					   //
/////////////////////////////////////////////////////////////////////////////////////////


class cRegisterRequest : public cBaseMessage {
public:

	cRegisterRequest();
	~cRegisterRequest();

	virtual cBaseMessage* Deserialize(QDataStream in);
	QString m_sUsername;
	QString m_sPassword;
};