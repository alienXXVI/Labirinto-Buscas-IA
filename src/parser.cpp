#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// ---------- utilitários simples de string ---------- //
static inline string ltrim(string s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch){ return !isspace(ch); }));
    return s;
}
static inline string rtrim(string s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch){ return !isspace(ch); }).base(), s.end());
    return s;
}
static inline string trim(string s) { return ltrim(rtrim(move(s))); }

static inline void strip_comment(string &s) {
    auto pos = s.find('%');
    if (pos != string::npos) s.erase(pos);
    s = trim(s);
}

static inline void strip_trailing_dot(string &s) {
    if (!s.empty() && s.back() == '.') s.pop_back();
    s = trim(s);
}

static inline vector<string> split_args(const string &inside) {
    vector<string> out;
    string cur;
    stringstream ss(inside);
    while (getline(ss, cur, ',')) {
        out.push_back(trim(cur));
    }
    return out;
}

static inline bool starts_with(const string &s, const string &prefix) {
    return s.size() >= prefix.size() && equal(prefix.begin(), prefix.end(), s.begin());
}
// --------------------------------------------------- //

bool parseFile(const string &filename, Graph &grafo, string &startNode, string &goalNode) {
    // -- Tentativa de abrir o arquivo --
    vector<string> candidates = {
        "input/" + filename,
        "../input/" + filename
    };

    ifstream file;
    string usedPath;
    for (auto &p : candidates) {
        file.open(p);
        if (file.is_open()) { usedPath = p; break; }
    }

    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo em input/: " << filename << endl;
        return false;
    }

    // -- Leitura e pré-processamento das linhas --
    vector<string> lines;
    string raw;
    while (getline(file, raw)) {
        strip_comment(raw);
        strip_trailing_dot(raw);
        if (!raw.empty()) lines.push_back(raw);
    }
    file.close();

    startNode = "";
    goalNode  = "";

    // Identificar orientação do grafo
    for (const auto &ln : lines) {
        if (starts_with(ln, "orientado(")) {
            auto p1 = ln.find('(');
            auto p2 = ln.rfind(')');
            if (p1 != string::npos && p2 != string::npos && p2 > p1+1) {
                string arg = trim(ln.substr(p1+1, p2 - (p1+1)));
                bool isOriented = (!arg.empty() && (arg[0]=='s' || arg[0]=='S'));
                grafo.setOriented(isOriented);
            }
            break;
        }
    }

    // Processar os demais comandos
    for (const auto &ln : lines) {
        if (starts_with(ln, "orientado(")) continue;

        else if (starts_with(ln, "ponto_inicial(")) {
            auto p1 = ln.find('(');
            auto p2 = ln.rfind(')');
            if (p1 != string::npos && p2 != string::npos && p2 > p1+1) {
                startNode = trim(ln.substr(p1+1, p2 - (p1+1)));
            }
        }
        else if (starts_with(ln, "ponto_final(")) {
            auto p1 = ln.find('(');
            auto p2 = ln.rfind(')');
            if (p1 != string::npos && p2 != string::npos && p2 > p1+1) {
                goalNode = trim(ln.substr(p1+1, p2 - (p1+1)));
            }
        }
        else if (starts_with(ln, "pode_ir(")) {
            auto p1 = ln.find('(');
            auto p2 = ln.rfind(')');
            if (p1 == string::npos || p2 == string::npos || p2 <= p1+1) continue;

            auto args = split_args(ln.substr(p1+1, p2 - (p1+1)));
            if (args.size() == 3) {
                try {
                    int cost = stoi(args[2]);
                    grafo.addEdge(args[0], args[1], cost);
                } catch (...) {
                    cout << "Aviso: custo invalido em linha: " << ln << endl;
                }
            }
        }
        else if (starts_with(ln, "h(")) {
            auto p1 = ln.find('(');
            auto p2 = ln.rfind(')');
            if (p1 == string::npos || p2 == string::npos || p2 <= p1+1) continue;

            auto args = split_args(ln.substr(p1+1, p2 - (p1+1)));
            if (args.size() == 3) {
                try {
                    int h = stoi(args[2]);
                    grafo.addNode(args[0]);
                    grafo.setHeuristic(args[0], h);
                } catch (...) {
                    cout << "Aviso: heuristica invalida em linha: " << ln << endl;
                }
            }
        }
    }

    return true;
}
