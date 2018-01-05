#ifndef IORIENTATIONGETTER_H
#define IORIENTATIONGETTER_H

#include <QtCore>

class IOrientationGetter : public QObject {
    Q_OBJECT
public:
    virtual ~IOrientationGetter( ) { }
signals:
    /**
     * @brief положение трекера в пространсве изменилось
     * x - гироскоп
     * y - гироскоп
     * z - гироскоп
     * x - акселерометр
     * y - акселерометр
     * z - акселерометр
     */
    void orientationChanged( float, float, float, float, float, float );
protected:
    IOrientationGetter( QObject *parent = nullptr ) : QObject( parent ) { }
};

#endif // IORIENTATIONGETTER_H
