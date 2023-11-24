#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// lista vazia 
#define TAM 3 
typedef struct {
    char cadastrar[20];
    int id;
    int status;
}cadastro;

// funçao para substituir o fflush
void limparBuffer(){
    int c ;
    while ((c = getchar ()) != '\n' && c != EOF);
}



int main(){
    cadastro p[TAM];

    int escolher , cadastros = 0 , consulta , relatorio , remoçao ;

    printf("Escolha a funcionalidade:\n");
    printf("1 - Cadastrar\n");
    printf("2 - Consultar produtos\n");
    printf("3 - Gerar relatório de produtos\n");  
    printf("4 - Remover produtos do estoque\n");
    scanf("%d\n",&escolher);

    printf("----------------------------------------");

    switch (escolher)
    {
    case 1:
        /* code */
        break;
    
    default:
        break;
    }


    return 0;
}
