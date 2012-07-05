QDataStream &operator<<(QDataStream &out, cRegisterRequest &Request) 
{
	out << Request.m_nID 
		<< Request.m_sUsername
		<< Request.m_sPassword;
	return out;
}

QDataStream &operator>>(QDataStream &in, cRegisterRequest &Request)
{
	in >> Request.m_nID
		>> Request.m_sUsername
		>> Request.m_sPassword;
	return in;
}

QDataStream &operator>>(QDataStream &in, cBaseMessage &Message)
{
	in >> Message.m_nID;

	return in;
}
