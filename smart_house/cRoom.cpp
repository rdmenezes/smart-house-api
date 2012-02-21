#include "cRoom.h"
#include "iostream"
using namespace std;

cRoom::cRoom()
{
}


cRoom::~cRoom()
{
}

void cRoom::AddWindow(cWindow &window)
{
	m_pWindows.push_back(window);
}

void cRoom::AddWindow()
{
	m_pWindows.push_back(cWindow());
}

void cRoom::Print(cSocket* socket)
{
	for (size_t i=0; i < m_pWindows.size(); i++)
	{
		socket->PutStringFormated("\t  Window %d is %s\n",i,(m_pWindows[i].m_bOpened ? "opened":"closed"));
	}
}