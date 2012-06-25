#ifndef QTCLIENT_H
#define QTCLIENT_H

#include <QMainWindow>
#include "TcpClient.h"

namespace Ui {
class QtClient;
}

class QtClient : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QtClient(QWidget *parent = 0);
    ~QtClient();
    
private:
    Ui::QtClient *ui;
	cTcpClient* m_pTcpClient;

private slots:

	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void OnClientResponce(QString responce);

signals:
	void ConnectClicked(QString nIpAddr,int nPort);
	void SendToServer(QString message, int Type);
};

#endif // QTCLIENT_H
