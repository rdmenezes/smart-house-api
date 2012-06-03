#pragma once
#include <iostream>
#include <string>
#include <qstring.h>
#include <QtNetwork>
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
	QTcpSocket* m_pTcpSocket;

public:
	void SetStatus(eStatus eStatus);
	void SetConnected(bool bIsConnected);
	void SetTcpSocket(QTcpSocket* Socket);
	eStatus GetStatus();
	bool IsConnected();
	void SetUserName(QString sUserName);
	void SetUserPassword(QString sUserPassword);
	QString GetUsername();
	QString GetUserPassword();
	QTcpSocket* GetTcpSocket();

	cClient& operator = (const cClient& Copy);
};
