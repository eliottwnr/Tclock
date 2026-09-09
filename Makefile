CC ?= cc
CFLAGS ?= -Wall -Wextra -O2
LDFLAGS ?=
LDLIBS ?= -lncurses

PREFIX ?= /usr/local
BINDIR ?= $(PREFIX)/bin

SOURCES = src/main.c src/display.c src/timer.c
OUTPUT = tclock

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $(OUTPUT) $(LDLIBS)

install: $(OUTPUT)
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 $(OUTPUT) $(DESTDIR)$(BINDIR)/$(OUTPUT)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(OUTPUT)

clean:
	rm -rf $(OUTPUT)

.PHONY: all install uninstall clean

