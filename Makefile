COMPILER = cc
SOURCES = src/main.c src/display.c src/timer.c
OUTPUT = tclock
OPTIONS = -lncurses

all: 
	$(COMPILER) $(SOURCES) -o $(OUTPUT) $(OPTIONS)

clean:
	rm -rvf pkg src/*.o $(OUTPUT) tclock*.pkg.tar.zst

.PHONY: all clean 
