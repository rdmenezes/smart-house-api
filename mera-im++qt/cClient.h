#pragma once
#include <iostream>
#include <string>
#include <qstring.h>
using namespace std;


enum eStatus {eSTATUS_Available, eSTATUS_FreeToTalk, eSTATUS_Away, eSTATUS_DoNotDisturb, eSTATUS_Offline};
class cClient 
{
public:
	cClient();
	~cClient();

private:

	QString m_sUserName;
	QString m_sUserPassword;
	eStatus m_eStatus;
	bool m_bIsConnected;
	int m_nSocketID;

public:
	void SetStatus(eStatus eStatus);
	void SetConnected(bool bIsConnected);
	eStatus GetStatus();
	bool IsConnected();
	void SetSocketID (int nSocketID);
	void SetUserName(QString sUserName);
	void SetUserPassword(QString sUserPassword);
	QString GetUsername();
	QString GetUserPassword();
	int GetSocketID();

	cClient& operator = (const cClient& Copy);
};
