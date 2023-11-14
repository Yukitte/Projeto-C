#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 3

typedef struct {
    char nome[20];
    int idade;
    int id;
    int status;
} Pessoa;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrar(Pessoa p[], int *totalCadastrados) {
    p[*totalCadastrados].status = 1;
    p[*totalCadastrados].id = rand() % 100;
    printf("Digite o nome do aluno:\n");
    fgets(p[*totalCadastrados].nome, sizeof(p[*totalCadastrados].nome), stdin);

    printf("Digite a idade:\n");
    scanf("%d", &p[*totalCadastrados].idade);
    limparBuffer();

    printf("\n\n");

    (*totalCadastrados)++;
}

void imprimirLista(Pessoa p[], int totalCadastrados) {
    for (int i = 0; i < totalCadastrados; i++) {
        printf("ID: %d\n", p[i].id);
        printf("Nome: %s", p[i].nome);
        printf("Idade: %d", p[i].idade);
        if (p[i].status == 1) {
            printf("\nStatus Ativo.");
        } else {
            printf("\nStatus Inativo.");
        }
        printf("\n\n");
    }
}

void buscar(Pessoa p[], int totalCadastrados, int id) {
    if (totalCadastrados == 0) {
        printf("Lista vazia\n");
    } else {
        for (int i = 0; i < totalCadastrados; i++) {
            if (p[i].id == id) {
                printf("Nome: %s", p[i].nome);
                printf("Idade: %d", p[i].idade);
                return;
            }
        }
    }
    printf("Nao existe o registro na lista.\n");
}

void alterar(Pessoa p[], int totalCadastrados, int id) {
    int escolha;
    if (totalCadastrados == 0) {
        printf("Lista vazia\n");
        return;
    } else {
        for (int i = 0; i < totalCadastrados; i++) {
            if (p[i].id == id) {
                //achei na lista
                printf("\n1 - Alterar nome");
                printf("\n2 - Alterar idade");
                printf("\n3 - Alterar status");
                printf("\n4 - Alterar tudo");
                printf("\nEscolha uma opcao:");
                scanf("%d", &escolha);

                switch (escolha) {
                    case 1:
                        printf("1- Alterar nome:\n");
                        fgets(p[i].nome, sizeof(p[i].nome), stdin);
                        size_t length = strlen(p[i].nome);
                        if (length > 0 && p[i].nome[length - 1] == '\n') {
                            p[i].nome[length - 1] = '\0';
                        }
                        break;

                    case 2:
                        printf("\n2 -
