static const char
rcsid[] = "$Id: i_main.c,v 1.4 1997/02/03 22:45:10 b1 Exp $";



#include "doomdef.h"
#include "m_argv.h"


int
main
( int		argc,
  char**	argv )
{
	myargc = argc;
	myargv = argv;

	//D_DoomMain();

	return 0;
}