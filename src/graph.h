#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

struct Edge {
    std::string destino;
    int custo;
};

struct Node {
    std::string nome;
    std::vector<Edge> vizinhos;
    int h = 0; // heurística (distância em linha reta até objetivo)
};

class Graph {
public:
    std::map<std::string, Node> nodes;
    std::string start;
    std::string goal;

    void addNode(const std::string &nome);
    void addEdge(const std::string &origem, const std::string &destino, int custo);
    Node* getNode(const std::string &nome);
};

#endif
