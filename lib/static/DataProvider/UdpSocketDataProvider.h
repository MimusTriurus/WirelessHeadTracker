#ifndef UDPSOCKETDATAPROVIDER_H
#define UDPSOCKETDATAPROVIDER_H

#include <QObject>
#include <QUdpSocket>
#include "IDataProvider.h"

class UdpSocketDataProvider : public IDataProvider {
public:
    UdpSocketDataProvider( );

    void setSettings( const QString &settingsDest ) override;

    void start( ) override;
    void stop( ) override;

    bool isDataAvailable( ) const override;
    QByteArray data( ) override;
private:
    const quint16 DEFAULT_PORT;
    quint16 _port;
    QUdpSocket _server;
};

#endif // UDPSOCKETDATAPROVIDER_H
