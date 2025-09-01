#ifndef ASTAR_H
#define ASTAR_H

#include "graph.h"
#include <string>
#include <vector>

using namespace std;

struct AStarState {
    string node;
    int g;                // custo acumulado até aqui
    int f;                // f(n) = g(n) + h(n)
    vector<string> path;  // caminho percorrido
};

void runAStar(const Graph &grafo, const string &start, const string &goal);

#endif
