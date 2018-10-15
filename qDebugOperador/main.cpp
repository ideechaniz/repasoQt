#include <QCoreApplication>
#include <QDebug>

class Persona
{
public:
    Persona(const QString &nombre, int edad)
        :m_nombre(nombre), m_edad(edad)
    {

    }
    friend inline QDebug &operator<<(QDebug qd, const Persona &p);
private:
    QString m_nombre;
    int m_edad;
};

inline QDebug &operator<<(QDebug qd, const Persona &p)
{
    return qd << p.m_nombre << " " << p.m_edad;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Persona juan("Juan", 29);
    qDebug() << juan;

    return a.exec();
}
