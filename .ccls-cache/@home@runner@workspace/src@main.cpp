#include "graph.h"
#include "dijkstra.h"
#include "astar.h"
#include "dfs.h"
#include "parser.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief Função auxiliar para imprimir resumo do grafo carregado.
 */
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

/**
 * @brief Menu principal do sistema de algoritmos de busca.
 */
int main() {
    Graph grafo;
    string start, goal;
    bool grafoCarregado = false;

    int opcao = -1;
    while (opcao != 0) {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Ler arquivo de entrada e imprimir resumo do grafo\n";
        cout << "2. Executar Busca em Profundidade (DFS) - Pior Solucao\n";
        cout << "3. Executar A* - Melhor Solucao\n";
        cout << "4. Executar Custo Uniforme (Dijkstra) com fio limitado - Bonus\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string filename;
                cout << "Digite o nome do arquivo de entrada (na pasta input/): ";
                cin >> filename;
                if (parseFile(filename, grafo, start, goal)) {
                    grafoCarregado = true;
                    cout << "Arquivo carregado com sucesso.\n";
                    printGraph(grafo, start, goal);
                } else {
                    cout << "Erro ao ler o arquivo.\n";
                }
                break;
            }
            case 2:
                if (grafoCarregado) {
                    cout << "\nExecutando Busca em Profundidade..." << endl;
                    runDFS(grafo, start, goal);
                } else {
                    cout << "Carregue primeiro um grafo (opcao 1).\n";
                }
                break;
            case 3:
                if (grafoCarregado) {
                    cout << "\nExecutando A*..." << endl;
                    runAStar(grafo, start, goal);
                } else {
                    cout << "Carregue primeiro um grafo (opcao 1).\n";
                }
                break;
            case 4:
                if (grafoCarregado) {
                    cout << "\nExecutando Custo Uniforme.." << endl;
                    runDijkstra(grafo, start, goal);
                } else {
                    cout << "Carregue primeiro um grafo (opcao 1).\n";
                }
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    }

    return 0;
}
