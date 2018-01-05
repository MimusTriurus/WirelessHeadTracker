#include "DataTransmitter.h"


DataTransmitter::DataTransmitter( QString host, quint16 port, QObject *parent ) :
    QObject{ parent },
    _host{ host },
    _port{ port }
{
    connect( &_socket, SIGNAL( error( QAbstractSocket::SocketError ) ),
             this, SLOT( onError( QAbstractSocket::SocketError ) ) );
}

void DataTransmitter::host( const QString &host ) {
    _host = host;
}

void DataTransmitter::port( const quint16 port ) {
    _port = port;
}

void DataTransmitter::sendFrameData( const QByteArray &data ) {
    _socket.writeDatagram( data , _host, _port );
}

void DataTransmitter::onError( QAbstractSocket::SocketError errorMessage ) {
    QString strError =
        "Error: " + ( errorMessage == QAbstractSocket::HostNotFoundError ?
                     "The host was not found." :
                     errorMessage == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed." :
                     errorMessage == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused." :
                     QString( _socket.errorString( ) )
                    );
    qDebug( ) << "error:" << strError;
}
