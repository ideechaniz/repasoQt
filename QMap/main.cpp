#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <ctime>

#define TOTAL 10000 // cuantos numeros.

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream io;
    QFile arch;
    QMap<int, int> registro; // numero y cantidad de veces presente.
    QMap<int, int>::Iterator it; // iterador
    int n, valor, suma=0;

    arch.setFileName("/home/noise/numeros.txt");
    arch.open(QIODevice::WriteOnly |QIODevice::Text);
    io.setDevice(&arch);

    qsrand(time(NULL));
    for(int i=0; i< TOTAL; i++)
        io << qrand() %10 +1 << ' ';// num entre 1 y 10 separados por espacio.
    arch.flush();
    arch.close();

    arch.open(QIODevice::ReadOnly |QIODevice::Text);
    while(!io.atEnd())
    {
        io >> n; // leer un numero.
        ++registro[n]; // un map se ve como un array pero puede no tener posiciones intermedias.
    }
    registro.erase(registro.find(0)); // al final del fichero hay un espacio y se interpreta como cero.

    for(it = registro.begin(); it!= registro.end(); it++)
    {
        valor= it.value();
        suma+=valor;
        qDebug() << it.key() << ":" << valor;
    }

    qDebug() << "Suma:" << suma;
    qDebug() << "Total:" << TOTAL;

    qDebug() << registro[1];

    return a.exec();
}
