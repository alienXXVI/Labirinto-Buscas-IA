### Projeto: Algoritmos de Busca em Grafos



Este projeto implementa três algoritmos de busca em grafos, acessíveis por meio de um menu interativo:



* Busca em Profundidade (DFS) - encontra uma solução qualquer (pior caso).
* A\* - encontra a melhor solução com heurística.
* Custo Uniforme (Dijkstra) com fio limitado - encontra caminhos respeitando uma restrição de comprimento de fio.





##### Estrutura do Projeto



/projeto

│

├── src/                  	# Código-fonte

│   ├── main.cpp          	# Menu principal

│   ├── graph.h / graph.cpp

│   ├── dfs.h / dfs.cpp

│   ├── astar.h / astar.cpp

│   ├── dijkstra.h / dijkstra.cpp

│   ├── parser.h / parser.cpp

│

├── input/                	# Arquivos de entrada (grafos)

│   ├── exemplo1.txt

│   └── exemplo2.txt

│

└── README.txt            	# Este arquivo





##### Pré-requisitos



Este projeto foi feito em C++11 ou superior.

Necessário ter instalado:



* GCC (g++) ou Clang
* Sistema operacional Linux, MacOS ou Windows com MinGW/MSYS2





##### Compilação



Navegue até a pasta src/ e compile todos os arquivos:



*cd src*

*g++ -std=c++11 \*.cpp -o busca*



Isso gerará o executável busca (ou busca.exe no Windows).





##### Execução



Para rodar o programa:



*./busca*



Você verá o seguinte menu:



*===== MENU PRINCIPAL =====*

*1. Ler arquivo de entrada e imprimir resumo do grafo*

*2. Executar Busca em Profundidade (DFS) - Pior Solução*

*3. Executar A\* - Melhor Solução*

*4. Executar Custo Uniforme (Dijkstra) com fio limitado - Bônus*

*0. Sair*

*Escolha uma opcao:*





##### Passo a Passo



1. ###### Carregar um grafo



* Escolha a opção 1 e digite o nome do arquivo de entrada (exemplo: exemplo1.txt).
* O arquivo deve estar na pasta input/.

Exemplo:



*Digite o nome do arquivo de entrada (na pasta input/): exemplo1.txt*





###### 2\. Visualizar resumo



O programa mostrará os nós, suas heurísticas e vizinhos.





###### 3\. Executar algoritmos



* Opção 2 - executa DFS.
* Opção 3 - executa A\*.
* Opção 4 - executa Custo Uniforme com limite de fio (será perguntado o valor do fio).





###### 4\. Finalizar



Opção 0 encerra o programa.





##### Formato dos Arquivos de Entrada



Um grafo deve ser definido da seguinte forma:



*ponto\_inicial(a0). % Ponto inicial da busca*

*ponto\_final(f0). % Ponto final da busca*

*orientado(s). % Indica grafo orientado*

*%orientado(n). % Indica grafo não orientado*

*pode\_ir(a0,b0,95). % Existe uma ligação entre a0 e b0*



*% O custo para chegar em b0 partindo de a0 é 95*



*pode\_ir(a0,c0,44). % Caso não orientado, o custo para a0 partindo de c0 é 44*

*pode\_ir(a0,d0,98). % Comentários não serão incluídos no arquivo de teste*

*pode\_ir(a0,e0,49).*

*pode\_ir(b0,c0,60).*

*pode\_ir(b0,e0,31).*

*pode\_ir(b0,f0,44).*

*pode\_ir(d0,c0,32).*

*pode\_ir(d0,e0,28).*

*pode\_ir(d0,f0,34).*

*h(a0,f0,58). % A distância em linha reta de a0 até f0 é 58*

*h(b0,f0,24).*

*h(c0,f0,34).*

*h(d0,f0,37).*

*h(e0,f0,5).*

*h(f0,f0,0).*



* *orientado*: s (sim)/n (nao) - define se o grafo é direcionado.
* *ponto\_inicial / ponto\_final* - definem o nó inicial e o objetivo.
* Cada linha - lista vizinhos e custos.
* *h* - valor da heurística (usado apenas no A\*).





##### Saídas do Programa



Durante a execução, o programa mostra:

Iterações do algoritmo.

Lista de nós parte da fronteira.

Distância total percorrida (solução final).

Caminhos explorados.

Caminhos descartados (no caso da execução do algoritmo Custo Uniforme com fio limitado, quando o fio é ultrapassado).

Medida de desempenho: número de nós expandidos.

Comprimento restante do fio (no caso da execução do algoritmo Custo Uniforme com fio limitado).

Caminho final encontrado (ou aviso se não existe).





