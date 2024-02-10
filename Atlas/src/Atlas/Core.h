#pragma once

#ifdef AT_PLATFORM_WINDOWS
   #ifdef AT_BUILD_DLL
      #define ATLAS_API __declspec(dllexport)
   #else 
      #define ATLAS_API __declspec(dllimport)
   #endif
#else
   #error Atlas only supports Windows at this time!
#endif

#ifdef AT_ENABLE_ASSERTS
   #define AT_ASSERT(x, ...) { if(!(x)) { AT_LOG_ERROR("Assertion Failed: {s}",__VA_ARGS__); __debugbreak(); } }
#else
   #define AT_ASSERT(x, ...)
#endif

#define SET_BIT(x,y) (x |= y)
#define CLEAR_BITS(x) (x = 0)
#define CLEAR_BIT(x,y) (x &= ~y)
#define TOGGLE_BIT(x) (x ^= y)
#define CHECK_BIT(x,y) (((x & y) == y) ? true : false)
#define BIT(x) (1 << x)

#define MOUSEBUFFERSIZE 4
#define KEYBOARDBUFFERSIZE 256