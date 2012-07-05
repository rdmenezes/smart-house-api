#pragma once

#include "Definitions.h"
#include <QObject>

class cBaseMessage {
public:

	cBaseMessage();
	~cBaseMessage();

	int m_nID;

	cBaseMessage* Deserialize(QDataStream* in);
};

class cRegisterRequest : public cBaseMessage {
public:

	cRegisterRequest();
	~cRegisterRequest();

	QString m_sUsername;
	QString m_sPassword;
};