#include <QCoreApplication>
#include <QDebug>

class Persona: public QObject
{
public:
    Persona(QObject *padre= NULL)
        :QObject(padre)
    {

    }
    void setNombre(QString nombre)
    {
        m_nombre= nombre;
    }
    void setEdad(int edad)
    {
        m_edad= edad;
    }
    void setSalario(double salario)
    {
        m_salario= salario;
    }

    QString getNombre() const
    {
        return m_nombre;
    }
    int getEdad() const
    {
        return m_edad;
    }
    double getSalariio() const
    {
        return m_salario;
    }
    ~Persona()
    {
        qDebug() << m_nombre << "se ha eliminado";
    }
    friend inline QDebug &operator<<(QDebug qd, const Persona &p);
private:
    QString m_nombre;
    int m_edad;
    double m_salario;
};

inline QDebug &operator <<(QDebug qd, const Persona &p)
{
    return qd << p.m_nombre << ' ' << p.m_edad << ' ' << p.m_salario;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Persona *juan = new Persona;
    Persona *pedro = new Persona(juan); // el padre es juan.
    Persona *luis = new Persona(juan);

    juan->setNombre("Juan");
    juan->setEdad(40);
    juan->setSalario(5000.0);

    pedro->setNombre("Pedrito");
    pedro->setEdad(13);
    pedro->setSalario(0.0);

    luis->setNombre("Luisito");
    luis->setEdad(15);
    luis->setSalario(0.0);

    qDebug() << *juan;
    qDebug() << *pedro;
    qDebug() << *luis;

    delete juan; // La clase QObject elimina a los hijos y eliminas al padre automaticamente.

    return a.exec();
}
