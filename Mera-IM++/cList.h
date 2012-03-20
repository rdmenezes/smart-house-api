#pragma once
#include "cClient.h"

using namespace std;

template<class T>class cList
{
public:
	 cList();
	 ~cList();

protected:
	struct ListItem
    {
        ListItem* m_pNext;
        T* m_pData;
        ListItem(T* pData)
        {
			m_pData = pData;
		}
    };
	ListItem* m_pHead;
public:
	
	void Insert(T* Client);
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