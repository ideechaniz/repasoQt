#include <QCoreApplication>
#include <QDebug>
#include <QPointer>

class Persona : public QObject
{
public:
    Persona (const QString nombre, QObject *padre=0)
        :QObject(padre)
    {
        m_nombre=nombre;
    }
    QString nombre() const
    {
        return m_nombre;
    }
private:
    QString m_nombre;

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int *ptr= new int(5);
    qDebug() << *ptr;
    delete ptr;

    qDebug() << *ptr;
    ptr= NULL; // en puntero normal hay que ponerlo a null a mano.


    // int char, double float, bool , short long ... no se permiten en QPointer
    // tiene que ser una clase que herede de QObject
    QPointer<Persona> ptr2 = new Persona("Juan");
    qDebug() << ptr2->nombre();
    delete ptr2;

    qDebug() << (ptr2 == NULL);
    // el delete del QPointer automaticamente lo deja a NULL
    return a.exec();
}
