#include <QCoreApplication>
#include <UnityHeadTracker.h>
#include <QDebug>
#include <QTimer>

int main( int argc, char *argv[ ] ) {
    QCoreApplication a( argc, argv );

    UnityHeadTracker::setSettings( "" );
    UnityHeadTracker::start( );
    QTimer _tmr;
    _tmr.setInterval( 1000 );
    QObject::connect( &_tmr, &QTimer::timeout, [ ]( ){
        qDebug( ) << "s:" << UnityHeadTracker::scalar( );
        qDebug( ) << "x:" << UnityHeadTracker::x( );
        qDebug( ) << "y:" << UnityHeadTracker::y( );
        qDebug( ) << "z:" << UnityHeadTracker::z( );
        qDebug( ) << "*********************************";
    } );
    _tmr.start( );

    return a.exec( );
}
