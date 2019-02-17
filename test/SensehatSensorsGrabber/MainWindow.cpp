#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QQuaternion>
#include <QDebug>
#include <AHRS.h>
#include <QCommandLineParser>
#include <QCommandLineOption>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );

    // читаем настройки из командной строки
    QCommandLineParser parser;
    parser.addHelpOption( );
    const QString HOST_ID{ "host" };
    const QString PORT_ID{ "port" };
    QCommandLineOption hostOption( HOST_ID, "Data receiver host", "127.0.0.1", "127.0.0.1" );
    parser.addOption( hostOption );
    QCommandLineOption portOption( PORT_ID, "Data receiver port", "10001", "10001" );
    parser.addOption( portOption );
    parser.process( qApp->arguments( ) );
    QString  host { parser.value( HOST_ID ) };
    QVariant vPort{ parser.value( PORT_ID ) };
    quint16 port = ( vPort.canConvert<quint16>( ) ) ? vPort.value<quint16>( ) : 10001;
    qDebug( ) << "set host:" << host << port;
    this->setWindowTitle( "Send data to host:" + host + " port:" +QString::number( port ) );
    _transmitter.host( host );
    _transmitter.port( port );

    connect( &_getter,
             SIGNAL( orientationChanged( float, float, float, float, float, float ) ),
             this,
             SLOT( onGetSensorsData( float, float, float, float, float, float ) ) );
}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::onGetSensorsData(  float xG, float yG, float zG, float xA, float yA, float zA ) {
    //qDebug( ) << xG << yG << zG << xA << yA << zA;
    _transmitter.sendData( Converter::serialize<QQuaternion>( AHRS::rotation( xG, yG, zG, xA, yA, zA ) ) );
}
