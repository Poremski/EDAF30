#ifndef __NODE_H
#define __NODE_H

#include "edge.h"
#include <string>
#include <vector>

class Edge;

class Node
{
  public:
    /**
     * Skapar en nod med givet namn, utan bågar och med maximalt värde.
     */
  	Node(const std::string& name);
    /**
     * Hämtar nodes namn.
     */
    std::string getName() const;
    /**
     * Sätter nodes värde till v.
     */
    void setValue(int v);
    /**
     * Hämtar nodes värde.
     */
    int getValue() const;
    /**
     * Lägger till en ny båge från denna nod till en given destination.
     * Bågen ska ha längden length.
     */
    void addEdge(Node* destination, int length);
    /**
     * Hämtar de bågar som utgår från denna nod.
     */
    const std::vector<Edge>& getEdges() const;
    /**
     * Lägger in nodförälder (nodens föregångare).
     */
    void setParent(Node*& node);
    /**
     * Returnerar nodförälder (nodens föregångare).
     */
    Node* getParent();
    /**
     * Anger int:s maxvärde.
     */
    static const unsigned int max_value = std::numeric_limits<int>::max();
  private:
    std::string name;
    int value;
    Node* parent = nullptr;
    std::vector<Edge> edges;
};

#endif
