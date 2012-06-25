#include "qtserver.h"
#include "ui_qtserver.h"

qtserver::qtserver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qtserver)
{
    ui->setupUi(this);
	m_eServerState = Stopped;
    m_pServer = cQServer::Instance();
    connect (ui->actionExit,SIGNAL(activated()),this, SLOT(OnExit()));
	connect (m_pServer, SIGNAL (ServerMessage(QString)),this, SLOT (OnServerMessage(QString)));

    QIntValidator* validator = new QIntValidator(1,65545,ui->lineEdit);
    ui->lineEdit->setValidator(validator);
}

qtserver::~qtserver()
{
    delete ui;
}

void qtserver::on_StartServer_clicked()
{
	if (m_eServerState == Stopped)
	{
		QString message;
		int nTcpPort = ui->lineEdit->text().toInt();
		if (nTcpPort <= 0 || nTcpPort > 65545)
		{
			message = "Invalid port. Enter port between 1 and 65545";
			if (ui->textBrowser->toPlainText() == message)
			{
				ui->textBrowser->setTextColor(Qt::red);
				ui->textBrowser->setText(message);
			}
			else
			{
				ui->textBrowser->setTextColor(Qt::black);
				ui->textBrowser->setText(message);
			}
			return;
		}


		if (m_pServer->Start(nTcpPort))
		{
			//ui->StartServer->setDisabled(true);

			ui->StartServer->setText("Stop");
			m_eServerState = Started;
		}
	}

	else if (m_eServerState == Started)
	{
		if (m_pServer->Stop())
		{
			ui->StartServer->setText("Start");
			m_eServerState = Stopped;
		}
	}

}

void qtserver::OnExit()
{
    QApplication::instance()->quit();
}

void qtserver::OnServerMessage(QString message)
{
	QString prev = ui->textBrowser->toPlainText();
    ui->textBrowser->setPlainText(prev + message);
}

