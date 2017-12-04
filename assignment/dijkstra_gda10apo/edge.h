#ifndef __EDGE_H
#define __EDGE_H

#include "node.h"
#include <string>
#include <vector>

class Node;

class Edge
{
  public:
    /**
     * Skapa en ny båge till noden destination, med längden length.
     */
    Edge(Node* destination, int length);
    /**
     * Hämtar bågens destination.
     */
    Node* getDest() const;
    /**
     * Hämtar bågens längd.
     */
    int getLength() const;
    /**
     * Sätter bågens längd.
     */
    void setLength(int length);
  private:
    Node* destination;
    int length{0};
};

#endif
