#pragma once
#include "iostream"

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
	char*  str;
	bool ReadLine(const char* TextPrompt = NULL);
	int ToInt();
};
