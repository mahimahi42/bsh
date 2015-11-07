# Compiler
CC := gcc

# Target (final program)
TARGET := bsh

# Directories
SRCDIR := src
BINDIR := bin
DOCDIR := doc
BUILDDIR := obj
INCDIR := $(SRCDIR)/include

# File extensions
SRCEXT := c
DEPEXT := d
OBJEXT := o

# Flags
INC := -I$(INCDIR)
WFLAGS := -Wall -Wextra -pedantic
CFLAGS := $(WFLAGS) -std=c11 -g

# Sources & Objects
SOURCES := $(shell find $(SRCDIR) -name '*.$(SRCEXT)')
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

# Non-file targets
.PHONY: all dirs doc clean bin_clean doc_clean obj_clean

# Default target
all: dirs $(TARGET)

# Remake target for development
remake: clean all

# Setup necessary directories
dirs:
	@mkdir -p $(BINDIR)
	@mkdir -p $(DOCDIR)
	@mkdir -p $(BUILDDIR)

# Documentation
doc:
	doxygen Doxyfile

# Get dependency info for existing object files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# Link object files into executable
$(TARGET): $(OBJECTS)
	$(CC) -o $(BINDIR)/$(TARGET) $^

# Compile object files
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	# Generate dependencies
	@$(CC) $(CFLAGS) $(INC) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@$(RM) $(BUILDDIR)/$*.$(DEPEXT).tmp

# Cleaning
clean: bin_clean doc_clean obj_clean

# Clean binaries
bin_clean:
	$(RM) -rf $(BINDIR)

# Clean documentation
doc_clean:
	$(RM) -rf $(DOCDIR)

# Clean object files
obj_clean:
	$(RM) -rf $(BUILDDIR)

# $(APP): $(OBJECTS)
# 	$(DIR_GUARD)
# 	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# %.o: %.c
# 	$(DIR_GUARD)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean: doc_clean
# 	rm -rf src/*.o

# doc_clean:
# 	rm -rf doc/*