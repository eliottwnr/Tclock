#ifndef MAIN_H
#define MAIN_H

typedef struct Time Time; 
struct Time {
	int hours; 
	int minutes; 
	int seconds; 
}; 

void getCurrentTime(Time *currentTime); 

#endif 
