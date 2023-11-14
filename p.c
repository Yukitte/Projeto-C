#include<stdio.h>
#define TAM 3
//modelo do registro
typedef struct{
    char nome[20];
    int idade;
    int id;
    int status;
}Aluno;

void cadastrar(Aluno a[], int indice){
    a[indice].status = 1;
    a[indice].id = rand() % 200;
    fflush(stdin);
    printf("\nDigite o nome do aluno: ");
    fflush(stdin);
    fgets(a[indice].nome, sizeof(a[indice].nome), stdin);
    fflush(stdin);
    printf("Digite a idade do aluno: ");
    fflush(stdin);
    scanf("%d", &a[indice].idade);
    fflush(stdin);
    printf("\n\n");
}

void imprimir(Aluno a[], int totalCadastro){
    if(totalCadastro == 0 ){
        printf("\n\nnao existem alunos cadastrados");
    }else{
        for(int i = 0; i < totalCadastro; i++ ){
            printf("Id: %d", a[i].id);
            printf("\nNome: %s", a[i].nome);
            printf("\nIdade: %d", a[i].idade);
            a[i].status == 1 ? printf("\nStatus : Ativo"): printf("\nStatus : Inativo");
            printf("\n\n");
        }
    }
}
void buscarRegistro(Aluno a[], int totalCadastro, int buscarId){
    if(totalCadastro == 0){
        printf("\nNao existe cadastros na lista\n");
        return;
    }else{
        for(int i = 0; i < totalCadastro; i++){
            if(a[i].id == buscarId){
                printf("\nNome do registro encontrado: %s", a[i].nome);
                return;
            }
        }
    }
    printf("\nRegistro nao encontrado na lista");
}
void alterarRegistro(Aluno a[], int totalCadastro, int buscarId){
    int opcaoEscolhida;
    if(totalCadastro == 0 ){
        printf("Lista vazia");
        return;
    }else{
        for(int i = 0 ; i < totalCadastro; i++){
            if(a[i].id == buscarId){
                printf("\nNome: %s ", a[i].nome);
                printf("\nIdade: %d ", a[i].idade);
                a[i].status == 1 ? printf("\nStatus : Ativo"): printf("\nStatus : Inativo");

                printf("\nAlterar os dados: ");

                printf("Digite 1 para alterar o nome, Digite 2 para alterar a idade, Digite 3 para alterar o status ou Digite 4 para alterar todos os campos");
                scanf("%d", &opcaoEscolhida);
                switch (opcaoEscolhida){
                    case 1: 
                        printf("Alteracao do nome: ");
                         fflush(stdin);
                        fgets(a[i].nome, sizeof(a[i].nome), stdin);
                         fflush(stdin);
                    break;
                    case 2: 
                        printf("Alteracao da idade: ");
                         fflush(stdin);
                        scanf("%d", &a[i].idade);
                         fflush(stdin);
                    break;
                    case 3: 
                        printf("Alteracao do status: 1 - Ativo / 0 - Inativo");
                         fflush(stdin);
                        scanf("%d", &a[i].status);
                         fflush(stdin);
                    break;
                    case 4:
                        printf("Alteracao do nome: ");
                        fflush(stdin);
                        fgets(a[i].nome, sizeof(a[i].nome), stdin);
                        fflush(stdin);
                        printf("Alteracao da idade: ");
                        scanf("%d", &a[i].idade);
                        fflush(stdin);
                        printf("Alteracao do status: 1 - Ativo / 0 - Inativo");
                        fflush(stdin);
                        scanf("%d", &a[i].status);
                        fflush(stdin);
                }
            }
        }
    }
}

int excluirRegistro(Aluno a[], int totalCadastro, int buscarId){
    int achou;
    for(int i = 0; i < totalCadastro; i++){
            if(a[i].id == buscarId){
                //registro encontrado
                //exclusão
                for(int j = i; j < totalCadastro - 1; j++ ){
                    a[j] = a[j + 1];
                }
                achou = 1;
                printf("\nExcluido com sucesso");
                return achou;
            }
        }
        achou  = 0;
        return achou;
}
    


main(){
    Aluno a[TAM];
    int opcao, totalCadastro = 0, buscarId;

    do{
        printf("\nDigite 1 para cadastrar");
        printf("\nDigite 2 para imprimir os cadastros");
        printf("\nDigite 3 para buscar um cadastro");
        printf("\nDigite 4 para alterar um cadastro");
        printf("\nDigite 5 para excluir um cadastro");
        printf("\nDigite 0 para encerrar o programa");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                //cadastra
                if(totalCadastro < TAM ){
                    cadastrar(a, totalCadastro);
                    totalCadastro++;
                }else{
                    printf("\n\nLimite maximo de cadastro atingido");
                }
                break;
            case 2:
                //mostra todos os cadastros
                imprimir(a, totalCadastro);
                break;
            case 3:
                //buscar 
                printf("Digite o id para buscar");
                scanf("%d", &buscarId);
                buscarRegistro(a, totalCadastro, buscarId);
                break;
            case 4:
                //alterar
                printf("Digite o id para alterar");
                scanf("%d", &buscarId);
                alterarRegistro(a, totalCadastro, buscarId);
                break;
            case 5:
                //excluir
                printf("Digite o id para excluir");
                scanf("%d", &buscarId);
                if(totalCadastro == 0){
                    printf("Lista vazia");
                }else{
                    int res = excluirRegistro(a, totalCadastro, buscarId);
                    if(res == 1){
                        totalCadastro--;
                    }else{
                        printf("Não foi possivel excluir - aluno nao encontrado");
                    }
                }
 
                break;
        }
    }while(opcao != 0);
}
