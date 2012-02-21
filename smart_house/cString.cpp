#include "cString.h"
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
	std::string sTemp = GetStringFromSocket();
	std::copy(sTemp.begin(),sTemp.end(), mBuff);
	if (TextPrompt)
	{
		cout << TextPrompt << endl << ">";
	}
	else 
	{
		cout << ">";
	}
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


std::string cString::GetStringFromSocket ()
{
	char buffer[1024];
	int ServerSocket;
	WORD SocketVersion = MAKEWORD(2,2);
	WSAStartup (SocketVersion,(WSADATA *) &buffer[0]);
	
	ServerSocket = socket (AF_INET, SOCK_STREAM, 0);

	sockaddr_in LocalAddr;
	LocalAddr.sin_family = AF_INET;
	LocalAddr.sin_port = htons(1234);
	LocalAddr.sin_addr.s_addr = 0;

	int result = bind(ServerSocket,(sockaddr *) &LocalAddr, sizeof(LocalAddr));
	int result1 = listen(ServerSocket, 100);

	SOCKET ClientSocket;
    sockaddr_in ClientSocketAddr;
	int ClientSocketAddrSize = sizeof(ClientSocketAddr);
	ClientSocket=accept(ServerSocket, (sockaddr *) &ClientSocketAddr, &ClientSocketAddrSize);
	char str[1024];

	char buff[1024];
	std::string string;
	int Bites_receaved = recv(ClientSocket,&buff[0],sizeof(buff),0);
	for (size_t i =0; i <= Bites_receaved+1; ++i)
	{
		if (i<=Bites_receaved)
		{
			str[i] = buff[i];
		}
		else str[i-1] = '0';
	}
	
	for (size_t i = 0; i < sizeof(buff);i++)
	{
		if (str[i] != '0')
		{
			string.push_back(str[i]);
		}
		else 
		{
			string.push_back(NULL);
			break;
		}
	}
	closesocket(ClientSocket);
	closesocket(ServerSocket);

	WSACleanup();
	return string;
}