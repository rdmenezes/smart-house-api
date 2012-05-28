#ifndef QTSERVER_H
#define QTSERVER_H
#pragma once

#include <QtGui/QWidget>
#include "ui_qtserver.h"
#include "Definitions.h"
#include "cQServer.h"

class qtserver : public QWidget
{
	Q_OBJECT

public:
	qtserver(QWidget *parent = 0, Qt::WFlags flags = 0);
	~qtserver();
	static qtserver* Instance();

public slots:
    void on_StartServer_clicked();
	void OnStartServerResponce(QString responce);

private:
	Ui::qtserverClass ui;
	static qtserver* m_pSelf;

	cQServer* m_pServer;
};

#endif // QTSERVER_H
