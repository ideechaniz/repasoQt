#ifndef OBJETO_H
#define OBJETO_H

#include <QObject>

class QTimer; // solo es una referencia a la clase que ya existe

class Objeto : public QObject
{
    Q_OBJECT
public:
    explicit Objeto(QObject *parent = nullptr);
    void inicia();
public slots:
    void onTimeout(); // tiempo acabado
private:
    QTimer *m_timer; // se pueden crear punteros a la referencia.
};

#endif // OBJETO_H
