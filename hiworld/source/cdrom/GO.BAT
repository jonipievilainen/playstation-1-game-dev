@ECHO OFF
DEL *.ISO
DEL *.IMG
DEL *.TOC
CLS
ECHO Please Wait!
ECHO Building HIWORLD.IMG...
BUILDCD -l -iHIWORLD.IMG HIWORLD.CTI
REM PAUSE
ECHO Converting HIWORLD.IMG to HIWORLD.ISO...
STRIPISO S 2352 HIWORLD.IMG HIWORLD.ISO
ECHO.
ECHO The HIWORLD CD-ROM Image was Created Successfully!
PSXLICENSE /eu /i HIWORLD.ISO