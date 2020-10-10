#ifndef __D_STATE__
#define __D_STATE__

// We need globally shared data structures,
//  for defining the global state variables.
#include "doomdata.h"
//#include "d_net.h"

// We need the playr data structure as well.
//#include "d_player.h"


#ifdef __GNUG__
#pragma interface
#endif



// ------------------------
// Command line parameters.
//
extern  boolean	nomonsters;	// checkparm of -nomonsters
extern  boolean	respawnparm;	// checkparm of -respawn
extern  boolean	fastparm;	// checkparm of -fast

extern  boolean	devparm;	// DEBUG: launched with -devparm



extern GameMode_t	gamemode;

// Set if homebrew PWAD stuff has been added.
extern  boolean	modifiedgame;


// -------------------------------------------
// Language.
extern  Language_t   language;


#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
