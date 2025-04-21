#pragma once

#ifdef AT_PLATFORM_WINDOWS
    #ifdef AT_BUILD_DLL
        #define ATLAS_API __declspec(dllexport)
    #else
        #define ATLAS_API __declspec(dllimport)
    #endif
#else
    #error Atlas only supports Windows!
#endif