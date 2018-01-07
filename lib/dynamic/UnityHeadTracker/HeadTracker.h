#ifndef HEADTRACKER_H
#define HEADTRACKER_H

#include <QThread>
#include <IDataProvider.h>

class HeadTracker : public QThread {
    Q_OBJECT
public:
    explicit HeadTracker( QObject *parent = nullptr );
    ~HeadTracker( );
    float scalar( ) const;
    float x( ) const;
    float y( ) const;
    float z( ) const;
    void setSettings( const char *filePath );

    void ( *logMessage )( const char *value );

    void run( ) override;
private:
    float _scalar{ 1 };
    float _x{ 0 };
    float _y{ 0 };
    float _z{ 0 };

    QString _settingsFilePath;

    void log( QString mess );
private slots:
    void onReceiveData( const QByteArray &data );
};

#endif // HEADTRACKER_H
