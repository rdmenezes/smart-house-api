#pragma once
#include "iostream"
#include "string"


enum eStatus {Available, FreeToTalk, Away, DoNotDisturb, Offline};
class cClient 
{
public:
	cClient();
	~cClient();

private:

	std::string UserName;
	std::string UserPassword;
	eStatus Status;
	bool Registered;
	int SocketID;

public:
	cClient* Next;
	void SetStatus(cClient Client, eStatus Status);
	eStatus GetStatus(cClient Client);
	bool IsRegistered(cClient Client);
	void SetSocketID (int Socket);
	void SetUserName(std::string UserName);
	void SetUserPassword(std::string UserPassword);
	std::string GetUsername();

	cClient& operator = (const cClient& Copy);
};