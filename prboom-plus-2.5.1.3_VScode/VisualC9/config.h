/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999-2000 by
 *  Florian Schulze (florian.schulze@gmx.net)
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  This is the config file for Windows
 *
 *-----------------------------------------------------------------------------*/

#define inline __inline

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* Define to strcasecmp, if we have it */
#define stricmp strcasecmp

/* Define to strncasecmp, if we have it */
#define strnicmp strncasecmp

/* Define on targets supporting 386 Assembly */
/* This is in the project settings */
/* #define I386_ASM 1 */

#ifdef _DEBUG
//#define PRBOOM_DEBUG 1
#endif // _DEBUG

#ifdef PRBOOM_DEBUG

/* Define to enable internal range checking */
#define RANGECHECK 1

/* Define this to see real-time memory allocation
 * statistics, and enable extra debugging features
 */
#define INSTRUMENTED 1

/* Uncomment this to exhaustively run memory checks
 * while the game is running (this is EXTREMELY slow).
 * Only useful if INSTRUMENTED is also defined.
 */
#define CHECKHEAP 1

/* Uncomment this to cause heap dumps to be generated.
 * Only useful if INSTRUMENTED is also defined.
 */
#define HEAPDUMP 1

/* Uncomment this to perform id checks on zone blocks,
 * to detect corrupted and illegally freed blocks
 */
#define ZONEIDCHECK 1

/* CPhipps - some debugging macros for the new wad lump handling code */
/* Defining this causes quick checks which only impose an overhead if a
 *  posible error is detected. */
#define SIMPLECHECKS 1

/* Defining this causes time stamps to be created each time a lump is locked, and
 *  lumps locked for long periods of time are reported */
#define TIMEDIAG 1

#endif // PRBOOM_DEBUG

/* Define to be the path where Doom WADs are stored */
#define DOOMWADDIR "/usr/local/share/games/doom"

/* Define if you have the SDL mixer library -lSDL_mixer */
#define HAVE_LIBSDL_MIXER 1

/* Define if you want networkg ame support */
#define HAVE_NET 1
#define USE_SDL_NET 1

/* Define if you have struct sockaddr_in6 */
/* #define HAVE_IPv6 1 */

/* Define if you have the inet_aton function.  */
/* #define HAVE_INET_ATON 1 */

/* Define if you have the inet_ntop function.  */
/* #define HAVE_INET_NTOP 1 */

/* Define if you have the inet_pton function.  */
/* #define HAVE_INET_PTON 1 */

/* Define if you have the setsockopt function.  */
/* #define HAVE_SETSOCKOPT 1 */

/* Define if you have the snprintf function.  */
#define HAVE_SNPRINTF 1
#define snprintf _snprintf

/* Define if you have the vsnprintf function.  */
#define HAVE_VSNPRINTF 1
#if _MSC_VER < 1400 /* not needed for Visual Studio 2008 */
#define vsnprintf _vsnprintf
#endif

/* Define for support for MBF helper dogs */
#define DOGS 1

#define MONITOR_VISIBILITY 1

/* Define if you want to use the gluTesselator  */
#define USE_GLU_TESS 1

/* Define if you want to use gluImageScale  */
#define USE_GLU_IMAGESCALE 1

/* Define if you want to use gluBuild2DMipmaps  */
#define USE_GLU_MIPMAP 1

/* Define if you want to use the Windows launcher */
#define USE_WINDOWS_LAUNCHER 1

/* Define if you want to use SIMD instructions */
#undef SIMD_INSTRUCTIONS

/* Set to the attribute to apply to struct definitions to make them packed.
 * For MSVC++ we can't do it like this, there are pragma's in the source
 * instead. */
#define PACKEDATTR

/* Name of package */
#define PACKAGE "prboom-plus"

/* Define to the full name of this package. */
#define PACKAGE_NAME "PrBoom-Plus"

//e6y
/* Version number of package */
#define VERSION "2.5.1.3"

/* Define if you have the SDL image library -lSDL_image */
#define HAVE_LIBSDL_IMAGE

/* Define if you want to use FBO for some tricks in OpenGL */
#define USE_FBO_TECHNIQUE 1

/* Define if you want to use PC Speaker */
#define USE_WIN32_PCSOUND_DRIVER

#define USE_EXPERIMENTAL_MUSIC 1

#if defined(USE_EXPERIMENTAL_MUSIC) && !defined(PRBOOM_SERVER)

/* use delay load feature for the libraries */
#pragma comment( lib, "delayimp.lib" )

/* Define to 1 if you have the `fluidsynth' library (-lfluidsynth). */
#define HAVE_LIBFLUIDSYNTH 1

/* Define to 1 if you have the `mad' library (-lmad). */
#define HAVE_LIBMAD 1

/* Define to 1 if you have the `portmidi' library (-lportmidi). */
#define HAVE_LIBPORTMIDI 1

/* Define to 1 if you have the `dumb' library (-ldumb). */
#define HAVE_LIBDUMB 1

/* Define to 1 if you have the `vorbisfile' library (-lvorbisfile). */
#define HAVE_LIBVORBISFILE 1

#ifdef _DEBUG
  #define LINK_MUS_LIBRARY(x) comment(lib, x"d.lib")
#else
  #define LINK_MUS_LIBRARY(x) comment(lib, x".lib")
#endif

#if defined(HAVE_LIBFLUIDSYNTH)
#pragma comment( lib, "libfluidsynth.lib" )
#endif

#if defined(HAVE_LIBMAD)
#pragma LINK_MUS_LIBRARY("libmad")
#endif

#if defined(HAVE_LIBPORTMIDI)
#pragma comment( lib, "portmidi.lib" )
#endif

#if defined(HAVE_LIBDUMB)
#pragma LINK_MUS_LIBRARY("dumb")
#endif

#if defined(HAVE_LIBVORBISFILE)
#pragma comment( lib, "libvorbisfile.lib" )
#pragma comment( lib, "libvorbis.lib" )
#pragma comment( lib, "libogg.lib" )
#endif

#endif // USE_EXPERIMENTAL_MUSIC

/* MSVC6' implementation of qsort is much slower (up to 32x) than it should be */
//#define USE_CUSTOM_QSORT 1

/* Shut up warnings */
#ifdef __INTEL_COMPILER
  #pragma warning(disable : 94 144 175 177 186 188 279 556 589 810)
#endif // __INTEL_COMPILER

#ifdef _WIN32

/* Define if you want to have PrBoom-Plus.wad in the exe  */
//#define ALL_IN_ONE 1

#ifdef _MSC_VER

//#define ALL_WARNINGS
#ifdef ALL_WARNINGS
  #pragma warning(error : 4701) // local variable *may* be used without init
  #pragma warning(error : 4189) // initialized but unused variable
#endif // ALL_WARNINGS

#ifdef _DEBUG
  #define LINK_LIBRARY(x) comment(lib, x"_D.lib")
#else
  #define LINK_LIBRARY(x) comment(lib, x".lib")
#endif

#ifdef ALL_IN_ONE
  #pragma LINK_LIBRARY("SDL_static" )
  #pragma LINK_LIBRARY("SDL_mixer_static" )
  #pragma LINK_LIBRARY("SDL_net_static" )
#ifdef HAVE_LIBSDL_IMAGE
  #pragma LINK_LIBRARY("SDL_image_static" )
#endif // HAVE_LIBSDL_IMAGE
#else // ALL_IN_ONE
  #pragma comment( lib, "SDL.lib" )
  #pragma comment( lib, "SDL_mixer.lib" )
  #pragma comment( lib, "SDL_net.lib" )
#ifdef HAVE_LIBSDL_IMAGE
  #pragma comment( lib, "SDL_image.lib" )
#endif // HAVE_LIBSDL_IMAGE
#endif // ALL_IN_ONE

#endif // _MSC_VER

#endif // _WIN32
