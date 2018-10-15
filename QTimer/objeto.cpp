#include "objeto.h"
#include <QTimer>
#include <QDebug>

Objeto::Objeto(QObject *parent) : QObject(parent)
{
    m_timer= new QTimer(this);
    connect(m_timer, SIGNAL(timeout()),
            this, SLOT(onTimeout()) );
}

void Objeto::inicia()
{
    m_timer->start(50); // 50 ms
}

void Objeto::onTimeout()
{
    qDebug() << "El tiempo ha terminado..."; // cada 50ms
}
