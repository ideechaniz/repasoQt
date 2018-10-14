#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream io; // input y output
    QFile a;
    QString contenido;

    a.setFileName("/home/noise/doc.txt");
    a.open(QIODevice::ReadWrite | QIODevice::Text);
    if (!a.isOpen())
    {
            qDebug() << "Error: archivo no abierto";
            return 1;
    }

    io.setDevice(&a);
    contenido = io.readAll(); // lo que tuviese de antes.
    qDebug() << contenido;
    io << "Adios";    // nuevo contenido que NO borra lo anterior. Lo pone al final.
    a.flush();
    a.close();

    // Ahora otro ejemplo;
    QString S;
    QTextStream io2;
    io2.setString(&S);
    io2 << "Hola mundo " << 8 << " " << 9.45;
    qDebug() << S;

    // otro ejemplo:
    int i;
    double d;
    char c;
    S="12 4.5 #";
    io2 >> i >> d >> c;
    qDebug() << i << d << c; // por alguna razon no coge el caracter.


    return app.exec();
}
