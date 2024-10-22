#include <stdio.h>
#include <ncurses.h>
#include <stdbool.h>

#include "display.h"
#include "main.h"

void initCurses(){
	initscr(); 
	cbreak(); 
	keypad(stdscr, TRUE); 
	nodelay(stdscr, TRUE); // do not wait for input
	noecho(); curs_set(0); 
}

void displayTime(Time *time, bool seconds, bool displayBigNumbers){
	int space_between, row_offset, column_offset; 

	if (seconds && displayBigNumbers){
		space_between = SPACE_BETWEEN_BIG; 
		row_offset = ROW_WITH_SECONDS_BIG; 
		column_offset = COLUMN_BIG; 
	}

	else if (seconds){
		space_between = SPACE_BETWEEN_NORMAL; 
		row_offset = ROW_WITH_SECONDS_NORMAL; 
		column_offset = COLUMN_NORMAL; 
	}

	else if (displayBigNumbers){
		space_between = SPACE_BETWEEN_BIG; 
		row_offset = ROW_WITHOUT_SECONDS_BIG; 
		column_offset = COLUMN_BIG; 
	}

	else {
		space_between = SPACE_BETWEEN_NORMAL; 
		row_offset = ROW_WITHOUT_SECONDS_NORMAL; 
		column_offset = COLUMN_NORMAL; 
	}

	// Hours
	printNumber((int)(time->hours)/10, column_offset, 0*space_between + row_offset, displayBigNumbers); 
	printNumber((time->hours)%10, column_offset, 1*space_between + row_offset, displayBigNumbers); 

	// Colon 
	printNumber(10, column_offset, 2*space_between + row_offset, displayBigNumbers); 

	// Minutes
	printNumber((int)(time->minutes)/10, column_offset, 3*space_between + row_offset, displayBigNumbers); 
	printNumber((time->minutes)%10, column_offset, 4*space_between + row_offset, displayBigNumbers); 

	if (seconds){
		// Colon 
		printNumber(10, column_offset, 5*space_between + row_offset, displayBigNumbers); 

		// Seconds
		printNumber((int)(time->seconds)/10, column_offset, 6*space_between + row_offset, displayBigNumbers); 
		printNumber((time->seconds)%10, column_offset, 7*space_between + row_offset, displayBigNumbers); 
	}
}

void printNumber(int n, int y, int x, bool displayBigNumbers){
	char* numbers[11] = {
	    // 0
	    "#####\n"
	    "#  ##\n"
	    "# # #\n"
	    "##  #\n"
	    "#####\n",

	    // 1
	    " ##  \n"
	    "  #  \n"
	    "  #  \n"
	    "  #  \n"
	    " ### \n",

	    // 2
	    "#####\n"
	    "    #\n"
	    "#####\n"
	    "#    \n"
	    "#####\n",

	    // 3
	    "#####\n"
	    "    #\n"
	    " ####\n"
	    "    #\n"
	    "#####\n",

	    // 4
	    "#   #\n"
	    "#   #\n"
	    "#####\n"
	    "    #\n"
	    "    #\n",

	    // 5
	    "#####\n"
	    "#    \n"
	    "#####\n"
	    "    #\n"
	    "#####\n",

	    // 6
	    "#####\n"
	    "#    \n"
	    "#####\n"
	    "#   #\n"
	    "#####\n",

	    // 7
	    "#####\n"
	    "    #\n"
	    "   # \n"
	    "  #  \n"
	    " #   \n",

	    // 8
	    "#####\n"
	    "#   #\n"
	    "#####\n"
	    "#   #\n"
	    "#####\n",

	    // 9
	    "#####\n"
	    "#   #\n"
	    "#####\n"
	    "    #\n"
	    "#####\n",

	    // Colon :
	    "     \n"
	    "  #  \n"
	    "     \n"
	    "  #  \n"
	    "     \n"
	};

	char* bigNumbers[11] = {
	    // 0
	    "##########\n"
	    "##########\n"
	    "##    ####\n"
	    "##   ## ##\n"
	    "##  ##  ##\n"
	    "##  ##  ##\n"
	    "## ##   ##\n"
	    "####    ##\n"
	    "##########\n"
	    "##########\n",

	    // 1
	    "   ###    \n"
	    "  ####    \n"
	    "    ##    \n"
	    "    ##    \n"
	    "    ##    \n"
	    "    ##    \n"
	    "    ##    \n"
	    "    ##    \n"
	    " ######## \n"
	    " ######## \n",

	    // 2
	    "##########\n"
	    "##########\n"
	    "        ##\n"
	    "        ##\n"
	    "##########\n"
	    "##########\n"
	    "##        \n"
	    "##        \n"
	    "##########\n"
	    "##########\n",

	    // 3
	    "##########\n"
	    "##########\n"
	    "        ##\n"
	    "        ##\n"
	    "   #######\n"
	    "   #######\n"
	    "        ##\n"
	    "        ##\n"
	    "##########\n"
	    "##########\n",

	    // 4
	    "##      ##\n"
	    "##      ##\n"
	    "##      ##\n"
	    "##      ##\n"
	    "##########\n"
	    "##########\n"
	    "        ##\n"
	    "        ##\n"
	    "        ##\n"
	    "        ##\n",

	    // 5
	    "##########\n"
	    "##########\n"
	    "##        \n"
	    "##        \n"
	    "##########\n"
	    "##########\n"
	    "        ##\n"
	    "        ##\n"
	    "##########\n"
	    "##########\n",

	    // 6
	    "##########\n"
	    "##########\n"
	    "##        \n"
	    "##        \n"
	    "##########\n"
	    "##########\n"
	    "##      ##\n"
	    "##      ##\n"
	    "##########\n"
	    "##########\n",

	    // 7
	    "##########\n"
	    "##########\n"
	    "        ##\n"
	    "       ## \n"
	    "      ##  \n"
	    "     ##   \n"
	    "    ##    \n"
	    "   ##     \n"
	    "  ##      \n"
	    " ##       \n",

	    // 8
	    "##########\n"
	    "##########\n"
	    "##      ##\n"
	    "##      ##\n"
	    "##########\n"
	    "##########\n"
	    "##      ##\n"
	    "##      ##\n"
	    "##########\n"
	    "##########\n",

	    // 9
	    "##########\n"
	    "##########\n"
	    "##      ##\n"
	    "##      ##\n"
	    "##########\n"
	    "##########\n"
	    "        ##\n"
	    "        ##\n"
	    "##########\n"
	    "##########\n",

	    // Colon :
	    "          \n"
	    "          \n"
	    "    ##    \n"
	    "    ##    \n"
	    "          \n"
	    "          \n"
	    "    ##    \n"
	    "    ##    \n"
	    "          \n"
	    "          \n"
	};

        int i = 0, j = 0;

	char* num_str = numbers[n];

	if (displayBigNumbers){
		num_str = bigNumbers[n];
	}
       
        while (num_str[i] != '\0'){ 	// Print each character from the string
            if (num_str[i] == '\n'){
                j = 0;
                y++;
            } 

	    else {
                mvaddch(y, x + j, num_str[i]);
                j++;
            }

            i++;
        }
}
