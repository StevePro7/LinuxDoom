static const char rcsid[] = "$Id: d_main.c,v 1.8 1997/02/03 22:45:09 b1 Exp $";

#define	BGCOLOR		7
#define	FGCOLOR		8


#define R_OK		1


#ifdef NORMALUNIX
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif


#include "d_main.h"
#include <stdio.h>
#include <stdlib.h>

#include "doomdef.h"
#include "doomstat.h"
//
#include "dstrings.h"
//#include "sounds.h"
//
//
//#include "z_zone.h"
//#include "w_wad.h"
//#include "s_sound.h"
//#include "v_video.h"
//
//#include "f_finale.h"
//#include "f_wipe.h"
//
#include "m_argv.h"
//#include "m_misc.h"
//#include "m_menu.h"
//
//#include "i_system.h"
//#include "i_sound.h"
//#include "i_video.h"
//
//#include "g_game.h"
//
//#include "hu_stuff.h"
//#include "wi_stuff.h"
//#include "st_stuff.h"
//#include "am_map.h"
//
//#include "p_setup.h"
//#include "r_local.h"




//
// D-DoomLoop()
// Not a globally visible function,
//  just included for source reference,
//  called by D_DoomMain, never exits.
// Manages timing and IO,
//  calls all ?_Responder, ?_Ticker, and ?_Drawer,
//  calls I_GetTime, I_StartFrame, and I_StartTic
//
void D_DoomLoop( void );


char*		wadfiles[ MAXWADFILES ];


boolean		devparm;	// started game with -devparm
boolean         nomonsters;	// checkparm of -nomonsters
boolean         respawnparm;	// checkparm of -respawn
boolean         fastparm;	// checkparm of -fast

boolean         drone;

boolean		singletics = false; // debug flag to cancel adaptiveness



								//extern int soundVolume;
								//extern  int	sfxVolume;
								//extern  int	musicVolume;

extern  boolean	inhelpscreens;

skill_t		startskill;
int             startepisode;
int		startmap;
boolean		autostart;

FILE*		debugfile;

boolean		advancedemo;




char		wadfile[ 1024 ];		// primary wad file
char		mapdir[ 1024 ];           // directory of development maps
char		basedefault[ 1024 ];      // default file


//void D_CheckNetGame( void );
//void D_ProcessEvents( void );
//void G_BuildTiccmd( ticcmd_t* cmd );
//void D_DoAdvanceDemo( void );


//
// EVENT HANDLING
//
// Events are asynchronous inputs generally generated by the game user.
// Events can be discarded if no responder claims them
//
event_t         events[ MAXEVENTS ];
int             eventhead;
int 		eventtail;



//
//  D_DoomLoop
//
extern  boolean         demorecording;

void D_DoomLoop( void )
{
}


//
// D_AddFile
//
void D_AddFile( char *file )
{
	int     numwadfiles;
	char    *newfile;

	for( numwadfiles = 0; wadfiles[ numwadfiles ]; numwadfiles++ )
		;

	newfile = malloc( strlen( file ) + 1 );
	strcpy( newfile, file );

	wadfiles[ numwadfiles ] = newfile;
}


unsigned char access( char* ptr, unsigned char test )
{
	return 1;
}

//
// IdentifyVersion
// Checks availability of IWAD files by name,
// to determine whether registered/commercial features
// should be executed (notably loading PWAD's).
//
void IdentifyVersion( void )
{
	char*	doom1wad = NULL;
	char*	doomwad = NULL;
	char*	doomuwad = NULL;
	char*	doom2wad = NULL;

	char*	doom2fwad = NULL;
	char*	plutoniawad = NULL;
	char*	tntwad = NULL;

#ifdef NORMALUNIX
	char *home;
	char *doomwaddir;
	doomwaddir = getenv( "DOOMWADDIR" );
	if( !doomwaddir )
		doomwaddir = ".";

	// Commercial.
	doom2wad = malloc( strlen( doomwaddir ) + 1 + 9 + 1 );
	sprintf( doom2wad, "%s/doom2.wad", doomwaddir );

	// Retail.
	doomuwad = malloc( strlen( doomwaddir ) + 1 + 8 + 1 );
	sprintf( doomuwad, "%s/doomu.wad", doomwaddir );

	// Registered.
	doomwad = malloc( strlen( doomwaddir ) + 1 + 8 + 1 );
	sprintf( doomwad, "%s/doom.wad", doomwaddir );

	// Shareware.
	doom1wad = malloc( strlen( doomwaddir ) + 1 + 9 + 1 );
	sprintf( doom1wad, "%s/doom1.wad", doomwaddir );

	// Bug, dear Shawn.
	// Insufficient malloc, caused spurious realloc errors.
	plutoniawad = malloc( strlen( doomwaddir ) + 1 +/*9*/12 + 1 );
	sprintf( plutoniawad, "%s/plutonia.wad", doomwaddir );

	tntwad = malloc( strlen( doomwaddir ) + 1 + 9 + 1 );
	sprintf( tntwad, "%s/tnt.wad", doomwaddir );


	// French stuff.
	doom2fwad = malloc( strlen( doomwaddir ) + 1 + 10 + 1 );
	sprintf( doom2fwad, "%s/doom2f.wad", doomwaddir );

	home = getenv( "HOME" );
	if( !home )
		I_Error( "Please set $HOME to your home directory" );
	sprintf( basedefault, "%s/.doomrc", home );
#endif

	if( M_CheckParm( "-shdev" ) )
	{
		gamemode = shareware;
		devparm = true;
		D_AddFile( DEVDATA"doom1.wad" );
		D_AddFile( DEVMAPS"data_se/texture1.lmp" );
		D_AddFile( DEVMAPS"data_se/pnames.lmp" );
		strcpy( basedefault, DEVDATA"default.cfg" );
		return;
	}

	if( M_CheckParm( "-regdev" ) )
	{
		gamemode = registered;
		devparm = true;
		D_AddFile( DEVDATA"doom.wad" );
		D_AddFile( DEVMAPS"data_se/texture1.lmp" );
		D_AddFile( DEVMAPS"data_se/texture2.lmp" );
		D_AddFile( DEVMAPS"data_se/pnames.lmp" );
		strcpy( basedefault, DEVDATA"default.cfg" );
		return;
	}

	if( M_CheckParm( "-comdev" ) )
	{
		gamemode = commercial;
		devparm = true;
		/* I don't bother
		if(plutonia)
		D_AddFile (DEVDATA"plutonia.wad");
		else if(tnt)
		D_AddFile (DEVDATA"tnt.wad");
		else*/
		D_AddFile( DEVDATA"doom2.wad" );

		D_AddFile( DEVMAPS"cdata/texture1.lmp" );
		D_AddFile( DEVMAPS"cdata/pnames.lmp" );
		strcpy( basedefault, DEVDATA"default.cfg" );
		return;
	}

	if( !access( doom2fwad, R_OK ) )
	{
		gamemode = commercial;
		// C'est ridicule!
		// Let's handle languages in config files, okay?
		language = french;
		printf( "French version\n" );
		D_AddFile( doom2fwad );
		return;
	}

	if( !access( doom2wad, R_OK ) )
	{
		gamemode = commercial;
		D_AddFile( doom2wad );
		return;
	}

	if( !access( plutoniawad, R_OK ) )
	{
		gamemode = commercial;
		D_AddFile( plutoniawad );
		return;
	}

	if( !access( tntwad, R_OK ) )
	{
		gamemode = commercial;
		D_AddFile( tntwad );
		return;
	}

	if( !access( doomuwad, R_OK ) )
	{
		gamemode = retail;
		D_AddFile( doomuwad );
		return;
	}

	if( !access( doomwad, R_OK ) )
	{
		gamemode = registered;
		D_AddFile( doomwad );
		return;
	}

	if( !access( doom1wad, R_OK ) )
	{
		gamemode = shareware;
		D_AddFile( doom1wad );
		return;
	}

	// stevepro
	//printf( "Game mode indeterminate.\n" );
	//gamemode = indetermined;
	gamemode = shareware;

	// We don't abort. Let's see what the PWAD contains.
	//exit(1);
	//I_Error ("Game mode indeterminate\n");
}

//
// Find a Response File
//
void FindResponseFile( void )
{
	int             i;
#define MAXARGVS        100

	for( i = 1; i < myargc; i++ )
		if( myargv[ i ][ 0 ] == '@' )
		{
			FILE *          handle;
			int             size;
			int             k;
			int             index;
			int             indexinfile;
			char    *infile;
			char    *file;
			char    *moreargs[ 20 ];
			char    *firstargv;

			// READ THE RESPONSE FILE INTO MEMORY
			handle = fopen( &myargv[ i ][ 1 ], "rb" );
			if( !handle )
			{
				printf( "\nNo such response file!" );
				exit( 1 );
			}
			printf( "Found response file %s!\n", &myargv[ i ][ 1 ] );
			fseek( handle, 0, SEEK_END );
			size = ftell( handle );
			fseek( handle, 0, SEEK_SET );
			file = malloc( size );
			fread( file, size, 1, handle );
			fclose( handle );

			// KEEP ALL CMDLINE ARGS FOLLOWING @RESPONSEFILE ARG
			for( index = 0, k = i + 1; k < myargc; k++ )
				moreargs[ index++ ] = myargv[ k ];

			firstargv = myargv[ 0 ];
			myargv = malloc( sizeof( char * )*MAXARGVS );
			memset( myargv, 0, sizeof( char * )*MAXARGVS );
			myargv[ 0 ] = firstargv;

			infile = file;
			indexinfile = k = 0;
			indexinfile++;  // SKIP PAST ARGV[0] (KEEP IT)
			do
			{
				myargv[ indexinfile++ ] = infile + k;
				while( k < size &&
					( ( *( infile + k ) >= ' ' + 1 ) && ( *( infile + k ) <= 'z' ) ) )
					k++;
				*( infile + k ) = 0;
				while( k < size &&
					( ( *( infile + k ) <= ' ' ) || ( *( infile + k ) > 'z' ) ) )
					k++;
			} while( k < size );

			for( k = 0; k < index; k++ )
				myargv[ indexinfile++ ] = moreargs[ k ];
			myargc = indexinfile;

			// DISPLAY ARGS
			printf( "%d command-line args:\n", myargc );
			for( k = 1; k < myargc; k++ )
				printf( "%s\n", myargv[ k ] );

			break;
		}
}


//
// D_ProcessEvents
// Send all the events of the given timestamp down the responder chain
//
void D_ProcessEvents( void )
{
	// TODO
	//event_t*	ev;

	//// IF STORE DEMO, DO NOT ACCEPT INPUT
	//if( ( gamemode == commercial )
	//	&& ( W_CheckNumForName( "map01" ) < 0 ) )
	//	return;

	//for( ; eventtail != eventhead; eventtail = ( ++eventtail )&( MAXEVENTS - 1 ) )
	//{
	//	ev = &events[ eventtail ];
	//	if( M_Responder( ev ) )
	//		continue;               // menu ate the event
	//	G_Responder( ev );
	//}
}


//
// D_DoomMain
//
void D_DoomMain( void )
{
//	int             p;
//	char                    file[ 256 ];

	FindResponseFile();

	IdentifyVersion();

	setbuf( stdout, NULL );
	modifiedgame = false;

	nomonsters = M_CheckParm( "-nomonsters" );
	respawnparm = M_CheckParm( "-respawn" );
	fastparm = M_CheckParm( "-fast" );
	devparm = M_CheckParm( "-devparm" );
	
}