#include "MessageManager.h"


using namespace std;


////////////////////////////////////////////////////////////////////////////////

cMessageManager* cMessageManager::Instance()
{
	static cMessageManager pSelf;
	return &pSelf;
}

////////////////////////////////////////////////////////////////////////////////

cMessageManager::cMessageManager ()
{
	m_pClientsList = new cClientsList;
}

////////////////////////////////////////////////////////////////////////////////

cMessageManager::~cMessageManager()
{
	delete m_pClientsList;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessDialog(QTcpSocket* ClientSocket,int nType, QString* sMessage)
{
	cClient User;
	bool rc = false;
	
/*	char MessageLength[4];
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
	*/
	sMessage->remove('\n');
	//QString sType = *sMessage->begin();
	if (sMessage->length() < 2)
	{
		return false;
	}

	switch (nType)
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
                rc = ProcessIMRequest(sMessage);
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

bool cMessageManager::ProcessRegisterRequest(QTcpSocket* ClientSocket, QString* sMessage)
{
	cClient* pUser = new cClient;
	QString sUsername,sPassword, sResponce;
	bool rc = false;
	//As we know, that message format Register Request is "0,username,password",
	//so set i to 2 as we are aware, that username starts with the third element, because two first once are "0" and ","
	if (sMessage->length() < 3)
	{
		return false;
	}

    signed int i = 2;
	while (sMessage->at(i) != ',' && sMessage->at(i) != '\0')
	{
		sUsername.push_back(sMessage->at(i));
		i++;
	}

	i++;
	while (i < sMessage->length() && sMessage->at(i) != '\0')
	{
		sPassword.push_back(sMessage->at(i));
		i++;
	}


	if (!IsUserRegistered(sUsername))
	{
		sResponce = "Registered successfully";
		pUser->SetTcpSocket(ClientSocket);
		pUser->SetUserName(sUsername);
		pUser->SetUserPassword(sPassword);
		m_pClientsList->Insert(pUser);
		//ClientSocket->write("Registered successfully");
		emit SendToClient(ClientSocket,sResponce);
		rc = true;
	}

	else
	{
		sResponce = "such user is already registered on this server";
		//ClientSocket->write("such user is already registered on this server");
		emit SendToClient(ClientSocket,sResponce);
	}

	delete pUser;
	return rc;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessLoginRequest(QTcpSocket* ClientSocket, QString* sMessage)
{
	QString sUsername,sPassword,sResponce;
	
    signed i = 2;
	while (sMessage->at(i) != ',')
	{
		sUsername.push_back(sMessage->at(i));
		i++;
	}
	i++;
	while (i < sMessage->length() && sMessage->at(i) != '\0')
	{
		sPassword.push_back(sMessage->at(i));
		i++;
	}

	cClient* pClient = m_pClientsList->FindByUsername(sUsername);
	if (!pClient)
	{
		sResponce = "User not found";
		//ClientSocket->write("User not found");
		emit SendToClient(ClientSocket,sResponce);
		return false;
	}
	else
	{
		if (pClient->GetUserPassword() == sPassword)
		{
			sResponce = "Log in successfully";
			pClient->SetConnected(true);
			//ClientSocket->write("Log in successfully");
			emit SendToClient(ClientSocket,sResponce);
			return true;
		}
		else
		{
			sResponce = "Incorrect password";
			//ClientSocket->write("Incorrect password");
			emit SendToClient(ClientSocket, sResponce);
			return false;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessLogoutRequest(QTcpSocket* ClientSocket)
{
	cClient* pClient = new cClient;//m_pClientsList->FindBySocketID(ClientSocket);
	if (!pClient)
	{
		return false;
	}
	else
	{
		pClient->SetConnected(false);
//		closesocket(ClientSocket);
		return true;
	}
}
////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::IsUserRegistered(QString sUsername)
{
	return (m_pClientsList->FindByUsername(sUsername) != NULL) ? true : false;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessIMRequest(QString* sMessage)
{
	QString sDestination, sIM;

    signed i = 2;
	while (sMessage->at(i) != ',')
	{
		sDestination.push_back(sMessage->at(i));
		i++;
	}

	i++;
	while (i < sMessage->length() && sMessage->at(i) != '\0')
	{
		sIM.push_back(sMessage->at(i));
		i++;
	}

	if (FindSocketByUsername(sDestination) > 0)
	{
		QTcpSocket* receiver = FindSocketByUsername(sDestination);
        emit SendToClient(receiver, sIM);
		return true;
	}

	return false;
}

////////////////////////////////////////////////////////////////////////////////

bool cMessageManager::ProcessStatusChangedRequest(QTcpSocket* ClientSocket,QString* sMessage)
{
	QString sState;
	size_t i = 2;
	sState = sMessage[i];
	cClient* pClient = new cClient;//m_pClientsList->FindBySocketID(ClientSocket);
	if (!pClient)
	{
		return false;
	}
	else
	{
		pClient->SetStatus((eStatus)(sState.toInt()));
		return true;
	}
}

////////////////////////////////////////////////////////////////////////////////

QTcpSocket* cMessageManager::FindSocketByUsername(QString sUsername)
{
	cClient* pClient = m_pClientsList->FindByUsername(sUsername);
	if (pClient)
	{
		return pClient->GetTcpSocket();
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
cClientsList* cMessageManager::GetClientsList()
{
	return m_pClientsList;
}

void cMessageManager::OnMessage(cBaseMessage* pMessage, QTcpSocket* pSenderSocket)
{
	switch(pMessage->m_nID)
	{
	case RegisterRequest:
		OnRegisterRequest((cRegisterRequest* )pMessage);
	}
}

void cMessageManager::OnRegisterRequest( cRegisterRequest* pRequest )
{
	int a = 0;
	a++;
	a--;
}
