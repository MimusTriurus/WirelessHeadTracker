#ifndef HEADTRACKER_H
#define HEADTRACKER_H

#include <QThread>
#include <IDataProvider.h>

class HeadTracker : public QThread {
    Q_OBJECT
public:
    explicit HeadTracker( QObject *parent = nullptr );

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
    float _scalar{ 1 };
    float _x{ 0 };
    float _y{ 0 };
    float _z{ 0 };

    float _sleepInterval{ 0.1f };
    float _working{ false };

    QString _settingsFilePath;

    void log( QString mess );
    void transformToQuaternion( const QByteArray &data );
};

#endif // HEADTRACKER_H
