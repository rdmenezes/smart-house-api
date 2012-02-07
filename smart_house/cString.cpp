#include "cString.h"

cString::cString()
{
}

//=========================================================================//

cString::cString (char* string)
{
	for (size_t i=0; i <= strlen(string); i++)
	{
		str[i] = string[i];
	}
}

//=========================================================================//

cString::cString(const cString &copy)
{
	for (size_t i=0; i <= strlen(copy.str); i++)
	{
		str[i] = copy.str[i];
	}
}


//=========================================================================//

cString::~cString()
{
}

//=========================================================================//

bool cString::GetString()
{
	if(cin.getline (str, 20))
	{
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