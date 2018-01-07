#include "HeadTracker.h"
#include <QDebug>
#include <QQuaternion>
#include <Converter.h>
#include <UdpSocketDataProvider.h>

HeadTracker::HeadTracker( QObject *parent ) : QThread( parent ) {
    this->log( "Create HeadTracker" );
}

HeadTracker::~HeadTracker( ) {
    this->log( "Destroy HeadTracker" );
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
    this->log( "set settings" );
    this->log( filePath );
    _settingsFilePath = filePath;
}

void HeadTracker::run( ) {
    auto dataProvider = new UdpSocketDataProvider( this );
    QObject::connect( dataProvider, SIGNAL( getData( QByteArray ) ),
             this, SLOT( onReceiveData( QByteArray ) ) );
    dataProvider->setSettings( _settingsFilePath.toUtf8( ) );
    dataProvider->run( );
}

void HeadTracker::log( QString mess ) {
    if ( logMessage != nullptr )
        logMessage( mess.toUtf8( ) );
    qDebug( ) << mess;
}

void HeadTracker::onReceiveData( const QByteArray &data ) {
    auto rotation = Converter::deserialize<QQuaternion>( data );
    _scalar = rotation.scalar( );
    _x = rotation.x( );
    _y = rotation.y( );
    _z = rotation.z( );
}
