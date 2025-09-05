#include "dijkstra.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void runDijkstra(const Graph &grafo, const string &start, const string &goal) {
    int fio_limite = 0;

    cout << "\nInicio da Execucao" << endl;
    cout << "Qual o comprimento do fio?" << endl;
    cin >> fio_limite;

    vector<DijkstraState> fronteira; // lista ordenada manualmente
    unordered_set<string> visitados;
    int nodesExpanded = 0;

    // Inserir estado inicial
    fronteira.push_back({start, 0, {start}});

    int iteracao = 1;

    while (!fronteira.empty()) {
        // Ordenar fronteira pelo custo acumulado
        sort(fronteira.begin(), fronteira.end());

        // Mostrar iteração
        cout << "\nIteracao " << iteracao++ << ":\n";
        cout << "ListaOrdenada: ";
        for (auto &s : fronteira) {
            cout << "(" << s.node << ": " << s.g << ") ";
        }
        cout << endl;

        // Expandir o nó de menor custo
        DijkstraState atual = fronteira.front();
        fronteira.erase(fronteira.begin());
        nodesExpanded++;

        cout << "Proximo a Ser Explorado: " << atual.node << endl;

        // Mostrar caminho até o nó atual
        cout << "Caminho: ";
        for (size_t i = 0; i < atual.path.size(); i++) {
            cout << atual.path[i];
            if (i + 1 < atual.path.size()) cout << " -> ";
        }
        cout << endl;

        int fio_restante = fio_limite - atual.g;
        cout << "Medida de desempenho - Nos Expandidos: " << nodesExpanded << endl;
        cout << "Fio restante: " << fio_restante;
        if (fio_restante < 0) cout << " - Caminho descartado";
        cout << endl;

        // Se nó já visitado, ignorar
        if (visitados.find(atual.node) != visitados.end()) continue;
        visitados.insert(atual.node);

        // Se excedeu o fio, não expandir
        if (atual.g > fio_limite) continue;

        // Se objetivo, terminar
        if (atual.node == goal) {
            cout << "\nFim da execucao";
            cout << "\nDistancia: " << atual.g;
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
            if (visitados.find(e.to) == visitados.end()) {
                int novo_custo = atual.g + e.cost; // %
                vector<string> novo_path = atual.path;
                novo_path.push_back(e.to);
                fronteira.push_back({e.to, novo_custo, novo_path});
            }
        }
    }

    cout << "\nFim da Execucao";
    cout << "\nNao foi encontrado caminho ate " << goal << "." << endl;
    cout << "Medida de desempenho - Nos Expandidos: " << nodesExpanded << endl << endl;
}
