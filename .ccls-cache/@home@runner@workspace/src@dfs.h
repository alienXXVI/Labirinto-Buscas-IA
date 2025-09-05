#ifndef DFS_H
#define DFS_H
#include "graph.h"
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

/**
 * @brief Estrutura que representa o estado de um nó durante a execução do algoritmo de DFS.
 */
struct DFSState {
    string node;            ///< Identificador do nó atual.
    int g;                  ///< Custo acumulado até o nó atual (g(n)).
    vector<string> path;    ///< Caminho percorrido desde a origem até este nó.
};

/**
 * @brief Executa o algoritmo de busca em profundidade (DFS) em um grafo.
 * 
 * @param grafo Grafo em que o algoritmo será executado.
 * @param start Nó inicial da busca.
 * @param goal Nó objetivo da busca.
 */
void runDFS(const Graph &grafo, const string &start, const string &goal);


#endif
