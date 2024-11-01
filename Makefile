COMPILER = cc
SOURCES = src/main.c src/display.c src/timer.c
OUTPUT = tclock
OPTIONS = -lncurses

all: 
	$(COMPILER) $(SOURCES) -o $(OUTPUT) $(OPTIONS)
