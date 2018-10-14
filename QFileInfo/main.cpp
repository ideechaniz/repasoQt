#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFileInfo finfo;
    finfo.setFile("/home/noise/documento.txt");
    qDebug() << finfo.exists();
    qDebug() << finfo.isFile();
    qDebug() << finfo.isNativePath(); // barras / o \


    qDebug() << finfo.fileName();
    qDebug() << finfo.filePath();
    qDebug() << finfo.size() << " bytes";
    qDebug() << finfo.suffix();


    return a.exec();
}
