#ifndef UDPSOCKETDATAPROVIDER_H
#define UDPSOCKETDATAPROVIDER_H

#include <QObject>
#include <QUdpSocket>
#include "IDataProvider.h"

class UdpSocketDataProvider : public IDataProvider {
    Q_OBJECT
public:
    explicit UdpSocketDataProvider( QObject *parent = nullptr );
public:
    void setSettings( const char *settingsDest ) override;
    void run( ) override;
private:
    const quint16 DEFAULT_PORT{ 10001 };

    QUdpSocket _server;
    quint16 _port{ DEFAULT_PORT };
private slots:
    void onReceiveData( );
};

#endif // UDPSOCKETDATAPROVIDER_H
