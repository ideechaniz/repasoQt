#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream io;
    QFile arch;
    QString contenido;

    arch.setFileName(":/main.cpp"); // con el : entro a resources.
    arch.open(QIODevice::Text |QIODevice::ReadOnly);
    io.setDevice(&arch);

    contenido= io.readAll();
    arch.close();
    qDebug().noquote()  << contenido;


    return a.exec();
}
