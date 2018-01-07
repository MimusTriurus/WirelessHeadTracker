#ifndef COMPORTDATAPROVIDER_H
#define COMPORTDATAPROVIDER_H

#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QSerialPortInfo>
#include <IDataprovider.h>

#include <QtXml>
#include <QtSerialPort/QSerialPort>
/**
 * @brief Поставщик данных для трекинга - COM порт
 */
class SerialPortDataProvider : public IDataProvider {
    Q_OBJECT
    public:
        SerialPortDataProvider( QObject *parent = nullptr );
        ~SerialPortDataProvider( );
    private slots:
        void handleReadyRead( );
        void handleTimeout( );
        void handleError( QSerialPort::SerialPortError error );
    public:
        void setSettings( const char *settingsDest ) override;
        void run( ) override;
    private:
        QSerialPort  _serialPort;
        QTimer       _timer;
        QByteArray   _readData;

        int _packetSize = 0;
        int _codeCharDelimiter = 0;

        void getSettings( QDomElement setting );
};

#endif // COMPORTDATAPROVIDER_H
