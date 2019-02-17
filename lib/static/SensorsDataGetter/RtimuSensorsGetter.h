#ifndef HEADTRACKER_H
#define HEADTRACKER_H

#include <QtCore>
#include <QTimer>
#include <QDebug>
#include <QStandardPaths>
#include <QFile>
#include <QByteArray>

#include "IOrientationGetter.h"
#include "RTIMULib.h"

class RtimuSensorsGetter : public IOrientationGetter {
    Q_OBJECT
public:
    RtimuSensorsGetter( QObject *parent = nullptr );
    ~RtimuSensorsGetter( );
private:
    QTimer        _tmrUpdate;
    int           _pollInterval;
    bool          _imuInited;
    RTIMUSettings *_settings;
    RTIMU         *_rtimu;

    void getSensorsData( );
    void report( const RTIMU_DATA &data );
};

#endif // HEADTRACKER_H
