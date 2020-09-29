#include<stdio.h>
#include<stdlib.h>

typedef struct Aluno {

    int ra;
    struct Aluno *prox;

};

void inserir(Aluno **ini, Aluno **f);
void listar(Aluno *ini);
Aluno *excluir(Aluno *ini);
Aluno *esvaziar(Aluno *ini);

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
            inicio = excluir(inicio);
            break;

        case '4':
            printf("Esvaziar\n");
            inicio = esvaziar(inicio);
            break;

        case '5':
            printf("Alterar Estrutura\n");
            break;

        }
    }
    while(op!='6');
    return 0;
}

void inserir(Aluno **ini, Aluno **f){
    Aluno *aux = (Aluno *) malloc(sizeof(Aluno));

    if (aux == NULL)
        printf("Sem memoria\n");
    else{
        printf("\nInforme o RA: ");
        scanf("%d", &aux->ra);
        aux->prox = NULL;

        if(*ini == NULL)
            *ini = aux;
        else{
        (*f)->prox = aux;
        }
        *f = aux;
    }

}

void listar(Aluno *ini){
    if(ini == NULL)
        printf("Fila vazia!\n");
    else{
        while(ini!=NULL){
            printf("RA: %d \n", ini->ra);
            ini = ini->prox;
        }
    }

}

Aluno *excluir(Aluno *ini){

    if(ini == NULL)
        printf("Fila Vazia!\n");
    else{
        Aluno *aux = ini->prox;
        free(ini);
        return aux;
    }

    return NULL;

}

Aluno *esvaziar(Aluno *ini){
    if(ini == NULL)
        printf("Fila Vazia!\n");
    else{
        while(ini != NULL){
            ini = excluir(ini);
        }
    }
    return NULL;

}
