#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "graph.h"

// Função que lê o arquivo de entrada e popula o grafo
bool parseFile(const std::string &filename, Graph &grafo);

#endif
