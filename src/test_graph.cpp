#include "graph.h"
#include <iostream>
#include <iomanip> // para setw
using namespace std;

int main() {
    // Criar grafo não orientado (false)
    Graph g(false);

    // Adicionar nós e arestas
    g.addEdge("a0", "b0", 95);
    g.addEdge("a0", "c0", 44);
    g.addEdge("b0", "f0", 50);
    g.addEdge("c0", "d0", 70);
    g.addEdge("d0", "e0", 30);
    g.addEdge("e0", "f0", 10);

    // Definir heurísticas
    g.setHeuristic("a0", 58);
    g.setHeuristic("b0", 24);
    g.setHeuristic("c0", 34);
    g.setHeuristic("d0", 12);
    g.setHeuristic("e0", 7);
    g.setHeuristic("f0", 0);

    // Mostrar se é orientado
    cout << "O grafo eh orientado? " << (g.isOriented() ? "Sim" : "Nao") << "\n\n";

    // Mostrar toda a estrutura do grafo
    cout << "Estrutura do Grafo:\n";
    for (auto const& [name, node] : g.nodes) {
        cout << "No " << name << " (heuristica: " << node.heuristic << ")\n";
        for (auto const& edge : g.getNeighbors(name)) {
            cout << "   -> " << setw(3) << edge.to 
                 << " (custo: " << edge.cost << ")\n";
        }
        cout << endl;
    }

    return 0;
}
