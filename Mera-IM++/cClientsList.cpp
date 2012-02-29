#include "cClientsList.h"

cClientsList::cClientsList()
{
	Head = NULL;
}

cClientsList::~cClientsList()
{
}

void cClientsList::Insert(cClient* Client)
{
	Client->Next = 0;
	
	if (!Head)
	{
		Head = new cClient;
		*Head = *Client;
	}
	else
	{
		cClient* temp = Head;
		while (temp->Next)
		{
			temp = temp->Next;
		}
		temp->Next = new cClient;
		*temp->Next = *Client;
	}
}

cClient* cClientsList::Begin()
{
	return Head;
}
