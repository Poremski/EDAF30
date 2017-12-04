#include "nodeset.h"

/**
 * Lägger till noden node till mängden,
 * om mängden inte redan innehåller en nod med samma namn.
 */
void NodeSet::add(Node* node)
{
  elements.push_back(node);
}

/**
 * Returnerar true om mängden noder är tom.
 */
bool NodeSet::isEmpty()
{
  return elements.size() == 0;
}

/**
 * Väljer ut den nod som har lägst värde och returnerar den.
 * Den returnerade noden tas bort ur mängden.
 * Om mängden är tom returneras null.
 */
Node* NodeSet::removeMin()
{
  if (isEmpty()) return 0;
  else
  {
    Node* tmp = 0;
    int min = std::numeric_limits<int>::max();
    unsigned int j = 0;
    for (unsigned int i = 0; i < elements.size(); ++i)
    {
      if (elements[i]->getValue() < min)
      {
        tmp = elements[i];
        min = elements[i]->getValue();
        j = i;
      }
    }
    elements.erase(elements.begin() + j);
    return tmp;
  }
}
