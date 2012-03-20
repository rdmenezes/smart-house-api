#include "cClientsList.h"


cClientsList::cClientsList(void)
{
}


cClientsList::~cClientsList(void)
{
}

////////////////////////////////////////////////////////////////////////////////

cClient* cClientsList::FindByUsername(string sUsername)
{
	for (ListItem* pItem = m_pHead; pItem != NULL; pItem = pItem->m_pNext)
	{
		if (pItem->m_pData->GetUsername() == sUsername)
		{
			return pItem->m_pData;
		}
	}

	return NULL;
}

////////////////////////////////////////////////////////////////////////////////

cClient* cClientsList::FindBySocketID(SOCKET SocketID)
{
	for (ListItem* pItem = m_pHead; pItem != NULL; pItem = pItem->m_pNext)
	{
		if (pItem->m_pData->GetSocketID() == SocketID)
		{
			return pItem->m_pData;
		}
	}

	return NULL;
}
