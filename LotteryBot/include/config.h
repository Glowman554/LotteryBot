#pragma once

/*
#define LANG_GERMAN
#undef LANG_ENGLISH
*/
///*
#define LANG_ENGLISH
#undef LANG_GERMAN
//*/

#define VERSION "0.2"
#define VENDOR "Glowman554"

#define MINECRAFT_VER L"Minecraft 1.16.4 - Multiplayer (3rd-party Server)"

#define WINDOW_X 745
#define WINDOW_Y 520

#define NEWTICKET_X 375
#define NEWTICKET_Y 275

#define OPEN_ALL_X 500
#define OPEN_ALL_Y 275

#ifdef LANG_ENGLISH
#include <langsys/english.h>
#endif

#ifdef LANG_GERMAN
#include <langsys/german.h>
#endif