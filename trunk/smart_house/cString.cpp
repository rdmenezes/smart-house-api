#include "cString.h"

cString::cString()
{
}

cString::cString (char* string)
{
	for (size_t i=0; i <= strlen(string); i++)
	{
		str[i] = string[i];
	}
}

cString::~cString()
{
}

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

bool cString::operator == (cString* string)
{
	if(strcmp(string->str,str) == 0) 
	{
		return true;
	}
	else
	{
		return false; 
	}
}

bool cString::operator != (cString* string)
{
	if(strcmp(string->str,str) == 0) 
	{
		return false;
	}
	else
	{
		return true; 
	}
}
