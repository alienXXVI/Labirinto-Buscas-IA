#ifndef ASTAR_H
#define ASTAR_H

#include "graph.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Estrutura que representa o estado de um nó durante a execução do algoritmo A*.
 *
 * O algoritmo A* utiliza a combinação de:
 *  - g(n): custo acumulado do nó inicial até o nó atual;
 *  - h(n): estimativa heurística de custo do nó atual até o objetivo;
 *  - f(n) = g(n) + h(n): função de avaliação que guia a busca.
 */
struct AStarState {
    string node;            ///< Nome ou identificador do nó atual.
    int g;                  ///< Custo acumulado até o nó atual (g(n)).
    int f;                  ///< Função de avaliação f(n) = g(n) + h(n).
    vector<string> path;    ///< Caminho percorrido desde o nó inicial até este estado.
};

/**
 * @brief Executa o algoritmo de busca A* em um grafo.
 *
 * @param grafo Estrutura do grafo que contém os nós, arestas e heurísticas.
 * @param start Nó inicial da busca.
 * @param goal Nó objetivo da busca.
 */
void runAStar(const Graph &grafo, const string &start, const string &goal);

#endif
