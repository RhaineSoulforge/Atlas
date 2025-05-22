@echo off
mkdir build
pushd build

if not defined DevEnvDir (call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat")

SET includes= /I../Atlas/src/ /I../Atlas/vendor/glad/include
SET links= User32.lib Gdi32.lib Kernel32.lib opengl32.lib
SET defines= /D NDEBUG /D AT_PLATFORM_WINDOWS /D AT_ENABLE_ASSERTS
SET files= ../Atlas/src/Atlas/*.cpp ../Atlas/src/Atlas/Platform/Windows/*.cpp ../Sandbox/src/*.cpp ../Atlas/vendor/glad/src/*.c ../Atlas/src/Atlas/Platform/OpenGL/*.cpp ../Atlas/src/Atlas/Renderer/*.cpp

cl /EHsc /std:c++17 /MT %includes% %defines% %files% %links% /FeSandbox.exe

popd

Rem PAUSE
