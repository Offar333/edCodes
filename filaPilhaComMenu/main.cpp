#include<stdio.h>
#include<stdlib.h>

typedef struct Aluno {

    int ra;
    struct Aluno *prox;

};

//prototipos
void inserir (Aluno **i, Aluno **f);

int main(){

    Aluno *inicio = NULL, *fim;
    char op;


    do{
        printf("Digite 1 - inserir, 2 - listar, 3 - remover, 4 - esvaziar, 5 - Alterar Estrutura, 6 - Sair: ");
        fflush(stdin);
        op = getchar();

        switch(op){

        case '1':
            printf("Inserir\n");
            inserir(&inicio, &fim);
            break;

        case '2':
            printf("Listar\n");
            break;

        case '3':
            printf("Excluir\n");
            break;

        case '4':
            printf("Esvaziar\n");
            break;

        case '5':
            printf("Alterar Estrutura\n");
            break;

        }
    }
    while(op!='6');
    return(0);
}

void inserir (Aluno **i, Aluno **f){
    Aluno *aux;
    aux = (Aluno *) malloc(sizeof(Aluno));

    if(aux == NULL)
        printf("Sem memoria!");

    printf("Digite o RA: ");
    scanf("%d", aux->ra);

    if(*i == NULL)
        *i = aux;
    else
        (*f)->prox = aux;

    *f = aux;

}
