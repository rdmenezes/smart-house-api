@echo off

set CONF=-debug-and-release
echo Setting up a Qt environment...

set QTDIR=%CD%\mera-im++qt\qt
echo -- QTDIR set to %QTDIR%
set PATH=%QTDIR%\bin;%PATH%
echo -- Added %QTDIR%\bin to PATH
set QMAKESPEC=win32-msvc2010
echo -- QMAKESPEC set to "win32-msvc2010"
"C:\Program Files\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe"