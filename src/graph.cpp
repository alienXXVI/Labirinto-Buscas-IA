#include "graph.h"

void Graph::addNode(const std::string &nome) {
    if (nodes.find(nome) == nodes.end()) {
        Node n;
        n.nome = nome;
        nodes[nome] = n;
    }
}

void Graph::addEdge(const std::string &origem, const std::string &destino, int custo) {
    nodes[origem].vizinhos.push_back({destino, custo});
}

Node* Graph::getNode(const std::string &nome) {
    if (nodes.find(nome) != nodes.end()) {
        return &nodes[nome];
    }
    return nullptr;
}
