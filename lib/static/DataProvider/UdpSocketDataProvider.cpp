#include "UdpSocketDataProvider.h"
#include <QDebug>

UdpSocketDataProvider::UdpSocketDataProvider( QObject *parent ) : IDataProvider{ parent } {
    connect( &_server, &QUdpSocket::readyRead, this, &UdpSocketDataProvider::onReceiveData );
}

void UdpSocketDataProvider::SetSettings( const char *settingsDest ) {
    Q_UNUSED( settingsDest )
    _server.bind( QHostAddress::Any, DEFAULT_PORT );
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
