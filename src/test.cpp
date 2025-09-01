#include "graph.h"
#include "astar.h"
#include "dfs.h"
#include <iostream>
using namespace std;

int main() {
    Graph g(true); // true = orientado, false = nao-orientado

    // Adicionar arestas conforme seu exemplo
    g.addEdge("a0", "b0", 95);
    g.addEdge("a0", "c0", 44);
    g.addEdge("a0", "d0", 98);
    g.addEdge("a0", "e0", 49);
    g.addEdge("b0", "c0", 60);
    g.addEdge("b0", "e0", 31);
    g.addEdge("b0", "f0", 44);
    g.addEdge("d0", "c0", 32);
    g.addEdge("d0", "e0", 28);
    g.addEdge("d0", "f0", 34);

    // Heurísticas
    g.setHeuristic("a0", 58);
    g.setHeuristic("b0", 24);
    g.setHeuristic("c0", 34);
    g.setHeuristic("d0", 37);
    g.setHeuristic("e0", 5);
    g.setHeuristic("f0", 0);

    // Rodar A*
    runAStar(g, "a0", "f0");
    runDFS(g, "a0", "f0");
}
