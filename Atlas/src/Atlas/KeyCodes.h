#pragma once

namespace Atlas
{
    #ifdef AT_PLATFORM_WINDOWS

        #define AT_BACK	0x08	//BACKSPACE key
        #define AT_TAB	0x09	//TAB key
        #define AT_CLEAR	0x0C	//CLEAR key
        #define AT_RETURN	0x0D	//ENTER key
        #define AT_SHIFT	0x10	//SHIFT key
        #define AT_CONTROL	0x11	//CTRL key
        #define AT_MENU	0x12	//ALT key
        #define AT_PAUSE	0x13	//PAUSE key
        #define AT_CAPITAL	0x14	//CAPS LOCK key
        #define AT_ESCAPE	0x1B	//ESC key
        #define AT_SPACE	0x20	//SPACEBAR
        #define AT_PRIOR	0x21	//PAGE UP key
        #define AT_NEXT	0x22	//PAGE DOWN key
        #define AT_END	0x23	//END key
        #define AT_HOME	0x24	//HOME key
        #define AT_LEFT	0x25	//LEFT ARROW key
        #define AT_UP	0x26	//UP ARROW key
        #define AT_RIGHT	0x27	//RIGHT ARROW key
        #define AT_DOWN	0x28	//DOWN ARROW key
        #define AT_SELECT	0x29	//SELECT key
        #define AT_PRINT	0x2A	//PRINT key
        #define AT_EXECUTE	0x2B	//EXECUTE key
        #define AT_SNAPSHOT	0x2C	//PRINT SCREEN key
        #define AT_INSERT	0x2D	//INS key
        #define AT_DELETE	0x2E	//DEL key

        #define AT_0 0x30	//0 key
        #define AT_1 0x31	//1 key
        #define AT_2 0x32	//2 key
        #define AT_3 0x33	//3 key
        #define AT_4 0x34	//4 key
        #define AT_5 0x35	//5 key
        #define AT_6 0x36	//6 key
        #define AT_7 0x37	//7 key
        #define AT_8 0x38	//8 key
        #define AT_9 0x39	//9 key
        #define AT_A 0x41	//A key
        #define AT_B 0x42	//B key
        #define AT_C 0x43	//C key
        #define AT_D 0x44	//D key
        #define AT_E 0x45	//E key
        #define AT_F 0x46	//F key
        #define AT_G 0x47	//G key
        #define AT_H 0x48	//H key
        #define AT_I 0x49	//I key
        #define AT_J 0x4A	//J key
        #define AT_K 0x4B	//K key
        #define AT_L 0x4C	//L key
        #define AT_M 0x4D	//M key
        #define AT_N 0x4E	//N key
        #define AT_O 0x4F	//O key
        #define AT_P 0x50	//P key
        #define AT_Q 0x51	//Q key
        #define AT_R 0x52	//R key
        #define AT_S 0x53	//S key
        #define AT_T 0x54	//T key
        #define AT_U 0x55	//U key
        #define AT_V 0x56	//V key
        #define AT_W 0x57	//W key
        #define AT_X 0x58	//X key
        #define AT_Y 0x59	//Y key
        #define AT_Z 0x5A	//Z key

        #define AT_LWIN	0x5B	//Left Windows key
        #define AT_NUMPAD0	0x60	//Numeric keypad 0 key
        #define AT_NUMPAD1	0x61	//Numeric keypad 1 key
        #define AT_NUMPAD2	0x62	//Numeric keypad 2 key
        #define AT_NUMPAD3	0x63	//Numeric keypad 3 key
        #define AT_NUMPAD4	0x64	//Numeric keypad 4 key
        #define AT_NUMPAD5	0x65	//Numeric keypad 5 key
        #define AT_NUMPAD6	0x66	//Numeric keypad 6 key
        #define AT_NUMPAD7	0x67	//Numeric keypad 7 key
        #define AT_NUMPAD8	0x68	//Numeric keypad 8 key
        #define AT_NUMPAD9	0x69	//Numeric keypad 9 key
        #define AT_MULTIPLY	0x6A	//Multiply key
        #define AT_ADD	0x6B	//Add key
        #define AT_SEPARATOR	0x6C	//Separator key
        #define AT_SUBTRACT	0x6D	//Subtract key
        #define AT_DECIMAL	0x6E	//Decimal key
        #define AT_DIVIDE	0x6F	//Divide key
        #define AT_F1	0x70	//F1 key
        #define AT_F2	0x71	//F2 key
        #define AT_F3	0x72	//F3 key
        #define AT_F4	0x73	//F4 key
        #define AT_F5	0x74	//F5 key
        #define AT_F6	0x75	//F6 key
        #define AT_F7	0x76	//F7 key
        #define AT_F8	0x77	//F8 key
        #define AT_F9	0x78	//F9 key
        #define AT_F10	0x79	//F10 key
        #define AT_F11	0x7A	//F11 key
        #define AT_F12	0x7B	//F12 key

        #define AT_NUMLOCK	0x90	//NUM LOCK key
        #define AT_SCROLL	0x91	//SCROLL LOCK key

        #define AT_LSHIFT	0xA0	//Left SHIFT key
        #define AT_RSHIFT	0xA1	//Right SHIFT key
        #define AT_LCONTROL	0xA2	//Left CONTROL key
        #define AT_RCONTROL	0xA3	//Right CONTROL key
        #define AT_LMENU	0xA4	//Left ALT key
        #define AT_RMENU	0xA5	//Right ALT key
    #endif
}