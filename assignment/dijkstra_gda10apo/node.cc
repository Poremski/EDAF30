#include "node.h"

/**
 * Skapar en nod med givet namn, utan bågar och med maximalt värde.
 */
Node::Node(const std::string& name) : name(name), value(max_value), parent(0) {}

/**
 * Hämtar nodes namn.
 */
std::string Node::getName() const
{
  return name;
}

/**
 * Sätter nodes värde till v.
 */
void Node::setValue(int v)
{
  value = v;
}

/**
 * Hämtar nodes värde.
 */
int Node::getValue() const
{
  return value;
}

/**
 * Lägger till en ny båge från denna nod till en given destination.
 * Bågen ska ha längden length.
 */
void Node::addEdge(Node* destination, int length)
{
  Edge edge(destination, length);
  edges.push_back(edge);
}

/**
 * Hämtar de bågar som utgår från denna nod.
 */
const std::vector<Edge>& Node::getEdges() const
{
  return edges;
}

/**
 * Lägger in nodförälder (nodens föregångare).
 */
void Node::setParent(Node*& node)
{
  parent = node;
}

/**
 * Returnerar nodförälder (nodens föregångare).
 */
Node* Node::getParent()
{
  return parent;
}
