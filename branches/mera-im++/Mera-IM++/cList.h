#pragma once
#include "cClient.h"

using namespace std;

template<class T>class cList
{
public:
	 cList();
	 ~cList();

private:
	struct ListItem
    {
        ListItem* m_pNext;
        T* m_pData;
        ListItem(T* pData)
        {
			m_pData = new T;
			*m_pData = *pData;
		}
    };
	ListItem* m_pHead;
public:
	
	void Insert(T* Client);
	T* FindByUsername(string sUsername);
	T* FindBySocketID(SOCKET SocketID);
};

template<class T> cList<T>::cList()
{
	m_pHead = NULL;
}

////////////////////////////////////////////////////////////////////////////////

template<class T> cList<T>::~cList()
{
}

////////////////////////////////////////////////////////////////////////////////
template<class T> void cList<T>::Insert(T* Data)
{
	ListItem* pNewItem = new ListItem(Data);
	pNewItem->m_pNext = 0;
	
	if (!m_pHead)
	{
		m_pHead = pNewItem;
	}
	else
	{
		ListItem* temp = m_pHead;
		while (temp->m_pNext)
		{
			temp = temp->m_pNext;
		}
		temp->m_pNext = pNewItem;
	}
}

////////////////////////////////////////////////////////////////////////////////

template<class T> T* cList<T>::FindByUsername(string sUsername)
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

template<class T> T* cList<T>::FindBySocketID(SOCKET SocketID)
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

////////////////////////////////////////////////////////////////////////////////