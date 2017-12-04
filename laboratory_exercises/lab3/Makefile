CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g

PROGS =  TestUserTable

all: $(PROGS)

User: User.o
UserTable: UserTable.o User.o
TestUserTable: TestUserTable.o UserTable.o

.PHONY: all test clean distclean

clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
