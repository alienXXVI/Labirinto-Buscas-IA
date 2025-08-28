#include "dfs.h"
#include <iostream>
#include <iomanip>
using namespace std;

void runDFS(const Graph &grafo, const string &start, const string &goal) {
    cout << "Inicio da execucao" << endl;

    stack<DFSState> pilha;
    unordered_set<string> visitados;

    // Estado inicial
    pilha.push({start, 0, {start}});

    int iteracao = 1;
    int nodesExpanded = 0; // contador de nós expandidos

    while (!pilha.empty()) {
        cout << "\nIteracao " << iteracao++ << ":" << endl;

        // Mostrar a pilha (topo à esquerda)
        cout << "Pilha: ";
        stack<DFSState> temp = pilha; // cópia para exibir
        vector<DFSState> ordem;
        while (!temp.empty()) {
            ordem.push_back(temp.top());
            temp.pop();
        }
        for (size_t i = 0; i < ordem.size(); ++i) { // topo à esquerda
            cout << "(" << ordem[i].node << ": " << ordem[i].cost << ") ";
        }
        cout << endl;

        // Explorar nó do topo
        DFSState atual = pilha.top();
        pilha.pop();
        nodesExpanded++; // incrementa contador ao expandir

        cout << "Proximo a Ser Explorado: " << atual.node << endl;

        // Caminho até agora
        cout << "Caminho: ";
        for (size_t i = 0; i < atual.path.size(); i++) {
            cout << atual.path[i];
            if (i < atual.path.size() - 1) cout << " -> ";
        }
        cout << endl;

        // Se for objetivo, parar
        if (atual.node == goal) {
            cout << "\n\nCaminho Final: ";
            for (size_t i = 0; i < atual.path.size(); i++) {
                cout << atual.path[i];
                if (i < atual.path.size() - 1) cout << " -> ";
            }
            cout << "\nCusto Final: " << atual.cost << endl;
            cout << "Medida de Desempenho (nos expandidos): " << nodesExpanded << endl;
            return;
        }

        // Marca como visitado
        visitados.insert(atual.node);

        // Expandir vizinhos (último inserido tem prioridade)
        auto vizinhos = grafo.getNeighbors(atual.node);
        for (auto it = vizinhos.rbegin(); it != vizinhos.rend(); ++it) {
            if (visitados.find(it->to) == visitados.end()) {
                DFSState novo;
                novo.node = it->to;
                novo.cost = atual.cost + it->cost;
                novo.path = atual.path;
                novo.path.push_back(it->to);
                pilha.push(novo);
            }
        }

        cout << "Medida de Desempenho (nos expandidos): " << nodesExpanded << endl;
    }

    cout << "\nNao foi encontrado caminho ate " << goal << "." << endl;
    cout << "Medida de Desempenho (nos expandidos): " << nodesExpanded << endl;
}