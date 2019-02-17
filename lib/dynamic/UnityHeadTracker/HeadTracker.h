#ifndef HEADTRACKER_H
#define HEADTRACKER_H

#include <QThread>
#include <IDataProvider.h>
#include <QMetaEnum>

class HeadTracker : public QThread {
    Q_OBJECT
public:
    explicit HeadTracker( QObject *parent = nullptr );
    void dataProviderType( const int type );

    float scalar( ) const;
    float x( ) const;
    float y( ) const;
    float z( ) const;
    void setSettings( const char *filePath );

    void ( *logMessage )( const char *value );

    void work( bool value );
    bool work( );
protected:
    void run( ) override;
private:
    float _scalar;
    float _x;
    float _y;
    float _z;

    float _sleepInterval;
    float _working;

    QString _settingsFilePath;

    void log( QString mess );
    void transformToQuaternion( const QByteArray &data );

    enum Type {
        ViaUdp,
        ViaSerialPort,
        ViaQSensors,
        ViaRtimu,
        None
    };
    Type _dataProviderType{ Type::ViaUdp };
    IDataProvider *makeDataProvider( );

    Type getType( const int i );
};

#endif // HEADTRACKER_H
