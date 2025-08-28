#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool parseFile(const std::string &filename, Graph &grafo) {
    // Prefixo da pasta input
    std::string filepath = "../input/" + filename;  // se o .exe estiver em src/

    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo: " << filepath << std::endl;
        return false;
    }

    // TODO: Implementar leitura do arquivo conforme especificação
    // ponto_inicial(a0), ponto_final(f0), orientado(s/n), pode_ir(...), h(...)

    file.close();
    return true;
}