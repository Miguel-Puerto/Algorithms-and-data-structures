#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da estrutura para armazenar os dados do estudante
struct Estudante {
    int ra;
    char nome[100];
    char curso[50];
};

// Função para gerar um RA aleatório entre 100000 e 999999
int gerarRA() {
    return rand() % 900000 + 100000;
}

int main() {
    struct Estudante p;

    // Inicializa a semente para geração de números aleatórios
    srand(time(NULL));
    p.ra = gerarRA();

    // Cadastro do nome do estudante
    printf("Digite o nome do estudante: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    // Cadastro do curso do estudante
    printf("Digite o curso do estudante: ");
    fgets(p.curso, sizeof(p.curso), stdin);
    p.curso[strcspn(p.curso, "\n")] = '\0';

    // Exibição dos dados cadastrados
    printf("\n=== Estudante Cadastrado com Sucesso ===\n");
    printf("RA: %d\n", p.ra);
    printf("Nome: %s\n", p.nome);
    printf("Curso: %s\n", p.curso);

    return 0;
}