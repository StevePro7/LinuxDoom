// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	DOOM main program (D_DoomMain) and game loop (D_DoomLoop),
//	plus functions to determine game mode (shareware, registered),
//	parse command line parameters, configure game parameters (turbo),
//	and call the startup functions.
//
//-----------------------------------------------------------------------------


static const char rcsid[] = "$Id: d_main.c,v 1.8 1997/02/03 22:45:09 b1 Exp $";

#define	BGCOLOR		7
#define	FGCOLOR		8


#ifdef NORMALUNIX
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif


//#include "doomdef.h"
//#include "doomstat.h"
//
//#include "dstrings.h"
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
//#include "m_argv.h"
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


#include "d_main.h"

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

//skill_t		startskill;
int             startepisode;
int		startmap;
boolean		autostart;

//FILE*		debugfile;

boolean		advancedemo;




char		wadfile[ 1024 ];		// primary wad file
char		mapdir[ 1024 ];           // directory of development maps
char		basedefault[ 1024 ];      // default file

//
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
// D_DoomMain
//
void D_DoomMain( void )
{
	//int             p;
	//char                    file[ 256 ];
}