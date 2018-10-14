#include <QCoreApplication>
#include <QVector>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<int> v;
    //std:vector<int> w;

    v << 1 << 2 << 8 << 9 << 10;

    qDebug() << v;

    return a.exec();
}
