#include <QtGui/QApplication>
#include "QtClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtClient w;
    w.show();
    
    return a.exec();
}
