# Algoritmos e Estrutura de Dados em C

Este repositório foi criado para organizar e consolidar os conceitos que aprendi em Ciência da Computação, documentando a minha evolução desde os fundamentos da lógica de programação e manipulação de arrays até a implementação de estruturas de dados dinâmicas e gerenciamento manual de memória em baixo nível.

---

## Estrutura do Repositório

O projeto está organizado em três grandes módulos que refletem a linha de aprendizado técnico:

### [01-logica-e-arrays](./01-logica-e-arrays/)
Focado em lógica estruturada e manipulação de memória estática.
* `inversao-valores.c`: Lógica de ordenação e leitura inversa de sequências numéricas.
* `jogo-mentalista.c`: Jogo interativo de adivinhação aplicando estruturas de repetição, condicionais compostas e cálculo de distância matemática (`abs`).
* `matriz.c`: Operações e manipulação de dados bidimensionais.
* `multiplicacao-vetor.c`: Algoritmos matemáticos e iteração em arrays unidimensionais.

### [02-estruturas-compostas](./02-estruturas-compostas/)
Introdução à modelagem de dados personalizada e funções utilitárias.
* `cadastro-estudante-struct.c`: Sistema de cadastro utilizando `structs` para agrupamento de dados, manipulação segura de strings com `fgets` e geração de identificadores (RA) pseudoaleatórios baseados em tempo (`time.h`).

### [03-estruturas-dinamicas](./03-estruturas-dinamicas/)
O núcleo avançado do repositório. Demonstra o domínio sobre ponteiros, alocação dinâmica (`malloc`/`free`) e estruturas de dados encadeadas.
* `lista-duplamente-ligada-aleatoria.c`: Uma evolução do algoritmo anterior, simulando testes automatizados através do sorteio aleatório de nós para remoção, controle de fluxo interativo e prevenção de vazamento de memória (*memory leaks*).
* `lista-duplamente-ligada.c`: Implementação pura de uma lista bidirecional com operações de inserção, remoção e navegação em ambos os sentidos.
* `arvores-binarias/`: Códigos voltados para estruturas de dados hierárquicas.

---

## Tecnologias e Conceitos Absorvidos

* **Linguagem:** C (Padrão ANSI)
* **Gerenciamento de Memória:** Alocação dinâmica com ponteiros, `malloc`, `free` e boas práticas para evitar *Memory Leaks*.
* **Modularização:** Criação de funções e passagem de parâmetros por valor e por referência.
* **Ferramentas:** Compilador GCC e automação básica via terminal.

---

## Como Compilar e Executar os Códigos

Certifique-se de ter um compilador GCC instalado em sua máquina.

1. Navegue até a pasta do arquivo desejado pelo terminal:
   ```bash
   cd 03-estruturas-dinamicas