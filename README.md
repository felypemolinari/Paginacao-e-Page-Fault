# Testes de Algoritmos e Desempenho

Este repositório é dedicado a testes de desempenho de diferentes algoritmos e operações de sistema, incluindo benchmarks de alocação de memória e implementações de estruturas de dados.

## Projetos

Atualmente, o repositório inclui:

* **`MemoryCost`**: Um benchmark para avaliar o custo e o desempenho da alocação de memória no sistema.
* **`Arvore`**: Uma implementação de algoritmo de árvore para fins de teste.

---

## `MemoryCost`

Este programa foi criado para testar a alocação de memória e permitir a análise de seu impacto no sistema, especificamente monitorando *page faults*.

### Como Compilar e Executar

1.  Navegue até o diretório do projeto:
    ```bash
    cd MemoryCost
    ```
2.  Compile o programa C++:
    ```bash
    g++ main.cpp -o main
    ```
   
3.  Execute o benchmark:
    ```bash
    ./main
    ```
   

### Como Monitorar (Linux)

Enquanto o programa (`./main`) estiver em execução, abra um segundo terminal para monitorar seu comportamento.

1.  **Encontrar o PID (Process ID):**
    Use o `top` para listar os processos ativos. Encontre o seu programa `main` na lista e anote o `PID`.
    ```bash
    top
    ```
   
2.  **Verificar Page Faults:**
    Depois de obter o PID, use o comando `ps` para monitorar os *minor page faults* (`minflt`) e os *major page faults* (`majflt`). Substitua `<PID>` pelo número que você anotou.
    ```bash
    ps -p <PID> -o minflt,majflt
    ```
   

---

## `Arvore`

Este diretório contém uma implementação de algoritmo de árvore, adicionada para testes.

### Como Compilar e Executar C++

1.  Navegue até o diretório do projeto:
    ```bash
    cd Arvore
    ```
2.  Compile o programa (assumindo que o arquivo principal seja `arvore.cpp`):
    ```bash
    g++ arvore.cpp -o arvore
    ```
3.  Execute o programa:
    ```bash
    ./arvore
    ```

### Como Compilar e Executar C++

1.  Navegue até o diretório do projeto:
    ```bash
    cd Arvore
    ```
2.  Execute o programa:
    ```bash
    python arvore.py  
    ```