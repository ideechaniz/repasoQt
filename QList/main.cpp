#include <QCoreApplication>
//#include <QList>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> L;
    // QLinkedList<int> L  esta es como la lista de c++

    L.append(1);
    L.append(2);
    L.append(3);
    L << 4 << 5 << 6 << 7 << 8;

    qDebug() << L;
    L.removeAt(2); // empieza de cero asi que quita el num 3.

    // un modo de iterar:
    QList<int>::Iterator i;
    int suma=0;
    for(i = L.begin(); i!= L.end(); i++)
    {
        suma+=*i;
    }
    qDebug() << suma;

    // otro modo de iterar sin iterador:
    for(int j=0; j< L.size(); j++)
        qDebug() << L[j];

    std::list<int> ml; // lista standard de c++
    ml=L.toStdList();
    qDebug() << ml; // antes no iba en qt pero ya si. qt 5.11.2

    qDebug() << endl;

    // otro modo:
    foreach (int i, L)
    {
        qDebug() << i;
    }
    qDebug() << endl;

    QString s="Hola,esto,son,palabras,separadas,por,coma";
    QList<QString> L1; // igual que QStringList L1;
    L1=s.split(',');
    qDebug() << L1;

    for(int j=0; j< L1.size(); j++)
        qDebug() << L1[j];

    QString k=L1.join(',');
    qDebug() << k;

    return a.exec();
}
