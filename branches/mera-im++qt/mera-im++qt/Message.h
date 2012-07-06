#pragma once

#include "Definitions.h"
#include "QtNetwork"

class cBaseMessage {
public:

	cBaseMessage();
	~cBaseMessage();

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

	QString m_sUsername;
	QString m_sPassword;
};