#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

#include "main.h"


#define SPACE_BETWEEN_NORMAL 7
#define SPACE_BETWEEN_BIG 14

#define COLUMN_NORMAL getmaxy(stdscr) / 2 -3
#define COLUMN_BIG getmaxy(stdscr) / 2 -5

#define ROW_WITH_SECONDS_NORMAL getmaxx(stdscr) / 2 - (4*SPACE_BETWEEN_NORMAL) +2
#define ROW_WITHOUT_SECONDS_NORMAL getmaxx(stdscr) / 2 - (2.5*SPACE_BETWEEN_NORMAL) +2
#define ROW_WITH_SECONDS_BIG getmaxx(stdscr) / 2 - (4*SPACE_BETWEEN_BIG) +2
#define ROW_WITHOUT_SECONDS_BIG getmaxx(stdscr) / 2 - (2.5*SPACE_BETWEEN_BIG) +2


void initCurses(); 
void displayTime(Time *time, bool seconds, bool displayBigNumbers);
void printNumber(int n, int y, int x, bool displayBigNumbers); 

#endif
