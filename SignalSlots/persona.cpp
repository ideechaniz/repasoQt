#include "persona.h"
#include <QDebug>

Persona::Persona(QObject *parent) : QObject(parent)
{

}

void Persona::escucha(const QString &palabras)
{
    qDebug() << m_nombre << "ha escuchado:" << palabras;
}

void Persona::habla(const QString &palabras)
{
    emit hablo(palabras);
}
