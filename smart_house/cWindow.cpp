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

cString cWindow::Serialize()
{
	cString rslt;
	TiXmlDocument doc;
	TiXmlPrinter printer;
	TiXmlElement * txRoom = new TiXmlElement("room");
	txRoom->SetAttribute("opened",m_bOpened?"true":"false");
	

	doc.LinkEndChild(txRoom);
	printer.SetIndent( "\t" );
	doc.Accept( &printer );
	rslt = cString((char*)printer.CStr());
	return rslt;
}

void cWindow::Deserialize( cString data )
{
	TiXmlDocument doc;
	doc.Parse(data.str);
	//TODO: parse window state
}
