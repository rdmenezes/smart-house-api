#include "ClientsList.h"


cClientsList::cClientsList(void)
{
}


cClientsList::~cClientsList(void)
{
}

////////////////////////////////////////////////////////////////////////////////

cClient* cClientsList::FindByUsername(QString sUsername)
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

/*cClient* cClientsList::FindBySocketID(QTcpSocket* SocketID)
{
	for (ListItem* pItem = m_pHead; pItem != NULL; pItem = pItem->m_pNext)
	{
		if (pItem->m_pData->GetSocketID() == SocketID->socketDescriptor())
		{
			return pItem->m_pData;
		}
	}

	return NULL;
}*/
