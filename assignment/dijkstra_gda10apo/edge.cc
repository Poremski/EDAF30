#include "edge.h"

/**
 * Skapa en ny båge till noden destination, med längden length.
 */
Edge::Edge(Node* destination, int length) : destination(destination), length(length) {}

/**
 * Hämtar bågens destination.
 */
Node* Edge::getDest() const
{
  return destination;
}

/**
 * Hämtar bågens längd.
 */
int Edge::getLength() const
{
  return length;
}

/**
 * Sätter bågens längd.
 */
void Edge::setLength(int length)
{
  this->length = length;
}
