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

#ifdef AT_ENABLE_ASSERTS
    #define AT_ASSERT(x,...) { if(x) { AT_LOG_ERROR("Assertion Failed: {s}",__VA_ARGS__); __debugbreak(); } }
#else
    #define AT_ASSERT(x,...)
#endif

#define AT_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)

#define SET_BIT(x,y) (x |= y)
#define CLEAR_BITS(x) (x = 0)
#define CLEAR_BIT(x,y) (x &= ~y)
#define TOGGLE_BIT(x) (x ^= y)
#define CHECK_BIT(x,y) (((x & y) == y) ? true : false)