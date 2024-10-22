#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>

#include "main.h"
#include "display.h"
#include "timer.h"


int main(int argc, char *argv[]){
	initCurses(); 

	Time currentTime; 
	getCurrentTime(&currentTime); 

	bool secondsAreDisplayed = false; 
	bool displayBigNumbers = false; 
	bool switchTimer = false; 

	for (int i = 1; i < argc; i++){
		if (*argv[i] == 's'){
			secondsAreDisplayed = true; 
		}

		else if (*argv[i] == 'b'){
			displayBigNumbers = true; 
		}

		else if (*argv[i] == 't'){
			switchTimer = true; 
		}
	}

	if (switchTimer == true){
		timerMode(secondsAreDisplayed, displayBigNumbers); 

		endwin(); 
		return 0; 
	}


	char exit = getch(); 
	while (exit != 'q'){ 			// while no input
		exit = getch(); 

		if (currentTime.seconds % 5 == 4){ 		// reset screen every 5 seconds & resync clock 
			sleep(1); 
			clear(); 
			getCurrentTime(&currentTime); 
		}

		else {
			sleep(1); 
			currentTime.seconds++; 
		}

		displayTime(&currentTime, secondsAreDisplayed, displayBigNumbers); 
	}

	endwin(); 
	return 0; 
}

void getCurrentTime(Time *currentTime){
	time_t now = time(NULL); 
	struct tm *tm_struct = localtime(&now); 

	currentTime->hours = tm_struct->tm_hour; 
	currentTime->minutes = tm_struct->tm_min; 
	currentTime->seconds = tm_struct->tm_sec; 
}
