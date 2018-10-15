#include <QCoreApplication>
#include "persona.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QObject *p = new QObject; // objeto principal, el padre.
    Persona *juan = new Persona(p); // las hacemos hijas de p para liberar memoria facil luego
    Persona *pedro= new Persona(p);

    QObject::connect(juan, SIGNAL(hablo(QString)),
                     pedro,SLOT(escucha(QString)));

    juan->setNombre("Juanito");
    pedro->setNombre("Pedrito");
    juan->habla("Hola Pedro");

    QObject::connect(pedro, SIGNAL(hablo(QString)),
                     juan,  SLOT(escucha(QString)));

    pedro->habla("Hola como estas?");
    juan->habla("bien gracias");
    pedro->habla("yo tambien");

    delete p; // asi liberando p libero tambien a pedro y juan.
    return a.exec();
}
