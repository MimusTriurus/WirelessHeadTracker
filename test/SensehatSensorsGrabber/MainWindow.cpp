#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QQuaternion>
#include <QDebug>
#include <MahonyAHRS/MahonyAHRS.h>

MainWindow::MainWindow( QWidget *parent ) :
    QMainWindow( parent ),
    ui( new Ui::MainWindow )
{
    ui->setupUi( this );
    connect( &_getter,
             SIGNAL( orientationChanged( float, float, float, float, float, float ) ),
             this,
             SLOT( onGetSensorsData( float, float, float, float, float, float ) ) );

}

MainWindow::~MainWindow( ) {
    delete ui;
}

void MainWindow::onGetSensorsData(  float xG, float yG, float zG, float xA, float yA, float zA ) {
    /*
    qDebug( ) << "xG:" << xG << "yG:" << yG << "zG:" << zG;
    qDebug( ) << "xA:" << xA << "yA:" << yA << "zA:" << zA;
    qDebug( ) << "****************************************";
    */
    MahonyFilter::MahonyAHRSupdateIMU( xG, yG, zG, xA, yA, zA );
    QQuaternion q( MahonyFilter::q0, MahonyFilter::q1, MahonyFilter::q2, MahonyFilter::q3 );
    //qDebug( ) << q;
    //qDebug( ) << "*************************";
    _transmitter.sendFrameData( Converter::convertToByteArray<QQuaternion>( q ) );
}
