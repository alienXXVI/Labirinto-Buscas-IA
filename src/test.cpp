#include "graph.h"
#include "dfs.h"
#include <iostream>

using namespace std;

int main() {
    // =======================
    // GRAFO ORIENTADO
    // =======================
    Graph g_orientado(true);

    // Adicionar arestas
    g_orientado.addEdge("a0","b0",95);
    g_orientado.addEdge("a0","c0",44);
    g_orientado.addEdge("a0","d0",98);
    g_orientado.addEdge("a0","e0",49);
    g_orientado.addEdge("b0","c0",60);
    g_orientado.addEdge("b0","e0",31);
    g_orientado.addEdge("b0","f0",44);
    g_orientado.addEdge("d0","c0",32);
    g_orientado.addEdge("d0","e0",28);
    g_orientado.addEdge("d0","f0",34);

    // Definir heurísticas (não usado no DFS, mas útil para A*)
    g_orientado.setHeuristic("a0",58);
    g_orientado.setHeuristic("b0",24);
    g_orientado.setHeuristic("c0",34);
    g_orientado.setHeuristic("d0",37);
    g_orientado.setHeuristic("e0",5);
    g_orientado.setHeuristic("f0",0);

    cout << "===== GRAFO ORIENTADO =====" << endl;
    runDFS(g_orientado, "a0", "f0");

    cout << "\n\n";

    // =======================
    // GRAFO NÃO ORIENTADO
    // =======================
    Graph g_nao_orientado(false);

    // Adicionar as mesmas arestas
    g_nao_orientado.addEdge("a0","b0",95);
    g_nao_orientado.addEdge("a0","c0",44);
    g_nao_orientado.addEdge("a0","d0",98);
    g_nao_orientado.addEdge("a0","e0",49);
    g_nao_orientado.addEdge("b0","c0",60);
    g_nao_orientado.addEdge("b0","e0",31);
    g_nao_orientado.addEdge("b0","f0",44);
    g_nao_orientado.addEdge("d0","c0",32);
    g_nao_orientado.addEdge("d0","e0",28);
    g_nao_orientado.addEdge("d0","f0",34);

    // Mesmas heurísticas
    g_nao_orientado.setHeuristic("a0",58);
    g_nao_orientado.setHeuristic("b0",24);
    g_nao_orientado.setHeuristic("c0",34);
    g_nao_orientado.setHeuristic("d0",37);
    g_nao_orientado.setHeuristic("e0",5);
    g_nao_orientado.setHeuristic("f0",0);

    cout << "===== GRAFO NAO ORIENTADO =====" << endl;
    runDFS(g_nao_orientado, "a0", "f0");

    return 0;
}
