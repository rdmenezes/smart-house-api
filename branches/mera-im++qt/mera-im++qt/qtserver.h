#ifndef QTSERVER_H
#define QTSERVER_H

#include <QMainWindow>
#include "cQServer.h"
#include "Definitions.h"

namespace Ui {
class qtserver;
}

class qtserver : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit qtserver(QWidget *parent = 0);
    ~qtserver();
    
private:
    Ui::qtserver *ui;
    cQServer* m_pServer;
	eServerState m_eServerState;

private slots:
    void on_StartServer_clicked();
    void OnExit();

public slots:
	void OnServerMessage(QString message);
};

#endif // QTSERVER_H
