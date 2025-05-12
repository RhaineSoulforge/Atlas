#pragma once

namespace Atlas
{
    #ifdef AT_PLATFORM_WINDOWS
        #define AT_LBUTTON	0x01	//Left mouse button
        #define AT_RBUTTON	0x02	//Right mouse button
        #define AT_MBUTTON	0x04	//Middle mouse button

        #define AT_XBUTTON1	0x05	//X1 mouse button
        #define AT_XBUTTON2	0x06	//X2 mouse button
    #else
        #error Atlas only supports Windows at this time!
    #endif
}