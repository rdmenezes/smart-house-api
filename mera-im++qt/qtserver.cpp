#include "qtserver.h"
qtserver* qtserver::m_pSelf = 0;
qtserver::qtserver(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
	QIntValidator* validator = new QIntValidator(1,65545,ui.lineEdit);
	ui.lineEdit->setValidator(validator);
	m_pSelf = this;
	cUISignalManager::Initialize();
	connect ( this, SIGNAL (OnEventFromUI()),cUISignalManager::Instance(),SLOT(OnEventFromUI()));
	connect ( cUISignalManager::Instance(), SIGNAL (StartServerResponce(QString)),m_pSelf,SLOT(OnStartServerResponce(QString)));
}

qtserver::~qtserver()
{
}

qtserver* qtserver::Instance()
{
	return m_pSelf;
}
void qtserver::OnMessage(cEvent* even)
{
//////
}
void qtserver::on_StartServer_clicked()
{
	QString message;
	cEvent *event = new cEvent;
	int nTcpPort = ui.lineEdit->text().toInt();
	if (nTcpPort == 0)
	{
		message = "Invalid port. Enter port between 1 and 65545";
		if (ui.textBrowser->toPlainText() == message)
		{
			ui.textBrowser->setTextColor(Qt::red);
			ui.textBrowser->setText(message);
		}
		else
		{
			ui.textBrowser->setTextColor(Qt::black);
			ui.textBrowser->setText(message);
		}
		return;
	}
	event->m_eAction = Start;
	event->m_eDestination = Server;
	event->m_nPort = nTcpPort;
	cUISignalManager::Instance()->Put(event);
	ui.textBrowser->setText(message);
}

void qtserver::OnStartServerResponce(QString responce)
{
	ui.textBrowser->setText(ui.textBrowser->toPlainText()+responce);
}