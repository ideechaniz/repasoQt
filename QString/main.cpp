#include <QCoreApplication>
#include <QDebug>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString nombre1= "Pedro Lopez Dominguez";
    qDebug() << nombre1; // qDebug saca las cosas por pantalla con comillas dobles.

    int x = 6;
    double y = 3.1416;
    char z= '#';
    QString contenido;
    contenido = QString("%1 %2 %3").arg(x).arg(y).arg(z);
    qDebug() << contenido;

    QString qs= "Original de Qt";
    qDebug() << qs;
    string qs_std= qs.toStdString(); // qDebug no acepta string de c++
    qDebug() << qs_std.c_str(); // qDebug aceptar char arrays pero no le pone comillas cuando viene de string

    string s = "Original del lenguaje C++"; // tradicional de c++ std
    QString qs2=s.c_str(); // directamente no se puede hay que hacerlo asi.
    qDebug() << qs2; // si le pone comillas cuando viene de QString


    bool estaono=nombre1.contains("Pedro");
    qDebug() << estaono;
    estaono = nombre1.startsWith("Ped");
    qDebug() << estaono;

    int indice = nombre1.indexOf('D'); // empezando de cero esta en el 12.
    qDebug() << indice;

    return a.exec();
}
