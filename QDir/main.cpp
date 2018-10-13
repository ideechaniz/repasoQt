#include <QCoreApplication>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir directorio;
    directorio.setPath("/home/noise");

    uint cantidad=directorio.count();
    for(uint i=2; i<cantidad; i++) // 0 es . y 1 es ..
        qDebug()<< directorio[i];


    return a.exec();
}
