#include <QCoreApplication>
#include <QVariant>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVariant  v1;
    v1.setValue<int>(5);
    qDebug() << v1;

    double x= v1.value<double>();
    qDebug() << x;

    // Ahora una lista que acepta "cualquier" cosa
    QList<QVariant> v;
    v << 3 << "hola" << 8.9;
    qDebug() << v;


    return a.exec();
}
