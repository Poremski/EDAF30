#include "dijkstra.h"
#include "edge.h"
#include <fstream>
#include "graph.h"
#include "node.h"
#include <string>
#include <vector>

void test_dijkstra();
void test_dijkstra_dijkstra_generalized_false();
void test_dijkstra_dijkstra_generalized_true();
void test_nodeset();
void test_graph_from_file();

int main ()
{
  test_dijkstra();
  test_dijkstra_dijkstra_generalized_false();
  test_dijkstra_dijkstra_generalized_true();
  test_nodeset();
  test_graph_from_file();
  return 0;
}

void test_bool(int id, bool error, std::string test, std::string msg)
{
  std::cout << "test_own - test_" << test << "_#" << id;
  if (error) std::cout << ": [ERROR] " << msg << std::endl;
  else std::cout << ": [OK]" << std::endl;
}

void test_dijkstra()
{
  Node lund{"Lund"};
  Node dalby{"Dalby"};
  Node sandby{"Sodra Sandby"};
  Node hallestad{"Torna Hallestad"};
  Node flyinge{"Flyinge"};
  Node veberod{"Veberod"};

  lund.addEdge(&dalby,12);
  lund.addEdge(&sandby,12);
  dalby.addEdge(&sandby,12);
  dalby.addEdge(&veberod,11);
  dalby.addEdge(&hallestad,5);
  sandby.addEdge(&lund,12);
  sandby.addEdge(&flyinge,4);
  hallestad.addEdge(&veberod,8);

  dijkstra(&lund);

  test_bool(1, lund.getValue() != 0, "dijkstra", "(lund.getValue() != 0) ej sant.");
  test_bool(2, dalby.getValue() != 12, "dijkstra", "(dalby.getValue() != 12) ej sant.");
  test_bool(3, sandby.getValue() != 12, "dijkstra", "(sandby.getValue() != 12) ej sant.");
  test_bool(4, hallestad.getValue() != 17, "dijkstra", "(hallestad.getValue() != 17) ej sant.");
  test_bool(5, veberod.getValue() != 23, "dijkstra", "(veberod.getValue() != 23) ej sant.");
  test_bool(6, flyinge.getValue() != 16, "dijkstra", "(flyinge.getValue() != 16) ej sant.");
}

void test_dijkstra_dijkstra_generalized_false()
{
  Node lund{"Lund"};
  Node dalby{"Dalby"};
  Node sandby{"Sodra Sandby"};
  Node hallestad{"Torna Hallestad"};
  Node flyinge{"Flyinge"};
  Node veberod{"Veberod"};

  lund.addEdge(&dalby,12);
  lund.addEdge(&sandby,12);
  dalby.addEdge(&sandby,12);
  dalby.addEdge(&veberod,11);
  dalby.addEdge(&hallestad,5);
  sandby.addEdge(&lund,12);
  sandby.addEdge(&flyinge,4);
  hallestad.addEdge(&veberod,8);

  std::string str = dijkstra_generalized(&lund, false);

  test_bool(1, lund.getValue() != 0, "dijkstra_generalized_false", "(lund.getValue() != 0) ej sant.");
  test_bool(2, dalby.getValue() != 12, "dijkstra_generalized_false", "(dalby.getValue() != 12) ej sant.");
  test_bool(3, sandby.getValue() != 12, "dijkstra_generalized_false", "(sandby.getValue() != 12) ej sant.");
  test_bool(4, hallestad.getValue() != 17, "dijkstra_generalized_false", "(hallestad.getValue() != 17) ej sant.");
  test_bool(5, veberod.getValue() != 23, "dijkstra_generalized_false", "(veberod.getValue() != 23) ej sant.");
  test_bool(6, flyinge.getValue() != 16, "dijkstra_generalized_false", "(flyinge.getValue() != 16) ej sant.");
}

void test_dijkstra_dijkstra_generalized_true()
{
  Node lund{"Lund"};
  Node dalby{"Dalby"};
  Node sandby{"Sodra Sandby"};
  Node hallestad{"Torna Hallestad"};
  Node flyinge{"Flyinge"};
  Node veberod{"Veberod"};

  lund.addEdge(&dalby,12);
  lund.addEdge(&sandby,12);
  dalby.addEdge(&sandby,12);
  dalby.addEdge(&veberod,11);
  dalby.addEdge(&hallestad,5);
  sandby.addEdge(&lund,12);
  sandby.addEdge(&flyinge,4);
  hallestad.addEdge(&veberod,8);

  std::string str = dijkstra_generalized(&lund, true);
  str = str.substr(str.rfind(' ')+1);
  str = str.substr(0, str.length()-1);

  test_bool(1, str.compare("2"), "dijkstra_generalized_true", "(!str.compare(\"2\")) ej sant.");
}

void test_nodeset()
{
  NodeSet ns{};
  Node a("A");
  a.setValue(10);
  Node b("B");
  b.setValue(20);
  Node c("C");
  c.setValue(30);

  ns.add(&a);
  ns.add(&b);
  ns.add(&c);

  Node* aa = ns.removeMin();
  test_bool(1, aa != &a, "nodeset", "(ns.removeMin() != &a) ej sant. Tog bort: " + aa->getName());
  Node* bb = ns.removeMin();
  test_bool(2, bb != &b, "nodeset", "(ns.removeMin() != &b) ej sant. Tog bort: " + bb->getName());
  Node* cc = ns.removeMin();
  test_bool(3, cc != &c, "nodeset", "(ns.removeMin() != &c) ej sant. Tog bort: " + cc->getName());
  test_bool(4, !ns.isEmpty(), "nodeset", "(ns.isEmpty()) ej sant.");

  ns.add(&a);
  test_bool(5, ns.isEmpty(), "nodeset", "(!ns.isEmpty()) ej sant.");
  ns.add(&b);
  test_bool(6, ns.isEmpty(), "nodeset", "(!ns.isEmpty()) ej sant.");
  ns.add(&c);
  test_bool(7, ns.isEmpty(), "nodeset", "(!ns.isEmpty()) ej sant.");

  a.setValue(40);
  bb = ns.removeMin();
  test_bool(1, bb != &b, "nodeset", "(ns.removeMin() != &b) ej sant. Tog bort: " + bb->getName());
  cc = ns.removeMin();
  test_bool(2, cc != &c, "nodeset", "(ns.removeMin() != &c) ej sant. Tog bort: " + cc->getName());
  aa = ns.removeMin();
  test_bool(3, aa != &a, "nodeset", "(ns.removeMin() != &a) ej sant. Tog bort: " + aa->getName());
}

void test_graph_from_file()
{
  std::ifstream i("graf.txt");
  Graph g(i);

  test_bool(1, g.find("Göteborg") != 0, "graph_from_file", "(g.find(\"Göteborg\") == 0) ej sant.");
  test_bool(2, g.find("Torna Hallestad") == 0, "graph_from_file", "(g.find(\"Torna Hallestad\") != 0) ej sant.");

  std::vector<Edge> lund = g.find("Lund")->getEdges();
  std::vector<Edge> torna = g.find("Torna Hallestad")->getEdges();

  test_bool(3, lund[4].getLength() != 19, "graph_from_file", "(lund[4].getLength() == 19) ej sant.");
  test_bool(4, torna[0].getLength() != 8, "graph_from_file", "(torna[0].getLength() == 8) ej sant.");

  lund[4].setLength(5);
  torna[0].setLength(5);
  test_bool(5, lund[4].getLength() != 5, "graph_from_file", "(lund[4].getLength() == 5) ej sant.");
  test_bool(6, torna[0].getLength() != 5, "graph_from_file", "(torna[0].getLength() == 5) ej sant.");
  test_bool(7, lund[3].getDest()->getName().compare("Staffanstorp") != 0, "graph_from_file", "(lund[3].getDest()->getName().compare(\"Staffanstorp\") == 0) ej sant.");
  test_bool(8, torna[1].getDest()->getName().compare("Sodra Sandby") != 0, "graph_from_file", "(torna[1].getDest()->getName().compare(\"Sodra Sandby\") == 0) ej sant.");
}
