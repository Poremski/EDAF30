CXX = g++
CC = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

CPPFLAGS = -std=c++11 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
CXXFLAGS += -DINFO

PROGS = test_nodeset test_graph_small test_graph_nofile test_dijkstra test_own

all: $(PROGS)

test_nodeset: test_nodeset.o nodeset.o node.o edge.o
test_graph_small: test_graph_small.o graph.o nodeset.o node.o edge.o
test_graph_nofile: test_graph_nofile.o graph.o nodeset.o node.o edge.o
test_dijkstra: test_dijkstra.o graph.o nodeset.o node.o edge.o dijkstra.o
test_own: test_own.o graph.o nodeset.o node.o edge.o dijkstra.o

run_all:
	./test_nodeset
	./test_graph_small
	./test_graph_nofile
	./test_dijkstra
	./test_own

run_own:
	./test_own

run_pre:
	./test_nodeset
	./test_graph_small
	./test_graph_nofile
	./test_dijkstra

.PHONY: all test clean distclean

clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

SRC = $(wildcard *.cc)
	-include $(SRC:.cc=.d)
