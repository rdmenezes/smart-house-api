#include "UISignalManager.h"

cUISignalManager* cUISignalManager::m_pSelf = 0;

void cUISignalManager::Initialize()
{
	m_pSelf = new cUISignalManager;
}

cUISignalManager* cUISignalManager::Instance()
{
	if(!m_pSelf)
	{
		m_pSelf = new cUISignalManager;
	}
	return m_pSelf;
}

cUISignalManager::cUISignalManager(void)
{
}

cUISignalManager::~cUISignalManager(void)
{
}

void cUISignalManager::Put(cEvent* event)
{
	DWORD thID;
	CreateThread(NULL,NULL,ProcessEvent,event,NULL,&thID);
}


DWORD WINAPI cUISignalManager::ProcessEvent(LPVOID ev)
{
	cServer* pServer = cServer::Instance();
	cEvent* event = (cEvent *)ev;
	switch (event->m_eDestination)
	{
	case Server:
		pServer->OnMessage(event);
	case UserInterface:
		emit m_pSelf->StartServerResponce(event->sDetails);
	}
	
	delete event;
	return 0;
}



///////////////////////////////////////////

void cUISignalManager::OnEventFromUI()
{
	emit StartServerResponce("All Okay");
}