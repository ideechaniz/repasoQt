#include "mibiblioteca.h"
#include <QtDebug>

MiBiblioteca::MiBiblioteca()
{
}

void MiBiblioteca::saluda() const
{
    qDebug() << "hola desde una biblioteca estatica";
}
