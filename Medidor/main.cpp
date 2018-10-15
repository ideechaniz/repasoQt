#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
#include <QTime>
#include <QFile>
#include <QTextStream>

// Mide el tiempo de ejecucion de otro programa.
int main(int argc, char *argv[])
{
    if(argc == 1) {
        qDebug() << QString("Use '%1' programa.exe fichero.txt").arg(argv[0]);
        return 1; // ej Medidor leafpad resultado.txt
    }
    int res; // resultado
    QTime inicio;
    QFile arch;
    QTextStream io;
    QProcess proc; // proceso
    QString programa = argv[1];
    QString resultado= argv[2];

    QCoreApplication a(argc, argv);
    inicio = QTime::currentTime();
    proc.start(programa);
    proc.waitForFinished();
    res=inicio.msecsTo(QTime::currentTime());

    arch.setFileName(resultado);
    arch.open(QIODevice::WriteOnly |QIODevice::Text);
    io.setDevice(&arch);
    io << "El programa " << programa <<" ha tardado "<< res << " milisegundos\n";
    arch.flush();
    arch.close();
    qDebug() << " Listo .... CTRL+C y cat "<< resultado;


    return a.exec();
}
