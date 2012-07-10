#pragma once

#include "Definitions.h"
#include "QtNetwork"

/////////////////////////////////////////////////////////////////////////////////////////
//																					   //
//				Class cRegisterRequest is used for registration users on the server   //
//																					   //
/////////////////////////////////////////////////////////////////////////////////////////


class cRegisterRequest {
public:

	cRegisterRequest();
	~cRegisterRequest();

	QString m_sUsername;
	QString m_sPassword;
};