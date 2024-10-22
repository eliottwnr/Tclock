#ifndef TIMER_H
#define TIMER_H

#include "main.h"


#define SPACEBAR 32

void timerMode(bool secondsAreDisplayed, bool displayBigNumbers); 
void getWaitedTime(Time *start, Time *finish, Time *wait); 
void timer(bool secondsAreDisplayed, bool displayBigNumbers); 

#endif 
