# Tclock 

![tclock](images/tclock.jpeg) 
![tclock with b and s options](images/tclock_b_s.jpeg) 

# Introduction

This program is a terminal clock written in C with a ncurses tui and performances efficient.


# Usage

Simply run `./tClock` with `s` option to display seconds and/or `b` to display bold numbers.
> To display both bold numbers and seconds: `./tClock b s`


Run `./tClock` with `o` option for one-shot mode, which displays the time directly in the console. 
> `o` option will ignore all others

**Hit `q` or `Q` to quit.**


# Chronometer

`./tClock t` combined with `s` and/or `b` option runs tClock on chronometer mode. Hit the spacebar in order to start/stop the chronometer. 


# Compiling from source

Use your favorite compiler (here cc):
```sh
cc src/main.c src/display.c src/timer.c -o tClock -lncurses
```
in the project's root directory.
