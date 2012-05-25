#ifndef QTSERVER_H
#define QTSERVER_H
#pragma once

#include <QtGui/QWidget>
#include "ui_qtserver.h"
#include "Definitions.h"
#include "UISignalManager.h"
#include "cServer.h"
#include "cQServer.h"

class qtserver : public QWidget
{
	Q_OBJECT

public:
	qtserver(QWidget *parent = 0, Qt::WFlags flags = 0);
	~qtserver();
	void OnMessage(cEvent* event);
	static qtserver* Instance();

signals:
	void OnEventFromUI();

public slots:
    void on_StartServer_clicked();
	void OnStartServerResponce(QString responce);


private:
	Ui::qtserverClass ui;
	static qtserver* m_pSelf;

	cQServer* m_pServer;
};

#endif // QTSERVER_H
