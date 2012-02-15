#include "cHouse.h"
#include "iostream"
using namespace std;

cHouse::cHouse()
{
	Name = "Default";
}

cHouse::cHouse(const cHouse &copy)
{
	Name = copy.Name;
	m_pFloors = copy.m_pFloors;
}

cHouse &cHouse::operator = ( const cHouse &copy )
{
	Name = copy.Name;
	m_pFloors = copy.m_pFloors;
	return *this;
}


cHouse::~cHouse()
{
}

void cHouse::AddFloor(cFloor &floor)
{
	m_pFloors.push_back(floor);
}
void cHouse::AddFloor()
{
	m_pFloors.push_back(cFloor());
}

void cHouse::Print()
{
	cout << Name.str << "\n";
	for (size_t i=0; i < m_pFloors.size(); i++)
	{
		cout << " " << i << endl << "  {" << endl;
		m_pFloors[i].Print();
		cout << "  }" << endl;
	}
	Serialize();
}

cString cHouse::Serialize()
{
	cString rslt;
	TiXmlDocument doc;
	TiXmlPrinter printer;
	TiXmlElement * txHouse = new TiXmlElement("house");
	txHouse->SetAttribute("name",Name.str);

	for (size_t i = 0; i<m_pFloors.size(); ++i)
	{
		TiXmlDocument txFloor;
		txFloor.Parse(m_pFloors[i].Serialize().str);
		txHouse->InsertEndChild(*txFloor.RootElement());
	}
	


	doc.LinkEndChild(txHouse);
	printer.SetIndent( "\t" );
	doc.Accept( &printer );
	rslt = cString((char*)printer.CStr());
	return rslt;
}
