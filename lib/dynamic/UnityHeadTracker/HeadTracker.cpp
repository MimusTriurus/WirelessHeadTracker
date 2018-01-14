#include "HeadTracker.h"
#include <QDebug>
#include <QQuaternion>
#include <Converter.h>
#include <UdpSocketDataProvider.h>

HeadTracker::HeadTracker( QObject *parent ) : QThread( parent ) {
    this->log( "Create HeadTracker" );

}

void HeadTracker::dataProviderType( const int type ) {
    _dataProviderType = getType( type );
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
    auto dataProvider = makeDataProvider( );
    if ( dataProvider ) {
        dataProvider->setSettings( _settingsFilePath );
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

IDataProvider *HeadTracker::makeDataProvider( ) {
    switch ( _dataProviderType ) {
    case Type::ViaUdp:
        return new UdpSocketDataProvider( );
        break;
    case Type::ViaSerialPort:
        log( "Serial port data provider unsupported yet" );
        return nullptr;
        break;
    case Type::ViaQSensors:
        log( "QSensors data provider unsupported yet" );
        return nullptr;
        break;
    case Type::ViaRtimu:
        log( "Rtimu data provider unsupported yet" );
        return nullptr;
        break;
    default:
        log( "unsupported data provider type!" );
        return nullptr;
        break;
    }
}

HeadTracker::Type HeadTracker::getType( const int i ) {
    Type t = static_cast<Type>( i );
    if ( t == nullptr ) {
        return Type::None;
    }
    return t;
}
