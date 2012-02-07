#pragma once
#include "iostream"

using namespace std;

class cString
{
public:
	cString();
	cString(char* Name);
	~cString();
	bool operator == (cString* string);
	bool operator != (cString* string);
	char  str[20];
	bool GetString();
};