#include "getdomainip.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GetDomainIP w;
    w.show();
    return QApplication::exec();
}
