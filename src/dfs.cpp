#include "dfs.h"
#include <iostream>
#include <list>

using namespace std;

void runDFS(const Graph &grafo, const string &start, const string &goal) {
    cout << "\nInicio da Execucao";

    // Usando list para conseguir inserir no início e percorrer
    list<DFSState> pilha;
    unordered_set<string> visitados;
    unordered_set<string> fronteira;

    // Estado inicial
    pilha.push_front({start, 0, {start}});
    fronteira.insert(start);

    int iteracao = 1;
    int nodesExpanded = 0;

    while (!pilha.empty()) {
        cout << "\nIteracao " << iteracao++ << ":" << endl;

        // Mostrar a pilha (topo à esquerda)
        cout << "Pilha: ";
        for (auto it = pilha.begin(); it != pilha.end(); ++it) {
            cout << "(" << it->node << ": " << it->g << ") ";
        }
        cout << endl;

        // Explorar nó do topo
        DFSState atual = pilha.front();
        pilha.pop_front();
        fronteira.erase(atual.node);
        nodesExpanded++;

        cout << "Proximo a Ser Explorado: " << atual.node << endl;

        // Caminho até agora
        cout << "Caminho: ";
        for (size_t i = 0; i < atual.path.size(); i++) {
            cout << atual.path[i];
            if (i < atual.path.size() - 1) cout << " -> ";
        }
        cout << endl;

        cout << "Medida de Desempenho - Nos Expandidos: " << nodesExpanded << endl;

        // Se for objetivo, parar
        if (atual.node == goal) {
            cout << "\nFim da Execucao";
            cout << "\nDistancia: " << atual.g;
            cout << "\nCaminho: ";
            for (size_t i = 0; i < atual.path.size(); i++) {
                cout << atual.path[i];
                if (i < atual.path.size() - 1) cout << " -> ";
            }
            cout << "\nMedida de Desempenho - Nos Expandidos: " << nodesExpanded << endl << endl;
            return;
        }

        // Marca como visitado
        visitados.insert(atual.node);

        // Expandir vizinhos (inserindo no início da pilha, mantendo ordem do arquivo)
        auto vizinhos = grafo.getNeighbors(atual.node);
        for (auto it = vizinhos.begin(); it != vizinhos.end(); ++it) {
            if (visitados.find(it->to) == visitados.end() && fronteira.find(it->to) == fronteira.end()) {
                DFSState novo;
                novo.node = it->to;
                novo.g = atual.g + it->g;
                novo.path = atual.path;
                novo.path.push_back(it->to);
                pilha.push_front(novo);   // insere no início
                fronteira.insert(it->to);
            }
        }
    }
    cout << "\nFim da Execucao";
    cout << "\nNao foi encontrado caminho ate " << goal << "." << endl;
    cout << "Medida de Desempenho - Nos Expandidos: " << nodesExpanded << endl << endl;
}