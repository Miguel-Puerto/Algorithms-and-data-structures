#include <stdio.h>
#include <stdlib.h>



// Definindo o nó da lista
typedef struct No {
    int valorINT;
    struct No* anterior;
    struct No* proximo;
} No;

// Definindo a estrutura da lista
typedef struct {
    No* inicio;
    No* fim;
} Lista;

// Inicializar a lista
void iniciarLista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Inserir no fim da lista
void inserirFim(Lista* lista, int valorINT) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valorINT = valorINT;
    novo->proximo = NULL;
    novo->anterior = lista->fim;

    if (lista->fim != NULL)
        lista->fim->proximo = novo;
    else
        lista->inicio = novo;

    lista->fim = novo;
}

// Listar do início ao fim
void listarInicio(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valorINT);
        atual = atual->proximo;
    }
    printf("\n");
}

// Listar do fim ao início
void listarFim(Lista* lista) {
    No* atual = lista->fim;
    while (atual != NULL) {
        printf("%d ", atual->valorINT);
        atual = atual->anterior;
    }
    printf("\n");
}

// Remover um valor da lista
void removerValor(Lista* lista, int valorINT) {
    No* atual = lista->inicio;

    while (atual != NULL && atual->valorINT != valorINT) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Valor não encontrado.\n");
        return;
    }

    if (atual->anterior != NULL)
        atual->anterior->proximo = atual->proximo;
    else
        lista->inicio = atual->proximo;

    if (atual->proximo != NULL)
        atual->proximo->anterior = atual->anterior;
    else
        lista->fim = atual->anterior;

    free(atual);
}

// Função principal
int main() {
    Lista lista;
    iniciarLista(&lista);
    int x;
    int y;
    int a;

printf("DIGITE O VALOR DE X: ");
scanf("%d", &x);

printf("DIGITE O VALOR DE Y: ");
scanf("%d", &y);

printf("DIGITE O VALOR DE A: ");
scanf("%d", &a);

    inserirFim(&lista, x);
    inserirFim(&lista, y);
    inserirFim(&lista, a);

    printf("\nListagem do início ao fim:\n");
    listarInicio(&lista);

    printf("\nListagem do fim ao início:\n");
    listarFim(&lista);

    printf("\nRemovendo o valor Y: %d", y);
    removerValor(&lista, y);

    printf("\nListagem atual: ");
    listarInicio(&lista);

    return 0;
}
