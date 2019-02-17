#include "UnityHeadTracker.h"
#include "HeadTracker.h"
#include <QDebug>

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
}

void setLogCallback( void ( *func )( const char * ) ) {
    _headTracker.logMessage = func;
}

void start( ) {
    _headTracker.work( true );
}

void stop( ) {
    _headTracker.work( false );
}

void setDataProviderType( const int type ) {
    _headTracker.dataProviderType( type );
}

}

