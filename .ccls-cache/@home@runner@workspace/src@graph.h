#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief Representa uma aresta em um grafo.
 */
struct Edge {
    string to;  ///< Nó de destino da aresta
    int cost;   ///< Custo associado à aresta (peso)
};

/**
 * @brief Representa um nó do grafo.
 */
struct Node {
    string nome;                ///< Nome do nó (identificação única)
    vector<Edge> neighbors;     ///< Lista de vizinhos (arestas de saída)
    int heuristic = 0;          ///< Heurística h(n) usada no A* (padrão: 0)
};

/**
 * @brief Estrutura de Grafo com suporte a orientação e heurística.
 */
class Graph {
private:
    bool oriented;  ///< Define se o grafo é orientado (true) ou não orientado (false)
public:
    unordered_map<string, Node> nodes; ///< Mapeamento de nome -> nó

    /**
     * @brief Construtor da classe Graph.
     * @param oriented Define se o grafo é orientado (default = true).
     */
    Graph(bool oriented = true);

    /**
     * @brief Define se o grafo é orientado.
     * @param val true para orientado, false para não orientado.
     */
    void setOriented(bool val);

    /**
     * @brief Retorna se o grafo é orientado.
     * @return true se orientado, false caso contrário.
     */
    bool isOriented() const;

    /**
     * @brief Adiciona um nó ao grafo.
     * @param name Nome do nó.
     */
    void addNode(const string &name);

    /**
     * @brief Adiciona uma aresta entre dois nós.
     * @param from Nó de origem.
     * @param to Nó de destino.
     * @param cost Custo/peso da aresta.
     *
     * Se o grafo não for orientado, adiciona também a aresta inversa.
     */
    void addEdge(const string &from, const string &to, int cost);

    /**
     * @brief Define a heurística de um nó.
     * @param node Nome do nó.
     * @param h Valor da heurística.
     */
    void setHeuristic(const string &node, int h);

    /**
     * @brief Obtém os vizinhos de um nó.
     * @param node Nome do nó.
     * @return Vetor de arestas saindo do nó.
     */
    vector<Edge> getNeighbors(const string &node) const;
};

#endif
