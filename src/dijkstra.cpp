#include "dijkstra.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void runDijkstra(const Graph &grafo, const string &start, const string &goal) {
    int fio_limite = 0;

    cout << "\nInicio da execucao" << endl;
    cout << "Qual o comprimento do fio?" << endl;
    cin >> fio_limite;

    vector<DijkstraState> frontier; // lista ordenada manualmente
    unordered_set<string> visited;
    int nodesExpanded = 0;

    // Inserir estado inicial
    frontier.push_back({start, 0, {start}});

    int iteracao = 1;

    while (!frontier.empty()) {
        // Ordenar fronteira pelo custo acumulado
        sort(frontier.begin(), frontier.end());

        // Mostrar iteração
        cout << "\nIteracao " << iteracao++ << ":\n";
        cout << "Fila: ";
        for (auto &s : frontier) {
            cout << "(" << s.node << ": " << s.cost << ") ";
        }
        cout << endl;

        // Expandir o nó de menor custo
        DijkstraState atual = frontier.front();
        frontier.erase(frontier.begin());
        nodesExpanded++;

        cout << "Proximo a Ser Explorado: " << atual.node << endl;

        int fio_restante = fio_limite - atual.cost;
        cout << "Medida de desempenho - Nos Expandidos: " << nodesExpanded << endl;
        cout << "Fio restante: " << fio_restante;
        if (fio_restante < 0) cout << " - Caminho descartado";
        cout << endl;

        // Se nó já visitado, ignorar
        if (visited.find(atual.node) != visited.end()) continue;
        visited.insert(atual.node);

        // Se excedeu o fio, não expandir
        if (atual.cost > fio_limite) continue;

        // Se objetivo, terminar
        if (atual.node == goal) {
            cout << "\nFim da execucao";
            cout << "\nDistancia: " << atual.cost;
            cout << "\nCaminho: ";
            for (size_t i = 0; i < atual.path.size(); i++) {
                cout << atual.path[i];
                if (i + 1 < atual.path.size()) cout << " -> ";
            }
            cout << "\nMedida de desempenho - Nos Expandidos: " << nodesExpanded << endl << endl;
            return;
        }

        // Expandir vizinhos
        auto vizinhos = grafo.getNeighbors(atual.node);
        for (auto &e : vizinhos) {
            if (visited.find(e.to) == visited.end()) {
                int novo_custo = atual.cost + e.cost;
                vector<string> novo_path = atual.path;
                novo_path.push_back(e.to);
                frontier.push_back({e.to, novo_custo, novo_path});
            }
        }
    }

    cout << "\nFim da Execucao";
    cout << "\nNao foi encontrado caminho ate " << goal << "." << endl;
    cout << "Medida de desempenho - Nos Expandidos: " << nodesExpanded << endl << endl;
}
