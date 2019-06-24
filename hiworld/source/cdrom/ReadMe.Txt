CD Tools
--------
These are just some quick tools I bust out.  Most of them are just a tiny bit of polish on top of messy tools I've written for myself.  USE THEM AT YOUR OWN RISK.

If you want to distribute these tools as part of a package of your own, I'd appreciate an email and a "thank you" in your about box and/or documentation/readme.

Most of my quick-and-dirty tools are written in Visual Basic, and these are no exceptions.  As such, most of them will require that you have the Visual Basic 6 runtime stuff.  If you don't have it, try http://download.com.com/3000-2070-5531236.html?tag=pop

If you just double-click the EXEs (or run them without arguments), most will pop up some usage information.  


Package History
---------------
2002 11 30	Added Revenge Of StripISO
		Added "STR Movies" section below



The Tools
---------
Here's the rundown:

makecd.bat
----------
A batch file skeleton.  You enter makecd <folder name>, and it will make an ISO image based on the contents of the folder.  Makes use of other files in here and also BUILDCD (which you can find elsewhere).

MakeCTI.exe
-----------
Makes a CTI based on a directory structure you've built locally.  See MakeCTI.Txt for more information.

StripISOToo.exe
---------------
A replacement for STRIPISO.  Works in Windows XP.  Not completely commandline compatible.  If you need a more compatible version (and the batch file below doesn't help), email me and I'll write one.

stipiso.bat
-----------
A batch file that runs StripISOToo.  You can modify batch files which execute STRIPISO.EXE to instead do "call stripiso.bat".  Well, sort of, anyway.

stripiso.exe
------------
This is Revenge Of StripISO (ROSI).  I wrote StripISOToo as a quick replacement for the widely-available STRIPISO, since it doesn't work under Windows XP.  I basically wrote it for myself so that I could make PSX CDs with mode 2 form 2 files on them (in my case, a couple of STR movies).  Since then, I've learned that some other programs use STRIPISO to do some of their dirty work.  My StripISOToo was never meant to be an exact replacement for STRIPISO, and though I think it could be made to work -- it was difficult for users.  So, I wrote Revenge Of StripISO, which is meant to be a drop-in replacement for the old STRIPISO.  Just copy this one over the old one and you should be good to go.

ISOTrim.exe
-----------
I'm not sure how well this works (I haven't tested it super extensively).  Basically, it just tries to chop extra data off the end of an image file that has extra data at the end.  I wrote this because Nero image files are basically just ISOs with some extra stuff.  The extra stuff makes the unrecognizable to other tools, unfortunately.  By running ISOTrim on them, other tools can then handle them.

strip2048.exe
-------------
Converts 2352 byte per sector CD images (or license files!) to 2048 byte per sector images.


Other related stuff in the works:


LameLice.exe
------------
A dumb little license tool.  There are many like it, but this one is mine, sir.  Can add licenses to images, can also make license files based on already-licensed images.  Works with both 2048 and 2352 sector sizes.


STR Movies
----------
Since people have been asking about doing it, here is a way to make movie discs:
1. Unzip the contents of my PSX CD Tools package into its own directory
2. Put BUILDCD.EXE into that directory (it's widely available on the net)
3. Create a subdirectory called something like "MOVIECD".
4. Put everything you want on that CD into the folder.  This includes your STR movies,
   movie player program, etc.
5. Open a command shell ('command.com' under Windows 95/98/Me, "cmd.exe" under NT/2000/XP)
   and navigate to the PSX CD Tools directory (i.e. "cd c:\windows\desktop\psxcdtools").
6. Run "makecd moviecd".
7. If all goes well, you'll get a 'moviecd.iso' file, which you can burn to a CD.  Presto.


Murphy McCauley
MMcCauley@FullSpectrum.Com
If you're emailing me, be sure to put "Deeth" somewhere in the Subject line!
November 2002