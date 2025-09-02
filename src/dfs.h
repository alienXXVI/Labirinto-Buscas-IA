#ifndef DFS_H
#define DFS_H
#include "graph.h"
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

/**
 * @brief Estrutura auxiliar para representar estado da pilha no DFS.
 */
struct DFSState {
    string node;            ///< Nó atual
    int cost;               ///< Custo acumulado até aqui
    vector<string> path;    ///< Caminho percorrido até aqui
};

/**
 * @brief Executa o algoritmo de busca em profundidade (DFS).
 * 
 * @param grafo Referência ao grafo.
 * @param start Nó inicial.
 * @param goal Nó final (objetivo).
 */
void runDFS(const Graph &grafo, const string &start, const string &goal);


#endif
