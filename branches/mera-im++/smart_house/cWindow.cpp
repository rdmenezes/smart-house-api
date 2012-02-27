#include "cWindow.h"
#include "iostream"
using namespace std;


cWindow::cWindow()
{
	m_bOpened = false;
}


cWindow::~cWindow()
{
}
void cWindow::Open()
{
	if (!m_bOpened)
	{
		m_bOpened = true;
		cout << "Window is opened" << endl;
	}
	else 
	{
		cout << "Windows is already opened" << endl;
	}
}

void cWindow::Close()
{
	if (m_bOpened)
	{
		m_bOpened = false;
		cout << "Window is closed" << endl;
	}
	else 
	{
		cout << "Windows is already closed" << endl;
	}
}