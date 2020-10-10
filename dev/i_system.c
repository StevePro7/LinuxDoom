
#ifdef __GNUG__
#pragma implementation "i_system.h"
#endif
#include "i_system.h"

#include <stdio.h>
#include <stdlib.h>

//
// I_Error
//
extern boolean demorecording;

int	mb_used = 6;

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


//
// I_GetTime
// returns time in 1/70th second tics
//
int  I_GetTime( void )
{
	// TODO
	//struct timeval	tp;
	//struct timezone	tzp;
	int			newtics;
	//static int		basetime = 0;

	//gettimeofday( &tp, &tzp );
	//if( !basetime )
	//	basetime = tp.tv_sec;
	//newtics = ( tp.tv_sec - basetime )*TICRATE + tp.tv_usec*TICRATE / 1000000;

	newtics = 0;
	return newtics;
}



byte* I_ZoneBase( int*	size )
{
	*size = mb_used * 1024 * 1024;
	return ( byte * ) malloc( *size );
}


// TODO
byte* I_AllocLow( int length )
{
	return NULL;
}


void I_WaitVBL( int count )
{
#ifdef SGI
	sginap( 1 );
#else
#ifdef SUN
	sleep( 0 );
#else
	// TODO
	//usleep( count * ( 1000000 / 70 ) );
#endif
#endif
}

void I_BeginRead( void )
{
}

void I_EndRead( void )
{
}