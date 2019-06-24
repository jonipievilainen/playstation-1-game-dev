@echo off

rem del %1.cti
rem del %1.iso

echo Building CTI...
call buildcti %1 %1.cti

echo Building CD image...
buildcd -l -i%1.img %1.cti

echo Converting to ISO...
call stripiso.bat %1.img %1.iso

rem del %1.img

echo ----------------
echo %1.ISO ready!