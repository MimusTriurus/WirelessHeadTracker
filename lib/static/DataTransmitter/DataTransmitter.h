#ifndef DATATRANSMITTER_H
#define DATATRANSMITTER_H

#include <QtCore>
#include <QUdpSocket>

class DataTransmitter : public QObject {
    Q_OBJECT
public:
    DataTransmitter( QString host = "localhost", quint16 port = 10000, QObject *parent = nullptr );
    void host( const QString &host );
    void port( const quint16 port );
public slots:
    void sendData( const QByteArray &data );
private:
    QUdpSocket      _socket;
    QHostAddress    _host;
    quint16         _port;
private slots:
    void onError( QAbstractSocket::SocketError errorMessage );
};

#endif // DATATRANSMITTER_H
