#include "RtimuSensorsGetter.h"

void RtimuSensorsGetter::getSensorsData( ) {

    if ( !_imuInited ) {
        _imuInited = true;
        if ( !_rtimu->IMUInit( ) )
            qWarning( "Failed to initialize IMU" );
    }
    int attempts = 5;
    while ( attempts-- ) {
        if ( _rtimu->IMURead( ) )
            break;
        usleep( _pollInterval * 1000 );
    }
    if ( attempts >= 0 ) {
        RTIMU_DATA data = _rtimu->getIMUData( );
        report( data );
    }
    else
        qWarning( "Failed to read intertial measurement data" );
}

RtimuSensorsGetter::RtimuSensorsGetter( QObject *parent ) : IOrientationGetter( parent ) {
    const QString writableConfigDir = QStandardPaths::writableLocation( QStandardPaths::GenericConfigLocation ) + QStringLiteral( "/sense_hat" );

    QByteArray dirName = writableConfigDir.toUtf8( );
    _settings = new RTIMUSettings( dirName.constData( ), "RTIMULib");

    _rtimu = RTIMU::createIMU( _settings );
    _pollInterval = qMax( 1, _rtimu->IMUGetPollInterval( ) );
    qDebug( ) << "IMU name " << _rtimu->IMUName( ) << "Recommended poll interval " << _pollInterval << " ms";

     _tmrUpdate.setInterval( _pollInterval );
     connect( &_tmrUpdate, &QTimer::timeout, [ this ] { this->getSensorsData( ); } );
     _tmrUpdate.start( );
}

RtimuSensorsGetter::~RtimuSensorsGetter( ) {
    delete _settings;
    delete _rtimu;
}

void RtimuSensorsGetter::report( const RTIMU_DATA &data ) {
    emit orientationChanged( data.gyro.x( ), data.gyro.y( ), data.gyro.z( ), data.accel.x( ), data.accel.y( ), data.accel.z( ) );
}
