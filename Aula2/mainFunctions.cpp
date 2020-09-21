#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    int ra;
    struct Aluno *prox;
};

int filaVazia(Aluno *);
void inserir(Aluno *, Aluno *, Aluno *);
void listar(Aluno *, Aluno *);
void remover(Aluno *, Aluno *, Aluno *);
void esvaziar(Aluno *, Aluno *, Aluno *);

int main(){
    Aluno *inicio = NULL, *fim, *aux;
    char op;

    do{
        printf("\nDigite 1 - inserir, 2 - listar, 3 - remover, 4 - esvaziar e 5 - sair : ");
        fflush(stdin);
        op = getchar();

        switch(op){

        case '1':
            printf("\nInserir\n");
            aux = (Aluno *) malloc(sizeof(Aluno));

            if(aux == NULL)
                printf("Sem memoria\n");

            else{
                inserir(aux, inicio, fim);
            }

            break;

        case '2':
            printf("\nListar\n");
            filaVazia(inicio);
            listar(aux, inicio);
            break;

        case '3':
            printf("Remover\n");
            filaVazia(inicio);
            remover(aux, inicio, fim);
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

void inserir(Aluno *a, Aluno *i, Aluno *f){

    printf("Digite o RA: ");
    scanf("%d", &a->ra);
    a->prox = NULL;

    if(i == NULL)
        i = a;
    else
        f->prox = a;

    f = a;
}


int filaVazia(Aluno *i){
    if (i == NULL)
                printf("Fila Vazia\n");
                return 0;
}

void listar(Aluno *a, Aluno *i){
    a = i;
    while(a != NULL){
        printf("RA: %d \n", a->ra);
        a = a ->prox;
    }
}

void remover(Aluno *a, Aluno *i, Aluno *f){
    a = i;
    i = i->prox;
    free(a);
    a = f;
}

void esvaziar(Aluno *a, Aluno *i, Aluno *f){
    a = i;
    f = NULL;

    while(a != NULL){
        i = i->prox;
        free(a);
        a = i;
    }
}
