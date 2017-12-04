#include "graph.h"

/**
 * Dela upp strängen enligt:
 * `Lund: 12 Dalby` => {city1}: {cost} {city2}
 */
void Graph::sub_str(std::string& str, std::string& city1, std::string& cost, std::string& city2)
{
  city1 = str.substr(0, str.find(':'));
  str = str.substr(str.find(':')+2);
  cost = str.substr(0, str.find(' '));
  city2 = str.substr(str.find(' ')+1);
}

/**
 * Returnera noden efter givet namn.
 * Om noden inte existerar returneras null.
 */
Node* Graph::find(const std::string& name)
{
  Node* tmp = 0;
  for (auto it = nodes.begin(); it != nodes.end(); ++it)
  {
    if (!name.compare((*it)->getName()))
    {
      tmp = (*it);
    }
  }
  return tmp;
}

/**
 * Lägg in en ny nod med ett givet namn.
 * Om det givna namnet existerar läggs inte noden in.
 */
void Graph::addNode(const std::string& name)
{
  if (find(name) == 0)
  {
    nodes.push_back(new Node(name));
  }
}

/**
 * Återställ alla nodernas värde till det initiala maxvärdet.
 */
void Graph::resetVals()
{
  for (auto it = nodes.begin(); it != nodes.end(); ++it)
  {
    (*it)->setValue((*it)->max_value);
  }
}

/**
 * Läs in data från fil.
 */
Graph::Graph(std::istream& in)
{
  std::string str, city1, cost, city2;
  while (getline(in, str))
  {
    sub_str(str, city1, cost, city2);

    addNode(city1);
    addNode(city2);

    Node* from = find(city1);
    Node* dest = find(city2);

    from -> addEdge(dest, std::stoi(cost));
  }
}
