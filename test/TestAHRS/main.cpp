#include <QCoreApplication>
#include <QDebug>
#include <MahonyAHRS/MahonyAHRS.h>

int main( int argc, char *argv[ ] )
{
    QCoreApplication a(argc, argv);

    MahonyFilter::MahonyAHRSupdateIMU( 20, 10, 5, 20, 10, 5 );
    qDebug( ) << MahonyFilter::q0 << MahonyFilter::q1 << MahonyFilter::q2 << MahonyFilter::q3;

    return a.exec();
}
