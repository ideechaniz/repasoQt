#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>

class Persona
{
public:
    Persona(const QString &nombre, int edad, double salario)
        :m_nombre(nombre), m_edad(edad), m_salario(salario)
    {

    }
    Persona(){}
    friend inline QDataStream &operator<<(QDataStream &ds, const Persona &p);
    friend inline QDataStream &operator>>(QDataStream &ds, Persona &p);
    friend inline QDebug operator<<(QDebug qd, const Persona &p);

private:
    QString m_nombre;
    int m_edad;
    double m_salario;

};

inline QDataStream &operator<<(QDataStream &ds, const Persona &p)
{
    return ds << p.m_nombre << p.m_edad << p.m_salario;
}
inline QDataStream &operator>>(QDataStream &ds, Persona &p)
{
    return ds >> p.m_nombre << p.m_edad << p.m_salario;
}

inline QDebug operator<<(QDebug qd, const Persona &p)
{
    return qd << p.m_nombre << p.m_edad << p.m_salario;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDataStream io;
    QFile arch;

    arch.setFileName("/home/noise/objeto.txt");
    arch.open(QIODevice::WriteOnly); // no le digo que es de texto
    io.setDevice(&arch);
    io.setVersion(QDataStream::Qt_5_0); // no hay porque ponerlo pero ayuda a mantener el codigo
                                        // porque el formato binario puede cambiar de version a version.

    io << 5;

    arch.flush();
    arch.close();
    qDebug() << "Listo .... mira con xxd ~/objeto.txt";

    // Ahora lo leo:
    arch.open(QIODevice::ReadWrite); // no le digo que es de texto
    io.setDevice(&arch);
    int n;
    io >> n;
    arch.flush();    
    arch.close();
    qDebug () << n;

    // Ahora con una clase en vez de un entero:

    Persona persona("juan",28,5000.0);
    qDebug() << "Hola " << persona;


    arch.setFileName("/home/noise/persona.txt");
    arch.open(QIODevice::WriteOnly); // no le digo que es de texto
    //arch.open(QIODevice::ReadWrite);
    io.setDevice(&arch);
    io << persona;
    arch.flush();
    arch.close();


    Persona personaleida;
    arch.open(QIODevice::ReadOnly);
    io.setDevice(&arch);
    io >> personaleida;
    arch.close();


    qDebug() << personaleida;

    // Este programa no funciona como deberia, no lee lo que he escrito.
    // puede ser por algo de que guarde algun puntero o algo
    // Pregunta porque esto no va.
    return a.exec();
}
