#ifndef __DIJKSTRA_H
#define __DIJKSTRA_H

#include <algorithm>
#include <iostream>
#include "node.h"
#include "nodeset.h"
#include <sstream>
#include <string>
#include <vector>

void dijkstra(Node* start);
std::string dijkstra_generalized(Node* start, bool by_localities);

#endif
