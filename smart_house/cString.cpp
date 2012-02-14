#include "cString.h"
#include <string.h>
cString::cString()
{
	str = 0;
}

//=========================================================================//

cString::cString (char* string)
{
	if(!string)
		return;
	str = new char [strlen(string)+1];
	for (size_t i=0; i <= strlen(string); i++)
	{
		str[i] = string[i];
	}
}

//=========================================================================//

cString::cString(const cString &copy)
{
	str = new char [strlen(copy.str)+1];
	for (size_t i=0; i <= strlen(copy.str); i++)
	{
		str[i] = copy.str[i];
	}	
}


//=========================================================================//

cString::~cString()
{
	delete [] str;
}

//=========================================================================//

bool cString::ReadLine(char* TextPrompt)
{
	char mBuff[200];
	if (TextPrompt)
	{
		cout << TextPrompt << endl << ">";
	}
	else 
	{
		cout << ">";
	}
	if(cin.getline (mBuff, 200))
	{
		delete [] str;
		str = new char [strlen(mBuff)+1];
		for (size_t i = 0; i <= strlen(mBuff); ++i)
		{
			str[i] = mBuff[i];
		}
		return true;
	}
	else
	{
		return false;
	}
}

//=========================================================================//

cString& cString::operator = (const cString &copy)
{
	delete [] str;
	str = new char [strlen(copy.str)+1];
	for (size_t i=0; i <= strlen(copy.str); i++)
	{
		str[i] = copy.str[i];
	}
	return *this;
}

//=========================================================================//

bool cString::operator == (cString string)
{
	if(strcmp(string.str,str) == 0) 
	{
		return true;
	}
	else
	{
		return false; 
	}
}

//=========================================================================//

bool cString::operator == (const char* string)
{
	if (strcmp(string,str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//=========================================================================//

bool cString::operator != (const char* string)
{
	if (strcmp(string,str) == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//=========================================================================//

bool cString::operator != (cString string)
{
	if(strcmp(string.str,str) == 0) 
	{
		return false;
	}
	else
	{
		return true; 
	}
}

//=========================================================================//