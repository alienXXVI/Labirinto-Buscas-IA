#include "parser.h"
#include "graph.h"
#include "astar.h"
#include "dfs.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void printGraph(const Graph &g, const string &start, const string &goal) {
    cout << "\n--- RESUMO DO GRAFO ---\n";
    cout << "Orientado? " << (g.isOriented() ? "Sim" : "Nao") << "\n";
    cout << "No inicial: " << start << "\n";
    cout << "No objetivo: " << goal << "\n";

    vector<string> nomes;
    for (const auto &kv : g.nodes) nomes.push_back(kv.first);
    sort(nomes.begin(), nomes.end());

    cout << "Nos (" << nomes.size() << "):\n";
    for (const auto &nome : nomes) {
        const Node &n = g.nodes.at(nome);
        cout << "  - " << n.nome << "  (h = " << n.heuristic << ")\n";
        if (n.neighbors.empty()) {
            cout << "      (sem vizinhos)\n";
        } else {
            cout << "      Vizinhos: ";
            for (size_t i = 0; i < n.neighbors.size(); ++i) {
                const Edge &e = n.neighbors[i];
                cout << e.to << " (custo: " << e.cost << ")";
                if (i + 1 < n.neighbors.size()) cout << " | ";
            }
            cout << "\n";
        }
    }
    cout << "-----------------------\n";
}

int main() {
    string nomeArquivo;
    cout << "Digite o nome do arquivo (na pasta input/): ";
    cin >> nomeArquivo;

    Graph g;
    string start, goal;

    if (!parseFile(nomeArquivo, g, start, goal)) {
        cerr << "Falha ao parsear o arquivo.\n";
        return 1;
    }

    printGraph(g, start, goal);
    runAStar(g, start, goal);
    runDFS(g, start, goal);

    return 0;
}
