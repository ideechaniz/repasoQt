#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile f;
    QByteArray contenido;
    f.setFileName("/home/noise/documento.txt");
    if( !f.exists()){
        qDebug() << "El archivo no existe";
        return 1;
    }

    f.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!f.isOpen()){
        qDebug() << "El archivo no se ha podido abrir";
    }

    contenido= f.readAll();
    qDebug() << contenido;
    f.close();

    contenido= "Estoy escribiendo en un archivo";

    f.open(QIODevice::WriteOnly | QIODevice::Text);
    f.write(contenido);
    f.flush();
    f.close();



    return a.exec();
}
