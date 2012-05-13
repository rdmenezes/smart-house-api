#include "cMessageManager.h"


using namespace std;

cMessageManager* cMessageManager::m_pSelf = 0;

////////////////////////////////////////////////////////////////////////////////

cMessageManager* cMessageManager::Instance()
{
	if (!m_pSelf)
	{
		m_pSelf = new cMessageManager;
	}
	return m_pSelf;
}

////////////////////////////////////////////////////////////////////////////////

cMessageManager::cMessageManager ()
{
	m_pClientsList = new cClientsList;
}

////////////////////////////////////////////////////////////////////////////////

cMessageManager::~cMessageManager()
{
	delete m_pSelf;
	delete m_pClientsList;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessDialog(SOCKET ClientSocket)
{
	cClient User;
	bool rc = false;
	
	char MessageLength[4];
	int Bytesrecv;
	
	if ((Bytesrecv = recv(ClientSocket,&MessageLength[0],4,0)) > 3)
	{
		return rc;
	}

	unsigned int nMessageLength = atoi(MessageLength);
	char* sMessage = new char [nMessageLength+1];
	
	recv(ClientSocket,&sMessage[0],nMessageLength,0);
	sMessage[nMessageLength] = '\0';


	// Putting '\0' where ever we encounter '\n'. This is for development testing using netcat because netcat puts \n in the end of
	// message when pressing ENTER but we're parsing \0's 
	for (size_t i = 0; i <= nMessageLength; i++) {sMessage[i] = (sMessage[i] == '\n' ? '\0':sMessage[i]);}
	
	eMessageType eType;
	eType = ProcessMessageType(sMessage[0]);

	switch (eType)
	{
		case eMESSAGE_RegisterRequest:
			{
				rc = ProcessRegisterRequest(ClientSocket,sMessage);
				break;
			}

		case eMESSAGE_LoginRequest:
			{
				rc = ProcessLoginRequest(ClientSocket,sMessage);
				break;
			}
		case eMESSAGE_LogoutRequest:
			{
				rc = ProcessLogoutRequest(ClientSocket);
				break;
			}
		case eMESSAGE_IM:
			{
				rc = ProcessIMRequest(ClientSocket,sMessage);
				break;
			}
		case eMESSAGE_StatusChanged:
			{
				rc = ProcessStatusChangedRequest(ClientSocket,sMessage);
				break;
			}
	}

	return rc;
}

////////////////////////////////////////////////////////////////////////////////

eMessageType cMessageManager::ProcessMessageType(char x)
{
	return (eMessageType)(x-'0');
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessRegisterRequest(SOCKET ClientSocket, char* sMessage)
{
	cClient* pUser = new cClient;
	string sUsername,sPassword;
	bool rc = false;
	//As we know, that message format Register Request is "0,username,password",
	//so set i to 2 as we are aware, that username starts with the third element, because two first once are "0" and ","
	int c = strlen(sMessage);
	if (c <= 3)
	{
		return false;
	}

	size_t i = 2;
	while (sMessage[i] != ',' && sMessage[i] != '\0')
	{
		sUsername.push_back(sMessage[i]);
		i++;
	}

	i++;
	while (sMessage[i] != '\0')
	{
		sPassword.push_back(sMessage[i]);
		i++;
	}


	if (!IsUserRegistered(sUsername))
	{
		pUser->SetSocketID(ClientSocket);
		pUser->SetUserName(sUsername);
		pUser->SetUserPassword(sPassword);
		m_pClientsList->Insert(pUser);
		send(ClientSocket,"success",sizeof("success"),0);
		rc = true;
	}

	else
	{
		send(ClientSocket,"failed",sizeof("failed"),0);
	}

	delete pUser;
	return rc;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessLoginRequest(SOCKET ClientSocket, char* sMessage)
{
	string sUsername,sPassword;
	
	size_t i = 2;
	while (sMessage[i] != ',')
	{
		sUsername.push_back(sMessage[i]);
		i++;
	}
	i++;
	while (sMessage[i] != '\0')
	{
		sPassword.push_back(sMessage[i]);
		i++;
	}

	cClient* pClient = m_pClientsList->FindByUsername(sUsername);
	if (!pClient)
	{
		closesocket(ClientSocket);
		return false;
	}
	else
	{
		if (pClient->GetUserPassword() == sPassword)
		{
			pClient->SetConnected(true);
			return true;
		}
		else
		{
			closesocket(ClientSocket);
			return false;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessLogoutRequest(SOCKET ClientSocket)
{
	cClient* pClient = m_pClientsList->FindBySocketID(ClientSocket);
	if (!pClient)
	{
		return false;
	}
	else
	{
		pClient->SetConnected(false);
		closesocket(ClientSocket);
		return true;
	}
}
////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::IsUserRegistered(string sUsername)
{
	return (m_pClientsList->FindByUsername(sUsername) != NULL) ? true : false;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessIMRequest(SOCKET ClientSocket,char* sMessage)
{
	string sDestination, sIM;

	size_t i = 2;
	while (sMessage[i] != ',')
	{
		sDestination.push_back(sMessage[i]);
		i++;
	}

	i++;
	while (sMessage[i] != '\0')
	{
		sIM.push_back(sMessage[i]);
		i++;
	}

	if (FindSocketByUsername(sDestination) > 0)
	{
		send(FindSocketByUsername(sDestination),&sIM[0],sIM.length(),0);
		return true;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessStatusChangedRequest(SOCKET ClientSocket,char* sMessage)
{
	char cState;
	size_t i = 2;
	cState = sMessage[i];
	cClient* pClient = m_pClientsList->FindBySocketID(ClientSocket);
	if (!pClient)
	{
		return false;
	}
	else
	{
		pClient->SetStatus((eStatus)(cState - '0'));
		return true;
	}
}

////////////////////////////////////////////////////////////////////////////////

SOCKET cMessageManager::FindSocketByUsername(string sUsername)
{
	cClient* pClient = m_pClientsList->FindByUsername(sUsername);
	if (pClient)
	{
		return pClient->GetSocketID();
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////