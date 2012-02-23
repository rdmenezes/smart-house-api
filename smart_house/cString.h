#pragma once
#include "iostream"
#include "cSocket.h"

using namespace std;

class cString
{
public:
	cString();
	cString(const char* Name);
	cString(const cString &copy);
	~cString();

	cString& operator = (const cString &copy);
	bool operator == (cString string);
	bool operator != (cString string);
	bool operator == (const char* string);
	bool operator != (const char* string);

	int Bites_receaved;
	char buff[1024];
	char*  str;
	bool ReadLine(char* TextPrompt = NULL);
	bool ReadLine(char* TextPrompt, int socket);
	int ToInt();
	std::string GetStringFromSocket(int socket);

	void PutString(int ClietnSocket, const char* string);
	void PutString(int ClientSocket, std::string string);
	void PutStringFormated(int ClientSocket, const char * format, ...);
};