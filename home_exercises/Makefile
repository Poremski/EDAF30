CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)

PROGS = hello

all: $(PROGS)

test: hello
	./hello

hello: hello.o

.PHONY: all test clean distclean

clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

SRC = $(wildcard *.cc)
	-include $(SRC:.cc=.d)
