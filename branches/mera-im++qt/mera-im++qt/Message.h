#pragma once

#include "Definitions.h"
#include <QObject>

class cBaseMessage {
public:

	cBaseMessage();
	~cBaseMessage();

	NetworkMessageType m_nID;
};

class cRegisterRequest : public cBaseMessage {
public:

	cRegisterRequest();
	~cRegisterRequest();

	QString m_sUsername;
	QString m_sPassword;
};