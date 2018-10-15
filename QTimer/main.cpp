#include <QCoreApplication>
#include "objeto.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Objeto obj;
    obj.inicia();


    return a.exec();
}
