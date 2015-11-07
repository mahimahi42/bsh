SRCDIR=src
BINDIR=bin
INCDIR=$(SRCDIR)/include
WARNFLAGS=-Wall -Wextra -pedantic
CFLAGS=-I$(INCDIR) $(WARNFLAGS) -std=c11
SOURCES:=$(shell find $(SRCDIR) -name '*.c')
OBJECTS=$(SOURCES:.c=.o)

appname=bsh
APP=$(BINDIR)/$(appname)

all: $(APP) doc

doc: $(SOURCES)
	doxygen Doxyfile

$(APP): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CC) -c $(CFLAGS) $(WARNFLAGS) $< -o $@

clean: doc_clean
	rm -rf src/*.o

doc_clean:
	rm -rf doc/*