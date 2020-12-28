# LinuxDoom
Test repository for id software Linux Doom source code

28/12/2020
Launch Linux	Ubuntu 19.04
git clone https://github.com/StevePro7/LinuxDoom
cd /path_to_LinuxDoom
cd prboom-plus-2.5.1.3_VScode

chmod +x build.sh
chmod +x configure
./configure
make
cd src
./prboom-plus

Launch VS Code
open folder
prboom-plus-2.5.1.3_VScode

Set break point
i_main.c
d_main.c

Press F5 to debug step thru the code


10/10/2020

Doom Retro
E:\Github\StevePro7\RetroDoom


D:\Github\bradharding\doomretro

VS2015
doomretro.sln
D:\Github\bradharding\doomretro\msvc

Debug
32-bit

doom1.wad
E:\Steven\INSTALLATION\Doom\_RetroDoom

EXE
E:\Steven\INSTALLATION\Doom\_RetroDoom\doomretro-3.5.5-win32


Linux
prboom-2.1.1-win32
DoomanNOTES.txt
E:\Steven\INSTALLATION\Doom


TODO watch this...!
https://www.siliconrepublic.com/video/john-romero-doom-wolfenstein-3d



25/09/2020
Game Engine Black Book: DOOM
https://archive.org/details/gebbdoome/page/394/mode/2up

Github
https://github.com/fabiensanglard/gebbdoom

Download book!
https://fabiensanglard.net/gebbdoom.pdf

DoomEngine.pdf
D:\Steven\BOOKS


Linux Doom
id software
E:\GitHub\StevePro7\Blogger\Doom\linuxdoom-1.10
D:\Github\id-software\DOOM\linuxdoom-1.10

FILE
#include <stdio.h>

disable 4996
e.g. file open
Add to preprocessor directives in project properties
C/C++ | PreProcessor
_CRT_SECURE_NO_WARNINGS



11/10/2020
m_menu.c
M_ResponderEvent()
menu actions respond to events key press etc.



ENTRY POINT
01.
i_main.c
E:\GitHub\StevePro7\LinuxDoom\dev\
int main( int argc, char**	argv )
D_DoomMain();


02.
doomretro.c
D:\Github\bradharding\doomretro\src\
int main(int argc, char **argv)
D_DoomMain();