#include "UdpSocketDataProvider.h"
#include <QDebug>

UdpSocketDataProvider::UdpSocketDataProvider( QObject *parent ) : IDataProvider{ parent } {
    connect( &_server, &QUdpSocket::readyRead, this, &UdpSocketDataProvider::onReceiveData );
}

void UdpSocketDataProvider::run( ) {
    _server.bind( QHostAddress::Any, _port );
}

void UdpSocketDataProvider::setSettings( const char *settingsDest ) {
    Q_UNUSED( settingsDest )
}

void UdpSocketDataProvider::onReceiveData( ) {
    while ( _server.hasPendingDatagrams( ) ) {
        QByteArray datagram;
        datagram.resize( _server.pendingDatagramSize( ) );
        QHostAddress address;
        _server.readDatagram( datagram.data( ), datagram.size( ), &address );
        emit this->getData( datagram );
    }
}
