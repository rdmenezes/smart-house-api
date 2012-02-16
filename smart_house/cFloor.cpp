#include "cFloor.h"
#include "iostream"
using namespace std;

cFloor::cFloor()
{
}


cFloor::~cFloor()
{
}

void cFloor::AddRoom(cRoom &room)
{
	m_pRooms.push_back(room);
}

void cFloor::AddRoom()
{
	cRoom room = cRoom();
	m_pRooms.push_back(room);
}

void cFloor::Print()
{	
	for(size_t i=0; i< m_pRooms.size();i++)
	{
		cout<<"      {"<<endl;
		m_pRooms[i].Print();
		cout<<"      }"<<endl;
	}
}

cString cFloor::Serialize()
{
	cString rslt;
	TiXmlDocument doc;
	TiXmlPrinter printer;
	TiXmlElement * txFloor = new TiXmlElement("floor");

	for (size_t i = 0; i<m_pRooms.size(); ++i)
	{
		TiXmlDocument txRoom;
		txRoom.Parse(m_pRooms[i].Serialize().str);
		txFloor->InsertEndChild(*txRoom.RootElement());
	}

	doc.LinkEndChild(txFloor);
	printer.SetIndent( "\t" );
	doc.Accept( &printer );
	rslt = cString((char*)printer.CStr());
	return rslt;
}

void cFloor::Deserialize( cString data )
{
	TiXmlDocument doc;
	doc.Parse(data.str);
	for( TiXmlElement *txRoom = doc.FirstChildElement("floor")->FirstChildElement("room"); txRoom; txRoom = txRoom->NextSiblingElement("room") )
	{
		TiXmlPrinter printer;
		txRoom->Accept(&printer);
		printer.SetIndent( "\t" );

		AddRoom();
		m_pRooms[m_pRooms.size()-1].Deserialize(cString((char*)printer.CStr()));
	}
}
