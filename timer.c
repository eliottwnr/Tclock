#include <ncurses.h>
#include <unistd.h>

#include "timer.h"
#include "display.h"
#include "main.h"


void timerMode(bool secondsAreDisplayed, bool displayBigNumbers){
	Time null = {0, 0, 0}; 
	displayTime(&null, secondsAreDisplayed, displayBigNumbers); 

	char input = getch(); 
	while(input != 'q' && input != 'Q'){
		input = getch(); 
		if (input == SPACEBAR){
			timer(secondsAreDisplayed, displayBigNumbers); 
		}
		sleep(0.1); 
	}
}


void getWaitedTime(Time *start, Time *finish, Time *wait){
        int startSeconds = start->hours * 3600 + start->minutes * 60 + start->seconds;
        int finishSeconds = finish->hours * 3600 + finish->minutes * 60 + finish->seconds;
    
        int secondsWaited = finishSeconds - startSeconds;

	wait->hours = (int)(secondsWaited / 3600); 
	secondsWaited = secondsWaited % 3600; 
	wait->minutes = (int)(secondsWaited / 60); 
	wait->seconds = secondsWaited % 60; 
}


void timer(bool secondsAreDisplayed, bool displayBigNumbers){
	Time start, finish, waiting; 

	getCurrentTime(&start); 

	char stop = getch(); 
	int count = 0; 
	while (stop != SPACEBAR){
		getCurrentTime(&finish); 
		getWaitedTime(&start, &finish, &waiting); 

		if (count == 10000){
			count = 0; 
			clear(); 
		}

		displayTime(&waiting, secondsAreDisplayed, displayBigNumbers); 
		sleep(0.5); 

		stop = getch(); 
		count++; 
	}
}
