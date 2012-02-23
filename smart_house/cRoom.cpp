#include "cRoom.h"

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

void cRoom::Print(int socket)
{
	cString s;
	for (size_t i=0; i < m_pWindows.size(); i++)
	{
		s.PutStringFormated(socket, "\t  Window %d is %s\n",i,(m_pWindows[i].m_bOpened ? "opened":"closed"));
	}
}