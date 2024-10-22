all: package

package: /main.c /main.h /display.c /display.h /timer.c /timer.h
	cc /main.c /display.c /timer.c -o tClock -lncurses

clean: 
	rm -f package
