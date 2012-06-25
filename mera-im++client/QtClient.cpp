#include "QtClient.h"
#include "ui_QtClient.h"

QtClient::QtClient(QWidget *parent) :
QMainWindow(parent),
	ui(new Ui::QtClient)
{
	ui->setupUi(this);
	m_pTcpClient = cTcpClient::Instance();
	if (m_pTcpClient)
	{
		connect (this, SIGNAL(ConnectClicked(QString, int)),m_pTcpClient, SLOT(ConnectClicked(QString, int)));
		connect(m_pTcpClient, SIGNAL(ClientResponce(QString)), this, SLOT(OnClientResponce(QString)));
		connect (this, SIGNAL(SendToServer(QString, int)), m_pTcpClient, SLOT(OnSendToServer(QString, int)));
	}
}

QtClient::~QtClient()
{
	delete ui;
}

void QtClient::on_pushButton_clicked()  //Connect button
{
	emit ConnectClicked(ui->lineEdit->text(),ui->lineEdit_2->text().toInt());
}

void QtClient::on_pushButton_2_clicked() //Send button
{
	//This is the "Send" button, so once it's pushed the IM is going to be send,
	//so the second parameter for signal SendToServer is hardcoded, which is
	//according to the requirements equals 3.
	emit SendToServer(ui->lineEdit_3->text(), 3);
	ui->textBrowser->append(ui->lineEdit_3->text());
	ui->lineEdit_3->clear();
}

void QtClient::OnClientResponce(QString responce)
{
	ui->textBrowser->append(responce);
}
