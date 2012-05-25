#include <QtNetwork>
#include <QDebug>

class cQServer
{	
public:
	cQServer(void);
	~cQServer(void);

	QTcpServer* m_pTcpServer;

	void StartServer (int Port);

	void OnClientConnected (QTcpServer* Server);
};
