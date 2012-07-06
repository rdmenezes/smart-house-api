#include "Message.h"

cBaseMessage::cBaseMessage()
{
	m_nID = -1;
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