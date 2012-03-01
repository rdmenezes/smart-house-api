#include "cClientsList.h"
using namespace std;

cClientsList::cClientsList()
{
	m_pHead = NULL;
}

////////////////////////////////////////////////////////////////////////////////

cClientsList::~cClientsList()
{
}

////////////////////////////////////////////////////////////////////////////////

void cClientsList::Insert(cClient* pClient)
{
	pClient->m_pNextClient = 0;
	
	if (!m_pHead)
	{
		m_pHead = new cClient;
		*m_pHead = *pClient;
	}
	else
	{
		cClient* temp = m_pHead;
		while (temp->m_pNextClient)
		{
			temp = temp->m_pNextClient;
		}
		temp->m_pNextClient = new cClient;
		*temp->m_pNextClient = *pClient;
	}
}

////////////////////////////////////////////////////////////////////////////////

cClient* cClientsList::FindByUserName(string sUserName)
{
	for (cClient* pClient = m_pHead; pClient != NULL; pClient = pClient->m_pNextClient)
	{
		if (pClient->GetUsername() == sUserName)
		{
			return pClient;
		}
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////

cClient* cClientsList::Begin()
{
	return m_pHead;
}

////////////////////////////////////////////////////////////////////////////////