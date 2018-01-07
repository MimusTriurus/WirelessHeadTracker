#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QQuaternion>
#include <QDebug>
#include <AHRS.h>

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
    _transmitter.sendData( Converter::serialize<QQuaternion>( AHRS::rotation( xG, yG, zG, xA, yA, zA ) ) );
}
