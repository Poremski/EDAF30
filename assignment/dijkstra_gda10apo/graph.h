#ifndef __GRAPH_H
#define __GRAPH_H

#include <fstream>
#include <iostream>
#include "node.h"
#include <vector>

class Graph
{
  public:
    /**
     * Konstruktor
     */
    Graph() : nodes() {};
    /**
     * Läs in data från fil.
     */
    Graph(std::istream& in);
    /**
     * Lägg in en ny nod med ett givet namn.
     * Om det givna namnet existerar läggs inte noden in.
     */
    void addNode(const std::string& name);
    /**
     * Dela upp strängen enligt:
     * `Lund: 12 Dalby` => {city1}: {cost} {city2}
     */
    void sub_str(std::string& str, std::string& city1, std::string& cost, std::string& city2);
    /**
     * Returnera noden efter givet namn.
     * Om noden inte existerar returneras null.
     */
    Node* find(const std::string& name);
    /**
     * Återställ alla nodernas värde till det initiala maxvärdet.
     */
    void resetVals();
    /**
     * Returnerar iterator begin() för node-vektorn. (Används i test_graph_nofile.cc)
     */
    std::vector<Node*>::iterator begin() { return nodes.begin(); };
    /**
     * Returnerar iterator end() för node-vektorn. (Används i test_graph_nofile.cc)
     */
    std::vector<Node*>::iterator end() { return nodes.end(); };
  private:
    std::vector<Node*> nodes;
};

#endif
