#include <QtGui/QApplication>
#include "qtserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtserver w;
    w.show();
    
    return a.exec();
}
