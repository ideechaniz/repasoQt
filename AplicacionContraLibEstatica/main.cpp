#include <QCoreApplication>
#include <mibiblioteca.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MiBiblioteca mBib;
    mBib.saluda();

    return a.exec();
}
