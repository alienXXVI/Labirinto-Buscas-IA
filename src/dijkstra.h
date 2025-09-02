#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <string>

using namespace std;

// Estado de cada nó na fronteira
struct DijkstraState {
    string node;           // nó atual
    int cost;              // custo acumulado até aqui
    vector<string> path;   // caminho percorrido

    // Ordenação por custo (menor custo tem maior prioridade)
    bool operator<(const DijkstraState &other) const {
        return cost > other.cost; // invertido para priority_queue ou ordenação crescente manual
    }
};

void runDijkstra(const Graph &grafo, const string &start, const string &goal);

#endif
