@echo off
mkdir build
pushd build

if not defined DevEnvDir (call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat")

SET includes= /I../Atlas/src/
SET links= User32.lib Gdi32.lib Kernel32.lib
SET defines= /D NDEBUG /D AT_PLATFORM_WINDOWS
SET files= ../Atlas/src/Atlas/*.cpp ../Sandbox/src/*.cpp

cl /EHsc /std:c++17 %includes% %defines% %files% %links% /FeSandbox.exe

popd

PAUSE