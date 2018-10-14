#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> L;
    L << 1 <<2 <<3 <<4 <<5;

    // con el foreach de qt
    foreach (int i, L)
        qDebug() << i;

    qDebug() << endl;

    // con C++11
    for(int i: L)
        qDebug() << i;

    // nota mira el directorio QList de mi dir de repaso para casos donde foreach no va,
    // para ver otras maneras de iterar.

    return a.exec();
}
