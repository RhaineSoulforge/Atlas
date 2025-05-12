#pragma once

namespace Atlas
{
    #ifdef AT_PLATFORM_WINDOWS

        #define AT_KEY_BACK	0x08	//BACKSPACE key
        #define AT_KEY_TAB	0x09	//TAB key
        #define AT_KEY_CLEAR	0x0C	//CLEAR key
        #define AT_KEY_RETURN	0x0D	//ENTER key
        #define AT_KEY_SHIFT	0x10	//SHIFT key
        #define AT_KEY_CONTROL	0x11	//CTRL key
        #define AT_KEY_MENU	0x12	//ALT key
        #define AT_KEY_PAUSE	0x13	//PAUSE key
        #define AT_KEY_CAPITAL	0x14	//CAPS LOCK key
        #define AT_KEY_ESCAPE	0x1B	//ESC key
        #define AT_KEY_SPACE	0x20	//SPACEBAR
        #define AT_KEY_PRIOR	0x21	//PAGE UP key
        #define AT_KEY_NEXT	0x22	//PAGE DOWN key
        #define AT_KEY_END	0x23	//END key
        #define AT_KEY_HOME	0x24	//HOME key
        #define AT_KEY_LEFT	0x25	//LEFT ARROW key
        #define AT_KEY_UP	0x26	//UP ARROW key
        #define AT_KEY_RIGHT	0x27	//RIGHT ARROW key
        #define AT_KEY_DOWN	0x28	//DOWN ARROW key
        #define AT_KEY_SELECT	0x29	//SELECT key
        #define AT_KEY_PRINT	0x2A	//PRINT key
        #define AT_KEY_EXECUTE	0x2B	//EXECUTE key
        #define AT_KEY_SNAPSHOT	0x2C	//PRINT SCREEN key
        #define AT_KEY_INSERT	0x2D	//INS key
        #define AT_KEY_DELETE	0x2E	//DEL key

        #define AT_KEY_0 0x30	//0 key
        #define AT_KEY_1 0x31	//1 key
        #define AT_KEY_2 0x32	//2 key
        #define AT_KEY_3 0x33	//3 key
        #define AT_KEY_4 0x34	//4 key
        #define AT_KEY_5 0x35	//5 key
        #define AT_KEY_6 0x36	//6 key
        #define AT_KEY_7 0x37	//7 key
        #define AT_KEY_8 0x38	//8 key
        #define AT_KEY_9 0x39	//9 key
        #define AT_KEY_A 0x41	//A key
        #define AT_KEY_B 0x42	//B key
        #define AT_KEY_C 0x43	//C key
        #define AT_KEY_D 0x44	//D key
        #define AT_KEY_E 0x45	//E key
        #define AT_KEY_F 0x46	//F key
        #define AT_KEY_G 0x47	//G key
        #define AT_KEY_H 0x48	//H key
        #define AT_KEY_I 0x49	//I key
        #define AT_KEY_J 0x4A	//J key
        #define AT_KEY_K 0x4B	//K key
        #define AT_KEY_L 0x4C	//L key
        #define AT_KEY_M 0x4D	//M key
        #define AT_KEY_N 0x4E	//N key
        #define AT_KEY_O 0x4F	//O key
        #define AT_KEY_P 0x50	//P key
        #define AT_KEY_Q 0x51	//Q key
        #define AT_KEY_R 0x52	//R key
        #define AT_KEY_S 0x53	//S key
        #define AT_KEY_T 0x54	//T key
        #define AT_KEY_U 0x55	//U key
        #define AT_KEY_V 0x56	//V key
        #define AT_KEY_W 0x57	//W key
        #define AT_KEY_X 0x58	//X key
        #define AT_KEY_Y 0x59	//Y key
        #define AT_KEY_Z 0x5A	//Z key

        #define AT_KEY_LWIN	0x5B	//Left Windows key
        #define AT_KEY_NUMPAD0	0x60	//Numeric keypad 0 key
        #define AT_KEY_NUMPAD1	0x61	//Numeric keypad 1 key
        #define AT_KEY_NUMPAD2	0x62	//Numeric keypad 2 key
        #define AT_KEY_NUMPAD3	0x63	//Numeric keypad 3 key
        #define AT_KEY_NUMPAD4	0x64	//Numeric keypad 4 key
        #define AT_KEY_NUMPAD5	0x65	//Numeric keypad 5 key
        #define AT_KEY_NUMPAD6	0x66	//Numeric keypad 6 key
        #define AT_KEY_NUMPAD7	0x67	//Numeric keypad 7 key
        #define AT_KEY_NUMPAD8	0x68	//Numeric keypad 8 key
        #define AT_KEY_NUMPAD9	0x69	//Numeric keypad 9 key
        #define AT_KEY_MULTIPLY	0x6A	//Multiply key
        #define AT_KEY_ADD	0x6B	//Add key
        #define AT_KEY_SEPARATOR	0x6C	//Separator key
        #define AT_KEY_SUBTRACT	0x6D	//Subtract key
        #define AT_KEY_DECIMAL	0x6E	//Decimal key
        #define AT_KEY_DIVIDE	0x6F	//Divide key
        #define AT_KEY_F1	0x70	//F1 key
        #define AT_KEY_F2	0x71	//F2 key
        #define AT_KEY_F3	0x72	//F3 key
        #define AT_KEY_F4	0x73	//F4 key
        #define AT_KEY_F5	0x74	//F5 key
        #define AT_KEY_F6	0x75	//F6 key
        #define AT_KEY_F7	0x76	//F7 key
        #define AT_KEY_F8	0x77	//F8 key
        #define AT_KEY_F9	0x78	//F9 key
        #define AT_KEY_F10	0x79	//F10 key
        #define AT_KEY_F11	0x7A	//F11 key
        #define AT_KEY_F12	0x7B	//F12 key

        #define AT_KEY_NUMLOCK	0x90	//NUM LOCK key
        #define AT_KEY_SCROLL	0x91	//SCROLL LOCK key

        #define AT_KEY_LSHIFT	0xA0	//Left SHIFT key
        #define AT_KEY_RSHIFT	0xA1	//Right SHIFT key
        #define AT_KEY_LCONTROL	0xA2	//Left CONTROL key
        #define AT_KEY_RCONTROL	0xA3	//Right CONTROL key
        #define AT_KEY_LMENU	0xA4	//Left ALT key
        #define AT_KEY_RMENU	0xA5	//Right ALT key
    #else
        #error Atlas only supports Windows at this time!
    #endif
}