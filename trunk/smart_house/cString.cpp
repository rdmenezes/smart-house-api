#include "cString.h"
cString::cString()
{
	str = 0;
}

//=========================================================================//

cString::cString (const char* string)
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

bool cString::ReadLine(char* TextPrompt, int socket)
{
	char mBuff[200];
	if (TextPrompt)
	{
		send(socket,&TextPrompt[0],strlen(TextPrompt),0);
		send(socket,"\n>",1,0);
	}
	else 
	{
		send(socket,"\n>",1,0);
	}

	std::string sTemp = GetStringFromSocket(socket);
	std::copy(sTemp.begin(),sTemp.end(), mBuff);
	if(mBuff != NULL)
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

int cString::ToInt()
{
	unsigned int result = 0;
	for (size_t i=0; i < strlen(str); ++i)
	{
		result *= 10;
		result +=str[i]-'0';
	}
	return result;
}


std::string cString::GetStringFromSocket(int socket)
{
	std::string string;
	Bites_receaved = recv(socket,&buff[0],sizeof(buff),0);
	str = new char [Bites_receaved+1];
	for (size_t i = 0; i <= Bites_receaved+1; ++i)
	{
		if (i<=Bites_receaved)
		{
			str[i] = buff[i];
		}
		else str[i-1] = 0;
	}

	for (size_t i = 0; i < sizeof(buff);i++)
	{
		if (str[i] != 0 && str[i] != 10)
		{
			string.push_back(str[i]);
		}
		else 
		{
			string.push_back(NULL);
			return string;
		}
	}
}



void cString::PutString(int ClientSocket, const char* string)
{
	send(ClientSocket,&string[0],strlen(string),0);
}

void cString::PutString(int ClientSocket, std::string string)
{
	send(ClientSocket,&string[0],string.length(),0);
}

void cString::PutStringFormated(int ClientSocket, const char * format, ...)
{
        char xbuf[128]; 
        va_list arg_list;
        va_start(arg_list, format);
        vsprintf(xbuf, format, arg_list);
        va_end(arg_list);
		send(ClientSocket,&xbuf[0],strlen(xbuf),0);
}