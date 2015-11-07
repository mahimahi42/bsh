CC=gcc
SRCDIR=src
BINDIR=bin
OBJDIR=obj
INCDIR=$(SRCDIR)/include
WARNFLAGS=-Wall -Wextra -pedantic
CFLAGS=-I$(INCDIR) $(WARNFLAGS) -std=c11
SOURCES:=$(shell find $(SRCDIR) -name '*.c')
OBJECTS=$(SOURCES:.c=.o)

VPATH=src

appname=bsh
APP=$(BINDIR)/$(appname)

.PHONY: all doc clean

all: $(APP) doc

doc:
	doxygen Doxyfile

$(APP): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CC) -o $@ $(CFLAGS) $(WARNFLAGS) -c $<

clean: doc_clean
	rm -rf src/*.o

doc_clean:
	rm -rf doc/*

obj_clean:
	rm -rf obj/