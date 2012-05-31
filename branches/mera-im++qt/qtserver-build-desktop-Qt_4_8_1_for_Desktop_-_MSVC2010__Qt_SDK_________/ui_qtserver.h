/********************************************************************************
** Form generated from reading UI file 'qtserver.ui'
**
** Created: Mon 28. May 17:43:15 2012
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
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtserverClass
{
public:
    QPushButton *StartServer;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *qtserverClass)
    {
        if (qtserverClass->objectName().isEmpty())
            qtserverClass->setObjectName(QString::fromUtf8("qtserverClass"));
        qtserverClass->resize(430, 242);
        StartServer = new QPushButton(qtserverClass);
        StartServer->setObjectName(QString::fromUtf8("StartServer"));
        StartServer->setGeometry(QRect(10, 80, 81, 31));
        lineEdit = new QLineEdit(qtserverClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 50, 81, 20));
        lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);
        label = new QLabel(qtserverClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 191, 41));
        textBrowser = new QTextBrowser(qtserverClass);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(195, 30, 221, 192));

        retranslateUi(qtserverClass);

        QMetaObject::connectSlotsByName(qtserverClass);
    } // setupUi

    void retranslateUi(QWidget *qtserverClass)
    {
        qtserverClass->setWindowTitle(QApplication::translate("qtserverClass", "qtserver", 0, QApplication::UnicodeUTF8));
        StartServer->setText(QApplication::translate("qtserverClass", "Start Server", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("qtserverClass", "To run the server enter tcp port below\n"
"and press \"Start Server\"", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qtserverClass: public Ui_qtserverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSERVER_H
