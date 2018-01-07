#include "UnityHeadTracker.h"
#include "HeadTracker.h"

#include <QThread>

namespace UnityHeadTracker {

static HeadTracker _headTracker;

float scalar( ) {
    return _headTracker.scalar( );
}

float x( ) {
    return _headTracker.x( );
}

float y( ) {
    return _headTracker.y( );
}

float z( ) {
    return _headTracker.z( );
}


void setSettings( const char *filePath ) {
    _headTracker.setSettings( filePath );
    _headTracker.run( );
}

void setLogCallback( void ( *func )( const char * ) ) {
    _headTracker.logMessage = func;
}

}

