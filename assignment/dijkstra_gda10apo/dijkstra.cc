#include "dijkstra.h"
/**
 * Dijkstras algoritm. Varje nod som kan nås från start ges ett värde,
 * där värdet anger det kortaste avståndet från noden start.
 * Alla noder förutsätts, när funktionen anropas, ha ett värde som är
 * större än alla faktiska avstånd i grafen.
 */
void dijkstra(Node* start)
{
  NodeSet ns{};
  start->setValue(0);
  ns.add(start);

  while (!ns.isEmpty())
  {
    Node* n = ns.removeMin();
    for (Edge e : n->getEdges())
    {
      int l = e.getLength();
      Node* d = e.getDest();
      int a = n->getValue() + l;
      if (a < d->getValue())
      {
        d->setValue(a);
        ns.add(d);
      }
    }
  }
}

/**
 * Den generaliserade Dijkstra-funktionen.
 * - Falsk 'by_localities' ger kortaste vägavstånd.
 * - Sann 'by_localities' ger minst antal passerande orter.
 */
std::string dijkstra_generalized(Node* start, bool by_localities)
{
  NodeSet ns{};
  start->setValue(0);
  ns.add(start);

  Node* dest;

  while (!ns.isEmpty())
  {
    Node* n = ns.removeMin();
    for (Edge e : n->getEdges())
    {
      if (by_localities) e.setLength(1);
      int l = e.getLength();
      Node* d = e.getDest();
      int a = n->getValue() + l;
      if (a < d->getValue())
      {
        d->setValue(a);
        d->setParent(n);
        ns.add(d);
        dest = d;
      }
    }
  }

  std::vector<Node*> reverse;
  while (dest != nullptr)
  {
    reverse.push_back(dest);
    dest = dest->getParent();
  }

  std::reverse(reverse.begin(), reverse.end());

  std::ostringstream stream;
  int v = 0;
  for (auto n : reverse)
  {
    if (by_localities) v += 1;
    else v += n->getValue();
    stream << n->getName() << " ";
  }
  if (by_localities) --v;
  stream << v << "\n";

  return stream.str();

}
