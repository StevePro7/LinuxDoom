
#ifdef __GNUG__
#pragma implementation "i_system.h"
#endif
#include "i_system.h"

#include <stdio.h>
//
// I_Error
//
extern boolean demorecording;

void I_Error( char *error, ... )
{
	//va_list	argptr;

	//// Message first.
	//va_start( argptr, error );
	//fprintf( stderr, "Error: " );
	//vfprintf( stderr, error, argptr );
	//fprintf( stderr, "\n" );
	//va_end( argptr );

	//fflush( stderr );

	//// Shutdown. Here might be other errors.
	//if( demorecording )
	//	G_CheckDemoStatus();

	//D_QuitNetGame();
	//I_ShutdownGraphics();

	//exit( -1 );
}
