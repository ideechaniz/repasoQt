#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // a es una aplicacion
    // argc es el numero de argumentos
    // argv son los argumentos.

    qDebug() << "Hola Qt";

    return a.exec(); // a.exec genera un bucle infinito
}
