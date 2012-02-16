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

void cRoom::Print()
{
	for (size_t i=0; i < m_pWindows.size(); i++)
	{
		cout << "\t\t  Window " << i << " is " << (m_pWindows[i].m_bOpened ? "opened":"closed") << endl;
	}
}

cString cRoom::Serialize()
{
	cString rslt;
	TiXmlDocument doc;
	TiXmlPrinter printer;
	TiXmlElement * txRoom = new TiXmlElement("room");

	for (size_t i = 0; i<m_pWindows.size(); ++i)
	{
		TiXmlDocument txWindow;
		txWindow.Parse(m_pWindows[i].Serialize().str);
		txRoom->InsertEndChild(*txWindow.RootElement());
	}

	doc.LinkEndChild(txRoom);
	printer.SetIndent( "\t" );
	doc.Accept( &printer );
	rslt = cString((char*)printer.CStr());
	return rslt;
}

void cRoom::Deserialize( cString data )
{
	TiXmlDocument doc;
	doc.Parse(data.str);
	for( TiXmlElement *txWindow = doc.FirstChildElement("room")->FirstChildElement("window"); txWindow; txWindow = txWindow->NextSiblingElement("window") )
	{
		TiXmlPrinter printer;
		txWindow->Accept(&printer);
		printer.SetIndent( "\t" );

		AddWindow();
		m_pWindows[m_pWindows.size()-1].Deserialize(cString((char*)printer.CStr()));
	}
}
