#ifndef UDPSOCKETDATAPROVIDER_H
#define UDPSOCKETDATAPROVIDER_H

#include <QObject>
#include <QUdpSocket>
#include "IDataProvider.h"

class UdpSocketDataProvider : public IDataProvider {
public:
    void setSettings( const QString &settingsDest ) override;

    void start( ) override;
    void stop( ) override;

    bool isDataAvailable( ) override;
    QByteArray data( ) override;
private:
    const quint16 DEFAULT_PORT{ 10001 };
    QUdpSocket _server;
    quint16 _port{ DEFAULT_PORT };
};

#endif // UDPSOCKETDATAPROVIDER_H
