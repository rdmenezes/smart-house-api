#include <winsock2.h>
#include <windows.h>
#include "cUtils.h"
#include "cMessageManager.h"

class cServer
{
public:
	cServer(void);
	~cServer(void);
	int StartServer();
	SOCKET GetClient(SOCKET Server);
	static cServer* Instance();

private:
	static cServer* m_pSelf;
};