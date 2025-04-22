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

#define SET_BIT(x,y) (x |= y)
#define CLEAR_BITS(x) (x = 0)
#define CLEAR_BIT(x,y) (x &= ~y)
#define TOGGLE_BIT(x) (x ^= y)
#define CHECK_BIT(x,y) (((x & y) == y) ? true : false)