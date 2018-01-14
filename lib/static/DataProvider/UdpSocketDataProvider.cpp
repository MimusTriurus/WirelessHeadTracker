#include "UdpSocketDataProvider.h"
#include <QDebug>

void UdpSocketDataProvider::start( ) {
    _server.bind( QHostAddress::Any, _port );
}

void UdpSocketDataProvider::stop( ) {
    _server.close( );
}

bool UdpSocketDataProvider::isDataAvailable( ) {
    return _server.hasPendingDatagrams( );
}

QByteArray UdpSocketDataProvider::data( ) {
    QByteArray datagram;
    datagram.resize( _server.pendingDatagramSize( ) );
    QHostAddress address;
    _server.readDatagram( datagram.data( ), datagram.size( ), &address );
    return datagram;
}

void UdpSocketDataProvider::setSettings( const char *settingsDest ) {
    Q_UNUSED( settingsDest )
}
