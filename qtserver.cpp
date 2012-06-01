#include "qtserver.h"
#include "ui_qtserver.h"

qtserver::qtserver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qtserver)
{
    ui->setupUi(this);

    m_pServer = new cQServer;
}

qtserver::~qtserver()
{
    delete ui;
}

void qtserver::on_StartServer_clicked()
{
    QString message;
    int nTcpPort = ui->lineEdit->text().toInt();
    if (nTcpPort == 0)
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

    m_pServer->StartServer(nTcpPort);
    ui->textBrowser->setText(message);
}
