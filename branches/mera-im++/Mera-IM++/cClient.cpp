#include "cClient.h"

using namespace std;

cClient::cClient()
{
	m_bIsConnected = false;
	m_eStatus = eSTATUS_Offline;
	m_nSocketID = -1;
}

////////////////////////////////////////////////////////////////////////////////

cClient::~cClient()
{
}

////////////////////////////////////////////////////////////////////////////////

void cClient::SetStatus(eStatus eStatus)
{
	m_eStatus = eStatus;
}

////////////////////////////////////////////////////////////////////////////////

eStatus cClient::GetStatus()
{
	return m_eStatus;
}

////////////////////////////////////////////////////////////////////////////////

bool cClient::IsConnected()
{
	return m_bIsConnected;
}

////////////////////////////////////////////////////////////////////////////////

void cClient::SetConnected(bool bIsConnected)
{
	m_bIsConnected = bIsConnected;
}

////////////////////////////////////////////////////////////////////////////////

cClient& cClient::operator = (const cClient& Copy)
{
	m_sUserName = Copy.m_sUserName; //socketID
	m_sUserPassword = Copy.m_sUserPassword;
	m_eStatus = Copy.m_eStatus;
	m_bIsConnected = Copy.m_bIsConnected;
	m_pNextClient = Copy.m_pNextClient;
	m_nSocketID = Copy.m_nSocketID;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////

void cClient::SetSocketID(int nSocketID)
{
	m_nSocketID = nSocketID;
}

////////////////////////////////////////////////////////////////////////////////

void cClient::SetUserName(string sUserName)
{
	m_sUserName = sUserName;
}

////////////////////////////////////////////////////////////////////////////////

void cClient::SetUserPassword(string sUserPassword)
{
	m_sUserPassword = sUserPassword;
}

////////////////////////////////////////////////////////////////////////////////

string cClient::GetUsername()
{
	return m_sUserName;
}

////////////////////////////////////////////////////////////////////////////////

string cClient::GetUserPassword()
{
	return m_sUserPassword;
}

////////////////////////////////////////////////////////////////////////////////

SOCKET cClient::GetSocketID()
{
	return m_nSocketID;
}
