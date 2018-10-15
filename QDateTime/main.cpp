#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // a manija una fecha sin mas
    QDate fecha(2018,10,15);
    QTime hora(8, 52, 0 );
    QDateTime fh1(fecha, hora); // fecha y hora
    qDebug() << fh1;

    // ahora coge la fecha del sistema
    QDateTime fh=QDateTime::currentDateTime();
    qDebug() << fh;
    qDebug() << QDate::currentDate();
    qDebug() << QTime::currentTime();


    return a.exec();
}
