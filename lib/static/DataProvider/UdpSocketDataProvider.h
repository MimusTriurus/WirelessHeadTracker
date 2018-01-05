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
    void SetSettings( const char *settingsDest );
private:
    const int DEFAULT_PORT{ 10001 };

    QUdpSocket _server;
private slots:
    void onReceiveData( );
};

#endif // UDPSOCKETDATAPROVIDER_H
