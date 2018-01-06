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
signals:
private:
    QTimer         _tmrUpdate;
    int            _pollInterval { 0 };
    bool           _imuInited    { false };
    RTIMUSettings *_settings     { nullptr };
    RTIMU         *_rtimu        { nullptr };

    void getSensorsData( );
    void report( const RTIMU_DATA &data );
};

#endif // HEADTRACKER_H
