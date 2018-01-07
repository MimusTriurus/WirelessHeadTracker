#include "UnityHeadTracker.h"
#include "HeadTracker.h"

#include <QThread>

namespace UnityHeadTracker {

static HeadTracker _headTracker;

float UnityHeadTracker::scalar( ) {
    return _headTracker.scalar( );
}

float UnityHeadTracker::x( ) {
    return _headTracker.x( );
}

float UnityHeadTracker::y( ) {
    return _headTracker.y( );
}

float UnityHeadTracker::z( ) {
    return _headTracker.z( );
}


void UnityHeadTracker::setSettings( const char *filePath ) {
    _headTracker.setSettings( filePath );
    _headTracker.run( );
}

void setLogCallback( void ( *func )( const char * ) ) {
    _headTracker.logMessage = func;
}

}

