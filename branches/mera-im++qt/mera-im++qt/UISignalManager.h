#pragma once
#include "cServer.h"
#include "Definitions.h"
#include "cUtils.h"
#include "qtserver.h"

class cUISignalManager : public QWidget
{
	Q_OBJECT
public:
	cUISignalManager(void);
	~cUISignalManager(void);
	static cUISignalManager* Instance();
	static void Initialize();
	void Put(cEvent* event);

signals:
	void StartServerResponce(QString responce);

public slots:
	void OnEventFromUI();


private:
	static cUISignalManager* m_pSelf;
	static DWORD WINAPI ProcessEvent(LPVOID action);
};

