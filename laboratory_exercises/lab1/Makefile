CXX = g++
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11

all: test_editor

clean:
	rm -f *.o test_editor

.PHONY: all
.PHONY: clean

# The following rule means: "if test_editor does not exist, or
# is older than test_editor.o or editor.o,
# then link test_editor".
test_editor: test_editor.o editor.o
	g++ -o test_editor test_editor.o editor.o

# Rules to create the object files.
test_editor.o: test_editor.cc editor.h
	g++ -c test_editor.cc -std=c++11
editor.o: editor.cc editor.h
	g++ -c editor.cc -std=c++11

print_argv: print_argv.o
	g++ -o print_argv print_argv.o
print_argv.o: print_argv.cc
	g++ -c print_argv.cc -std=c++11
