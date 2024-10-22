COMPILER = cc
SOURCES = src/main.c src/display.c src/timer.c
OUTPUT = tclock
OPTIONS = -lncurses

all: 
	$(COMPILER) $(SOURCES) -o $(OUTPUT) $(OPTIONS)


.PHONY: clean 
clean: 
		echo "Removing all make files"
		rm -rvf pkg src tclock tclock-1-1-any.pkg.tar.zst tclock-debug-1-1-any.pkg.tar.zst
