#pragma once
#include "iostream"
#include "winsock2.h"
#include "string"

using namespace std;

class cString
{
public:
	cString();
	cString(char* Name);
	cString(const cString &copy);
	~cString();

	cString& operator = (const cString &copy);
	bool operator == (cString string);
	bool operator != (cString string);
	bool operator == (const char* string);
	bool operator != (const char* string);
	char*  str;
	bool ReadLine(char* TextPrompt = NULL);
	int ToInt();
	std::string GetStringFromSocket ();
};