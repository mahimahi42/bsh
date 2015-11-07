CC=gcc

SRCDIR=src
BINDIR=bin
INCDIR=$(SRCDIR)/include
DIR_GUARD=@mkdir -p $(@D)

WARNFLAGS=-Wall -Wextra -pedantic
CFLAGS=-I$(INCDIR) $(WARNFLAGS) -std=c11 -fPIC
SOURCES:=$(shell find $(SRCDIR) -name '*.c')
OBJECTS:=$(SOURCES:.c=.o)
VPATH=src

appname=bsh
APP=$(BINDIR)/$(appname)

all: $(APP) doc

$(APP): $(OBJECTS)
	$(DIR_GUARD)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(DIR_GUARD)
	$(CC) $(CFLAGS) $(WARNFLAGS) -c $< -o $@

doc:
	doxygen Doxyfile

clean: doc_clean
	rm -rf src/*.o

doc_clean:
	rm -rf doc/*