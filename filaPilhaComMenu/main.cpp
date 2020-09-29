#include<stdio.h>
#include<stdlib.h>

typedef struct Aluno {

    int ra;
    struct Aluno *prox;

};

//prototipos
void inserir (Aluno **i, Aluno **f);
void listar(Aluno *i);

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
            listar(inicio);
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
    else{
        printf("\nDigite o RA: ");
        scanf("%d", &aux->ra);
        aux->prox = NULL;
        if(*i == NULL)
            *i = aux;
        else
            (*f)->prox = aux;
         *f = aux;
    }
}

void listar(Aluno *i){
    if(i == NULL){
        printf("Fila vazia");
    }else{
        while(i != NULL);{
            printf("\nRA: %d", i->ra);
            i = i->prox;
        }
    }
}

