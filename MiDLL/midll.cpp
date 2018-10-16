#include "midll.h"
#include <QDebug>


MiDLL::MiDLL()
{
}

void MiDLL::saluda() const
{
    qDebug() <<"Hola desde una DLL";
}
