#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <string>

using namespace std;

/**
 * @struct DijkstraState
 * @brief Estrutura que representa o estado de um nó durante a execução do algoritmo de Dijkstra.
 */
struct DijkstraState {
    string node;            ///< Identificador do nó atual.
    int g;                  ///< Custo acumulado até o nó atual (g(n)).
    vector<string> path;    ///< Caminho percorrido desde a origem até este nó.

    /**
     * @brief Operador de comparação para ordenação por custo.
     *
     * @param other Outro estado de Dijkstra para comparação.
     * @return true se este estado tiver custo maior que o outro.
     */
    bool operator<(const DijkstraState &other) const {
        return g > other.g;
    }
};

/**
 * @brief Executa o algoritmo de Dijkstra em um grafo.
 *
 * @param grafo Grafo em que o algoritmo será executado.
 * @param start Nó inicial da busca.
 * @param goal Nó objetivo da busca.
 */
void runDijkstra(const Graph &grafo, const string &start, const string &goal);

#endif
