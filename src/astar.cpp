#include "astar.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void runAStar(const Graph &grafo, const string &start, const string &goal) {
    cout << "\nInicio da execucao" << endl;

    // Lista aberta (fronteira), ordenada por f = g + h
    list<AStarState> fronteira;

    // Melhor custo g(n) conhecido até agora para cada nó
    unordered_map<string, int> gScore;

    // Fechados = nós já expandidos
    unordered_set<string> fechados;

    // Inicializa nó inicial
    AStarState inicial;
    inicial.node = start;
    inicial.g = 0;
    inicial.f = inicial.g + grafo.nodes.at(start).heuristic;
    inicial.path = {start};
    fronteira.push_back(inicial);
    gScore[start] = 0;

    int iteracao = 1;
    int nodesExpanded = 0;

    while (!fronteira.empty()) {
        // Ordena fronteira por f (crescente)
        fronteira.sort([](const AStarState &a, const AStarState &b) {
            return a.f < b.f;
        });

        cout << "\nIteracao " << iteracao++ << ":" << endl;

        // Mostrar lista ordenada
        cout << "ListaOrdenada: ";
        for (auto &s : fronteira) {
            cout << "(" << s.node << ": " << s.g << " + "
                 << grafo.nodes.at(s.node).heuristic
                 << " = " << s.f << ") ";
        }
        cout << endl;

        // Seleciona o nó com menor f
        AStarState atual = fronteira.front();
        fronteira.pop_front();

        cout << "Proximo a Ser Explorado: " << atual.node << endl;

        // Caminho até agora
        cout << "Caminho: ";
        for (size_t i = 0; i < atual.path.size(); i++) {
            cout << atual.path[i];
            if (i < atual.path.size() - 1) cout << " -> ";
        }
        cout << endl;

        nodesExpanded++;
        cout << "Medida de Desempenho - Nos Expandidos: " << nodesExpanded << endl;

        // Verifica se é objetivo
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

        fechados.insert(atual.node);

        // Expande vizinhos
        for (auto &edge : grafo.getNeighbors(atual.node)) {
            int novoG = atual.g + edge.cost;

            // Se já foi expandido com custo melhor, ignora
            if (fechados.find(edge.to) != fechados.end() &&
                novoG >= gScore[edge.to]) {
                continue;
            }

            // Se nunca visitado ou achou caminho melhor
            if (gScore.find(edge.to) == gScore.end() || novoG < gScore[edge.to]) {
                gScore[edge.to] = novoG;
                AStarState viz;
                viz.node = edge.to;
                viz.g = novoG;
                viz.f = novoG + grafo.nodes.at(edge.to).heuristic;
                viz.path = atual.path;
                viz.path.push_back(edge.to);

                // remove duplicatas piores da fronteira
                fronteira.remove_if([&](const AStarState &s) {
                    return s.node == viz.node && s.f >= viz.f;
                });

                fronteira.push_back(viz);
            }
        }
    }
    
    cout << "\nFim da Execucao";
    cout << "\nNao foi encontrado caminho ate " << goal << "." << endl;
    cout << "Medida de Desempenho - Nos Expandidos: " << nodesExpanded << endl << endl;
}
