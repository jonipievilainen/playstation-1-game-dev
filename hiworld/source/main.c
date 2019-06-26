/*
===========================================================
                Sony PlayStation 1 Source Code
===========================================================
                         FONT EXAMPLE
                  displays text on the screen
-----------------------------------------------------------

    Developer / Programmer..............: SCEI & PSXDEV.net
    Software Ddevelopment Kit...........: PSY-Q
    Last Release........................: 04/JANUARY/2013

          Original code by SCEI | Edited by PSXDEV.net

      If you need help, read LIBOVR46.PDF in PSYQ/DOCS
      also join our IRC channel on EFNET #psxdev

  Copyright (C) 1994,1995 by Sony Computer Entertainment Inc.
                     All Rights Reserved.

   Sony Computer Entertainment Inc. Development Department

                    http://psxdev.net/

-----------------------------------------------------------*/

#include <sys/types.h>
#include <libetc.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <stdio.h>

#define OT_LENGTH (2) // the ordertable length
#define PACKETMAX (20) // the maximum number of objects on the screen

#define SCREEN_WIDTH  320 // screen width
#define	SCREEN_HEIGHT 240 // screen height

unsigned long __ramsize =   0x002000000; // force the PSX to use 2 megabytes of RAM
unsigned long __stacksize = 0x00004000; // force the PSX to use 16 kilobytes of stack

GsOT myOT[2];            
GsOT_TAG myOT_TAG[2][1<<OT_LENGTH];
PACKET GPUPacketArea[2][PACKETMAX];   

// --------
// INTEGERS
// --------
int main(void);
int CurrentBuffer = 0;

// ----------
// PROTOTYPES
// ----------
void graphics();
void display();

const DEBUG = 1; // a switch for turning on and off debugging (seen below in the code)


int main(void) 
{
	graphics(); // setup the graphics (seen below)

	FntLoad(960, 256); // load basic font pattern

	// screen X,Y | max text length X,Y | autmatic background clear 0,1 | max characters (eg: 50).
	SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512));

	// should debug = 1 (as seen above), print to the debug window (should you be using one)
	if (DEBUG) printf("\n\nPievin eka ps1 demo\n");
	if (DEBUG) printf("\nhttp://aika.zapto.org/");

	// draw and display forever
	while (1)
	{
		FntPrint("             PIEVIN EKA PS1 DEMO\n\n           HTTP://AIKA.ZAPTO.ORG/"); // use '\n' to make a new line
		display();
	}

	return 0;
}

void graphics()
{
   // automatic video mode control. As a learning excersize, try making it set the correct resolution for NTSC format. The defined value above (320x240) is for PAL.
   if (*(char *)0xbfc7ff52=='E') // SCE[E] string address
     SetVideoMode(1); // PAL MODE
   else
     SetVideoMode(0); // NTSC MODE

   // set the graphics mode resolutions
   GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, GsINTER|GsOFSGPU, 1, 0); // you may also try using 'GsNONINTER'. Do a search/find in LIBOVR46.PDF in PSYQ/DOCS for detailed information

   // set the top left coordinates of the two buffers in video memory
   GsDefDispBuff(0, 0, 0, SCREEN_HEIGHT);

   // init the ordering tables
   myOT[0].length = OT_LENGTH;
   myOT[1].length = OT_LENGTH;
   myOT[0].org = myOT_TAG[0];
   myOT[1].org = myOT_TAG[1];

   GsClearOt(0,0,&myOT[0]);
   GsClearOt(0,0,&myOT[1]);
}


void display()
{
	// refresh the font
	FntFlush(-1);

	// get the current buffer
	CurrentBuffer=GsGetActiveBuff();

	// setup the packet workbase
	GsSetWorkBase((PACKET*)GPUPacketArea[CurrentBuffer]);

	// clear the ordering table
	GsClearOt(0,0,&myOT[CurrentBuffer]);

	// wait for all drawing to finish
	DrawSync(0);

	// wait for v_blank interrupt - a useful way to do a 'sleep' in Psy-Q, is to use 'for i=0; i<20; i++ VSync(0);'
	// try adding this to the main while loop and noteing what happens...
	VSync(0);

	// flip double buffers
	GsSwapDispBuff();

	// clear the ordering table with a background color
	GsSortClear(rand(200),rand(200),rand(200),&myOT[CurrentBuffer]); // RGB value 50,50,50 which is a grey/gray background (0,0,0 would be black for example)

	// Draw the ordering table for the CurrentBuffer
	GsDrawOt(&myOT[CurrentBuffer]);
}