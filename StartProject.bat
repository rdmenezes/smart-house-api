@echo off

set CONF=%2
if "%2"=="" set CONF=-debug-and-release
echo start configure and compile Qt PATH = %1 configure %CONF%
pause


echo Setting up a Qt environment...

set QTDIR=%1
echo -- QTDIR set to %1
set PATH=%1\bin;%PATH%
echo -- Added %1\bin to PATH
set QMAKESPEC=win32-msvc2010
echo -- QMAKESPEC set to "win32-msvc2010"

"C:\Program Files\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe"