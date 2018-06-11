CC := g++
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGETNAME := ov
TARGET := $(TARGETDIR)/$(TARGETNAME)

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall
LIB := -L lib -lstdc++ -lyaml-cpp
INC := -I include

TEST_NAME := tester
TEST_TARGET := $(TARGETDIR)/$(TEST_NAME)
TEST_DIR := test
TEST_SOURCES := $(shell find $(TEST_DIR) -type f -name *.$(SRCEXT))
TEST_LIB := -L lib -lstdc++ -lgtest -pthread

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGETDIR)"; $(RM) -r $(BUILDDIR) $(TARGETDIR)

# Tests
tester:
	@mkdir -p $(TARGETDIR)
	$(CC) $(CFLAGS) $(TEST_SOURCES) $(INC) $(TEST_LIB) -o $(TEST_TARGET)

.PHONY: clean