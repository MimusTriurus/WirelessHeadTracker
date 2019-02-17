#include "UdpSocketDataProvider.h"
#include <QDebug>

void UdpSocketDataProvider::start( ) {
    _server.bind( QHostAddress::Any, _port );
}

void UdpSocketDataProvider::stop( ) {
    _server.close( );
}

bool UdpSocketDataProvider::isDataAvailable( ) const {
    return _server.hasPendingDatagrams( );
}

QByteArray UdpSocketDataProvider::data( ) {
    QByteArray datagram;
    datagram.resize( _server.pendingDatagramSize( ) );
    QHostAddress address;
    _server.readDatagram( datagram.data( ), datagram.size( ), &address );
    return datagram;
}

UdpSocketDataProvider::UdpSocketDataProvider( ) :
    DEFAULT_PORT{ 10001 },
    _port{ DEFAULT_PORT }
{

}

void UdpSocketDataProvider::setSettings( const QString &settingsDest ) {
    Q_UNUSED( settingsDest )
}
