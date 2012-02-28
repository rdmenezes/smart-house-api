#include "cClient.h"
cClient::cClient()
{
	Registered = false;
	Status = Offline;
	SocketID = -1;
}

cClient::~cClient()
{
}

void cClient::SetStatus(cClient Client, eStatus Status)
{
	Client.Status = Status;
}

eStatus cClient::GetStatus(cClient Client)
{
	return Client.Status;
}

bool cClient::IsRegistered(cClient Client)
{
	return Client.Registered;
}

cClient& cClient::operator = (const cClient& Copy)
{
	UserName = Copy.UserName; //socketID
	UserPassword = Copy.UserPassword;
	Status = Copy.Status;
	Registered = Copy.Registered;
	Next = Copy.Next;
	SocketID = Copy.SocketID;
	return *this;
}

void cClient::SetSocketID (int Socket)
{
	this->SocketID = Socket;
}

void cClient::SetUserName(std::string UserName)
{
	this->UserName = UserName;
}

void cClient::SetUserPassword(std::string UserPassword)
{
	this->UserPassword = UserPassword;
}

std::string cClient::GetUserName()
{
	return UserName;
}
