#ifndef BOX_H
#define BOX_H
#include <stdlib.h>
#include <sys/ioctl.h> //For getting the widht of the terminal;

// These are standard box drawing charcters for unix based system.
#define _VER_n "│"   /* "\x1b(0\x78\x1b(B" */
#define _TL_n "┌"    /* "\x1b(0\x6c\x1b(B" */
#define _TR_n "┐"    /* "\x1b(0\x6b\x1b(B" */
#define _HOR_n "─"   /* "\x1b(0\x71\x1b(B" */
#define _BL_n "└"    /* "\x1b(0\x6d\x1b(B" */
#define _BR_n "┘"    /* "\x1b(0\x6a\x1b(B" */
#define _CROSS_n "┼" /* "\x1b(0\x6e\x1b(B" */
#define _VER_RIGHT_n "├"
#define _VER_LEFT_n "┤"

// Other box drawing characters

// Bold lines
#define _VER_b "┃"
#define _TL_b "┏"
#define _TR_b "┓"
#define _HOR_b "━"
#define _BL_b "┗"
#define _BR_b "┛"
#define _CROSS_b "╋"

// Double line
#define _VER_d "║"
#define _TL_d "╔"
#define _TR_d "╗"
#define _HOR_d "═"
#define _BL_d "╚"
#define _BR_d "╝"
#define _CROSS_d "╬"

// Rounded corners
#define _TR_r "╮"
#define _TL_r "╭"
#define _BL_r "╰"
#define _BR_r "╯"

#endif
