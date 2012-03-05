#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>

using namespace std;

enum eStatus {eSTATUS_Available, eSTATUS_FreeToTalk, eSTATUS_Away, eSTATUS_DoNotDisturb, eSTATUS_Offline};
class cClient 
{
public:
	cClient();
	~cClient();

private:

	string m_sUserName;
	string m_sUserPassword;
	eStatus m_eStatus;
	bool m_bIsConnected;
	int m_nSocketID;

public:
	cClient* m_pNextClient;
	void SetStatus(eStatus eStatus);
	void SetConnected(bool bIsConnected);
	eStatus GetStatus();
	bool IsConnected();
	void SetSocketID (int nSocketID);
	void SetUserName(string sUserName);
	void SetUserPassword(string sUserPassword);
	string GetUsername();
	string GetUserPassword();
	SOCKET GetSocketID();

	cClient& operator = (const cClient& Copy);
};