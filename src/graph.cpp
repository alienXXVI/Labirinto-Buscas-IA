#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(bool oriented) {
    this->oriented = oriented;
}

void Graph::setOriented(bool val) {
    oriented = val;
}

bool Graph::isOriented() const { // entender
    return oriented;
}

void Graph::addNode(const string &name) { // entender
    if (nodes.find(name) == nodes.end()) {
        nodes[name] = Node{name, {}, 0};
    }
}

void Graph::addEdge(const string &from, const string &to, int cost) {
    addNode(from);
    addNode(to);

    nodes[from].neighbors.push_back({to, cost});
    if (!oriented) {
        nodes[to].neighbors.push_back({from, cost});
    }
}

void Graph::setHeuristic(const string &node, int h) {
    if (nodes.find(node) != nodes.end()) {
        nodes[node].heuristic = h;
    }
}

vector<Edge> Graph::getNeighbors(const string &node) const {
    auto it = nodes.find(node);
    if (it != nodes.end()) {
        return it->second.neighbors;
    }
    return {};
}