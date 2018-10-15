#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>

class Persona : public QObject
{
    Q_OBJECT
public:
    explicit Persona(QObject *parent = nullptr);
    void setNombre(const QString &nombre)
    {
        m_nombre=nombre;
    }
    void habla(const QString &palabras);

signals:
    void hablo(QString);// todas las señales son void y no se pone la variable solo el tipo.
public slots:
    void escucha(const QString &palabras); // estos son metodos normales.

private:
    QString m_nombre;
};

#endif // PERSONA_H
