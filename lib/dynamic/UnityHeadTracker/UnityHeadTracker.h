#ifndef UNITYHEADTRACKER_H
#define UNITYHEADTRACKER_H

#include <QtGlobal>

#if defined( Q_CC_MSVC )
#define FUNCTION_EXPORT __declspec( dllexport )
#else
#define FUNCTION_EXPORT
#endif

namespace UnityHeadTracker {
    extern "C" {
        FUNCTION_EXPORT void setSettings( const char *filePath );
        FUNCTION_EXPORT void start( );
        FUNCTION_EXPORT void stop( );

        FUNCTION_EXPORT float scalar( );
        FUNCTION_EXPORT float x( );
        FUNCTION_EXPORT float y( );
        FUNCTION_EXPORT float z( );

        FUNCTION_EXPORT void setLogCallback( void ( *func )( const char *value ) );
    }
}

#endif // UNITYHEADTRACKER_H
