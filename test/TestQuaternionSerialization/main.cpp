#include <QCoreApplication>
#include <QQuaternion>
#include <QDebug>
#include <Converter.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QQuaternion q{ 0, 10, 1, 20 };
    qDebug( ) << "before:" << q;
    QByteArray qBytes{ Converter::convertToByteArray<QQuaternion>( q ) };
    qDebug( ) << "before qBytes:" << qBytes;
    QQuaternion q1{ Converter::convertFromByteArray<QQuaternion>( qBytes ) };
    qDebug( ) << "after:" << q1;
    QByteArray qBytes1{ Converter::convertToByteArray<QQuaternion>( q1 ) };
    qDebug( ) << "after qBytes:" << qBytes1;

    return a.exec();
}
