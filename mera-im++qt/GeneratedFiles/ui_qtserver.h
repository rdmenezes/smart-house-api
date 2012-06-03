/********************************************************************************
** Form generated from reading UI file 'qtserver.ui'
**
** Created: Sun 3. Jun 14:25:24 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSERVER_H
#define UI_QTSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtserver
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *StartServer;
    QTextBrowser *textBrowser;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtserver)
    {
        if (qtserver->objectName().isEmpty())
            qtserver->setObjectName(QString::fromUtf8("qtserver"));
        qtserver->resize(400, 300);
        actionExit = new QAction(qtserver);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(qtserver);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 50, 61, 21));
        StartServer = new QPushButton(centralWidget);
        StartServer->setObjectName(QString::fromUtf8("StartServer"));
        StartServer->setGeometry(QRect(10, 80, 61, 23));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(130, 50, 256, 192));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 361, 16));
        qtserver->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qtserver);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        qtserver->setMenuBar(menuBar);
        statusBar = new QStatusBar(qtserver);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qtserver->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(qtserver);

        QMetaObject::connectSlotsByName(qtserver);
    } // setupUi

    void retranslateUi(QMainWindow *qtserver)
    {
        qtserver->setWindowTitle(QApplication::translate("qtserver", "qtserver", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("qtserver", "exit", 0, QApplication::UnicodeUTF8));
        StartServer->setText(QApplication::translate("qtserver", "Start", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("qtserver", "To start the server enter TCP Port number and press \"Start\" button", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("qtserver", "file", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qtserver: public Ui_qtserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSERVER_H
