#include <stdio.h>
#include <stdlib.h>

// Definição do nó da Árvore Binária de Busca
typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

// Função recursiva para inserção de um elemento na BST
No* insere(No *r, int x) {
    if (r == NULL) {
        No *n = (No*)malloc(sizeof(No));
        if (n == NULL) {
            printf("Erro: Falha de alocação de memória para o nó!\n");
            exit(1);
        }
        n->dado = x;
        n->esq = NULL;
        n->dir = NULL;
        return n;
    }

    if (x < r->dado) {
        r->esq = insere(r->esq, x);
    } else if (x > r->dado) {
        r->dir = insere(r->dir, x);
    }
    
    // Ignora duplicatas
    return r;
}

// Percurso em ordem (Esquerda -> Raiz -> Direita)
void emOrdem(No *r) {
    if (r) {
        emOrdem(r->esq);
        printf("%d ", r->dado);
        emOrdem(r->dir);
    }
}

// Desalocação recursiva de memória da árvore
void liberaArvore(No *r) {
    if (r) {
        liberaArvore(r->esq);
        liberaArvore(r->dir);
        free(r);
    }
}

int main(void) {
    No *raiz = NULL;
    int *v = NULL; // Ponteiro que apontará para o vetor dinâmico
    int tamanho, i;

    // 1. Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor desejado: ");
    if (scanf("%d", &tamanho) != 1 || tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

    // 2. Aloca a memória para o vetor dinamicamente
    v = (int*)malloc(tamanho * sizeof(int));
    if (v == NULL) {
        printf("Erro: Falha de alocação de memória para o vetor!\n");
        return 1;
    }

    // 3. Solicita ao usuário que preencha o vetor
    printf("\n=== Preenchimento do Vetor de %d elementos ===\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        printf("Digite o valor para a posicao [%d]: ", i);
        if (scanf("%d", &v[i]) != 1) {
            printf("Entrada inválida.\n");
            free(v); // Libera o vetor alocado antes de fechar por erro
            return 1;
        }
    }

    // 4. Passa os dados do vetor para a árvore binária
    printf("\nInserindo elementos do vetor na árvore...\n");
    for (i = 0; i < tamanho; i++) {
        raiz = insere(raiz, v[i]);
    }

    // 5. Exibe o resultado de forma ordenada
    printf("Árvore em ordem (valores ordenados): ");
    emOrdem(raiz);
    printf("\n");

    // 6. Limpeza total da memória RAM
    free(v);            // Libera o vetor dinâmico
    liberaArvore(raiz); // Libera os nós da árvore
    
    return 0;
}
