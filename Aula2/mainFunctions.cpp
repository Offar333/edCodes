#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    int ra;
    struct Aluno *prox;
};

int filaVazia(Aluno *);
void inserir(Aluno **i, Aluno **f);
void listar(Aluno *i);
Aluno *remover(Aluno *i);
Aluno *esvaziar(Aluno *i);

int main(){
    Aluno *inicio = NULL, *fim;
    char op;

    do{
        printf("\nDigite 1 - inserir, 2 - listar, 3 - remover, 4 - esvaziar e 5 - sair : ");
        fflush(stdin);
        op = getchar();

        switch(op){

        case '1':
            printf("\nInserir\n");
            inserir(&inicio, &fim);
            break;

        case '2':
            printf("\nListar\n");
            filaVazia(inicio);
            listar(inicio);
            break;

        case '3':
            printf("Remover\n");
            filaVazia(inicio);
            inicio = remover(inicio);
            break;

        case '4':
            printf("Esvaziar\n");
            filaVazia(inicio);
            esvaziar(aux, inicio, fim);

            break;

        case '5':
            printf("Sair\n");
            break;
        }

    }while (op != '5');
    return 0;
}

void inserir(Aluno **i, Aluno **f){

    Aluno *aux;
    aux = (Aluno *) malloc(sizeof(Aluno));

    if(aux == NULL)
        printf("Sem memoria\n");

    printf("Digite o RA: ");
    scanf("%d", &aux->ra);
    aux->prox = NULL;

    if(*i == NULL)
        *i = aux;
    else
        (*f)->prox = aux;

    *f = aux;
}


int filaVazia(Aluno *i){
    if (i == NULL)
        printf("Fila Vazia\n");
        return NULL;
}

void listar(Aluno *i){
    while(i != NULL){
        printf("RA: %d \n", i->ra);
        i = i->prox;
    }
}

Aluno *remover(Aluno *i){
    Aluno *aux = ini->prox;
    free(ini);
    return aux;
}

Aluno *esvaziar(Aluno *i){
    while(i != NULL){
        ini = remover(ini);
}
