#pragma once
#include "iostream"

using namespace std;

class cString
{
public:
	cString();
	cString(char* Name);
	cString(const cString &copy);
	~cString();

	cString& cString::operator = (const cString &copy);
	bool operator == (cString string);
	bool operator != (cString string);
	bool operator == (const char* string);
	bool operator != (const char* string);

	char  str[20];
	bool GetString();
};