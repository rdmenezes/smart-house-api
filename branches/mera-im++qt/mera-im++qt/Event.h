#pragma once
#include <iostream>
#include "Definitions.h"
#include <qobject.h>
using namespace std;
class cEvent
{
public:
	cEvent(void);
	~cEvent(void);
	Action m_eAction;
	Destination m_eDestination;
	int m_nPort;
	QString sDetails;
};

