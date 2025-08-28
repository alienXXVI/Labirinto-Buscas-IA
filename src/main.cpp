#include <iostream>
#include "parser.h"
#include "graph.h"
#include "astar.h"
#include "dfs.h"
#include "dijkstra.h"

int main() {
    std::string arquivo;
    std::cout << "Digite o nome do arquivo de entrada (garante que ele esteja dentro da pasta input/): ";
    std::cin >> arquivo;

    Graph grafo;
    if (!parseFile(arquivo, grafo)) {
        std::cout << "Erro ao ler o arquivo!" << std::endl;
        return 1;
    }

    int opcao;
    do {
        std::cout << "\nEscolha o algoritmo:\n";
        std::cout << "1. A* (Melhor solucao)\n";
        std::cout << "2. DFS (Pior solucao)\n";
        std::cout << "3. Custo Uniforme (Bonus fio limitado)\n";
        std::cout << "0. Encerrar\n";
        std::cout << "Opcao: ";
        std::cin >> opcao;

        switch(opcao) {
            case 1:
                runAStar(grafo);
                break;
            case 2:
                runDFS(grafo);
                break;
            case 3: {
                int comprimento_fio;
                std::cout << "Digite o comprimento do fio: ";
                std::cin >> comprimento_fio;
                runDijkstra(grafo, comprimento_fio);
                break;
            }
            case 0:
                std::cout << "Programa encerrado." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida.\n";
                break;
        }
    } while(opcao != 0);

    return 0;
}