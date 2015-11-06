SRCDIR=src
BINDIR=bin
INCDIR=$(SRCDIR)/include
WARNFLAGS=-Wall -Wextra -pedantic
CFLAGS=-I$(INCDIR) $(WARNFLAGS) -std=c11
SOURCES:=$(shell find $(SRCDIR) -name '*.c')
OBJECTS=$(SOURCES:.c=.o)
#LINK.o=$(LINK.c)
#OBJECTS=$(shell for obj in `find $(SRCDIR)/ -name *.c`;do sed 's/.c/.o/g';done)

appname=bsh
APP=$(BINDIR)/$(appname)

all: $(APP)

$(APP): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CC) -c $(CFLAGS) $(WARNFLAGS) $< -o $@

clean:
	rm -rf src/*.o


#$(BINDIR)/$(appname): $(OBJECTS)

#$(OBJECTS): $(SRCDIR)