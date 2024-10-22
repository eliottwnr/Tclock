all: package

package: src/main.c src/main.h src/display.c src/display.h src/timer.c src/timer.h
	cc src/main.c src/display.c src/timer.c -o tClock -lncurses

clean: 
	rm -f package
