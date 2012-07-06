#include "Message.h"


QDataStream& operator>>(QDataStream& in, cRegisterRequest &Request)
{
	in	>> Request.m_nID
		>> Request.m_sUsername
		>> Request.m_sPassword;
	return in;
}


cBaseMessage::cBaseMessage()
{
}

cBaseMessage::~cBaseMessage()
{
}

cRegisterRequest::cRegisterRequest()
{
	m_nID = RegisterRequest;
}
cRegisterRequest::~cRegisterRequest()
{
}

cBaseMessage* cRegisterRequest::Deserialize(QDataStream in)
{
	cRegisterRequest Message;
	in >> Message;
	return &Message;
}