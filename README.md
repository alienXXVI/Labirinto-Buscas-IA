
# Projeto: Algoritmos de Busca em Grafos

Este projeto implementa três algoritmos de busca em grafos para resolver um problema de caminho no "labirinto de Creta". Os algoritmos podem ser acessados através de um menu interativo, permitindo a exploração de diferentes estratégias de busca.

## Algoritmos Implementados

  * **Busca em Profundidade (DFS):** Encontra uma solução, mas não é garantidamente a melhor (pior solução).
  * **A\*:** Encontra a melhor solução usando uma função heurística para maior eficiência.
  * **Custo Uniforme (Dijkstra) com fio limitado:** Encontra caminhos respeitando uma restrição de comprimento, como um bônus para o projeto.

-----

## Estrutura do Projeto

```
/projeto
│
├── src/                  # Código-fonte
│   ├── main.cpp          # Menu principal
│   ├── graph.h/graph.cpp
│   ├── dfs.h/dfs.cpp
│   ├── astar.h/astar.cpp
│   ├── dijkstra.h/dijkstra.cpp
│   └── parser.h/parser.cpp
│
├── input/                # Arquivos de entrada (grafos)
│   ├── exemplo1.txt
│   └── exemplo2.txt
│
└── README.md             # Este arquivo
```

-----

## Pré-requisitos

Este projeto foi desenvolvido em **C++11** ou superior. Para compilar e executar, é preciso ter um dos seguintes instalados:

  * **GCC (g++)** ou **Clang**
  * **Sistema operacional Linux**, **MacOS** ou **Windows** (com MinGW/MSYS2)

-----

## Compilação

Navegue até a pasta `src/` e execute o comando abaixo para compilar todos os arquivos.

```sh
cd src
g++ -std=c++11 *.cpp -o busca
```

Isso criará um arquivo executável chamado `busca` (ou `busca.exe` no Windows).

-----

## Execução

Para rodar o programa, execute o seguinte comando no terminal:

```sh
./busca
```

Você verá um menu com as opções disponíveis:

```
===== MENU PRINCIPAL =====
1. Ler arquivo de entrada e imprimir resumo do grafo
2. Executar Busca em Profundidade (DFS) - Pior Solução
3. Executar A* - Melhor Solução
4. Executar Custo Uniforme (Dijkstra) com fio limitado - Bônus
0. Sair
Escolha uma opcao:
```

-----

## Passo a Passo

1.  **Carregar um grafo:**

      * Escolha a opção **1** e digite o nome do arquivo de entrada (ex: `exemplo1.txt`). O arquivo deve estar na pasta `input/`.
      * *Exemplo: `Digite o nome do arquivo de entrada (na pasta input/): exemplo1.txt`*

2.  **Visualizar resumo:**

      * O programa irá mostrar os nós, suas heurísticas e os vizinhos.

3.  **Executar algoritmos:**

      * **Opção 2:** Executa a Busca em Profundidade (DFS).
      * **Opção 3:** Executa o algoritmo A\*.
      * **Opção 4:** Executa o algoritmo Custo Uniforme com limite de fio (o programa pedirá o valor do fio).

4.  **Finalizar:**

      * A opção **0** encerra o programa.

-----

## Formato dos Arquivos de Entrada

Um grafo deve ser definido em um arquivo de texto com o seguinte formato:

```
ponto_inicial(a0).       % Ponto inicial da busca
ponto_final(f0).         % Ponto final da busca
orientado(s).            % Indica grafo orientado
%orientado(n).           % Indica grafo nao orientado
pode_ir(a0,b0,95).       % Existe uma ligacao entre a0 e b0
% O custo para chegar em b0 partindo de a0 eh 95
pode_ir(a0,c0,44).       % Caso nao orientado, o custo para a0 partindo de c0 eh 44
pode_ir(a0,d0,98).
pode_ir(a0,e0,49).
pode_ir(b0,c0,60).
pode_ir(b0,e0,31).
pode_ir(b0,f0,44).
pode_ir(d0,c0,32).
pode_ir(d0,e0,28).
pode_ir(d0,f0,34).
h(a0,f0,58).             % A distancia em linha reta de a0 ate f0 eh 58
h(b0,f0,24).
h(c0,f0,34).
h(d0,f0,37).
h(e0,f0,5).
h(f0,f0,0).
```

  * `orientado`: **s** (sim) / **n** (não) - define se o grafo é direcionado.
  * `ponto_inicial` / `ponto_final`: definem os nós inicial e objetivo.
  * `pode_ir`: define as conexões entre nós e seus respectivos custos.
  * `h`: valor da heurística (usado apenas no algoritmo A\*).

-----

## Saídas do Programa

Durante a execução, o programa exibirá as seguintes informações:

  * Iterações do algoritmo.
  * Lista de nós que fazem parte da fronteira de busca.
  * Medida de desempenho: **número de nós expandidos**.
  * Distância total percorrida (solução final).
  * Caminho final encontrado (ou aviso se a solução não existe).
  * Caminhos descartados (no caso do bônus).
  * Comprimento restante do fio (no caso do bônus).
