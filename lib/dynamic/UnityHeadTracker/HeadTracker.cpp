#include "HeadTracker.h"
#include <QDebug>
#include <QQuaternion>
#include <Converter.h>
#include <UdpSocketDataProvider.h>

HeadTracker::HeadTracker( QObject *parent ) : QThread( parent ) {
    this->log( "Create HeadTracker" );
}

float HeadTracker::scalar( ) const {
    return _scalar;
}

float HeadTracker::x( ) const {
    return _x;
}

float HeadTracker::y( ) const {
    return _y;
}

float HeadTracker::z( ) const {
    return _z;
}

void HeadTracker::setSettings( const char *filePath ) {
    this->log( "settings file path:" + QString( filePath ) );

    _settingsFilePath = filePath;
}

void HeadTracker::work( bool value ) {
    _working = value;
    if ( !this->isRunning( ) )
        this->start( );
}

bool HeadTracker::work( ) {
    return this->isRunning( );
}

void HeadTracker::run( ) {
    auto dataProvider = new UdpSocketDataProvider( );
    dataProvider->start( );
    this->log( "run thread" );
    while ( _working ) {
        if ( dataProvider->isDataAvailable( ) ) {
            transformToQuaternion( dataProvider->data( ) );
        }
        QThread::sleep( _sleepInterval );
    }
    dataProvider->stop( );
    this->log( "stop thread" );
    delete dataProvider;
}

void HeadTracker::log( QString mess ) {
    if ( logMessage != nullptr )
        logMessage( mess.toUtf8( ) );
    qDebug( ) << mess;
}

void HeadTracker::transformToQuaternion( const QByteArray &data ) {
    auto rotation = Converter::deserialize<QQuaternion>( data );
    _scalar = rotation.scalar( );
    _x = rotation.x( );
    _y = rotation.y( );
    _z = rotation.z( );
}
