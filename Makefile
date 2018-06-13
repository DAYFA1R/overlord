CXX ?= g++
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGETNAME := ov
TARGET := $(TARGETDIR)/$(TARGETNAME)

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -std=c++11
LIB := -L lib -lyaml-cpp
INC := -I include

TEST_NAME := run_tests
TEST_TARGET := $(TARGETDIR)/$(TEST_NAME)
TEST_DIR := test
TEST_SOURCES := $(shell find $(TEST_DIR) -type f -name *.$(SRCEXT))
TEST_LIB := -L lib -lgtest -pthread
GTEST_DIR := $(TEST_DIR)/googletest-release-1.8.0/googletest

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo " Linking..."
	@echo " $(CXX) $^ -o $(TARGET) $(LIB)"; $(CXX) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CXX) $(CFLAGS) $(INC) -c -o $@ $<"; $(CXX) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGETDIR)"; $(RM) -r $(BUILDDIR) $(TARGETDIR)

# Tests
tests:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)/test

	$(CXX) -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) \
		-pthread -c $(GTEST_DIR)/src/gtest-all.cc -o $(BUILDDIR)/test/gtest-all.o

	ar -rv lib/libgtest.a $(BUILDDIR)/test/gtest-all.o

	$(CXX) -isystem ${GTEST_DIR}/include $(INC) -pthread $(TEST_SOURCES) lib/libgtest.a \
    	-o $(TEST_TARGET)

.PHONY: clean