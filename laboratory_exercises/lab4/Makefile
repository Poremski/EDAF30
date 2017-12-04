CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g

PROGS =  TagRemover Primes date_test TestToString TestStringCast

all: $(PROGS)

test: TagRemover Primes date_test TestToString TestStringCast
	./TagRemover
	./Primes
	./date_test
	./TestToString
	./TestStringCast

TagRemover: TestTagRemover.o TagRemover.o
Primes: TestPrimes.o Primes.o
date_test: date_test.o date.o
TestToString: TestToString.o date.o
TestStringCast: TestStringCast.o date.o

.PHONY: all test clean distclean

clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
