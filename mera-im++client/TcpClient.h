#pragma once

#include <QtNetwork>


class cTcpClient : public QObject
{
	Q_OBJECT

public:
	static cTcpClient* Instance();


private:
	cTcpClient(void);
	~cTcpClient(void);
	quint16 m_nNextBlockSize;
	QTcpSocket* m_pTcpSocket;

private slots:
	void OnDataFromServer();
	void ConnectClicked (QString sServer, int nPort);
	void OnSendToServer (QString message, int Type);
	void OnConnected ();

signals:
	void ClientResponce(QString responce);

};