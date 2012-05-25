#pragma once
#include <winsock2.h>
#include <windows.h>
#include "cUtils.h"
#include "cMessageManager.h"
#include <QtGui/QWidget>
#include "UISignalManager.h"

class cServer
{
public:
	cServer(void);
	~cServer(void);

	void StartServer(int port);
	SOCKET GetClient(SOCKET Server);
	static cServer* Instance();
	void OnMessage(cEvent* event);

	static cServer* m_pSelf;
};