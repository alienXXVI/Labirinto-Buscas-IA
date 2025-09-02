#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "graph.h"

using namespace std;

/**
 * @brief Faz o parse do arquivo e popula o grafo.
 * @param filename Nome do arquivo (dentro de input/ ou ../input/).
 * @param grafo Estrutura de grafo a ser preenchida.
 * @param startNode Nome do nó inicial (retornado pela função).
 * @param goalNode Nome do nó objetivo/meta (retornado pela função).
 * @return true se leitura foi bem sucedida; false caso contrário.
 */
bool parseFile(const string &filename, Graph &grafo,
               string &startNode, string &goalNode);

#endif
