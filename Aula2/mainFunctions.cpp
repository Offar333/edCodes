#include <stdio.h>
#include <stdlib.h>

typedef struct Pipoca{

    char sabor[25];
    int serie;
    int dataFab;
    int horaFab;
    struct Pipoca *prox;
};

void inserir(Pipoca **i, Pipoca **f);
void listar(Pipoca *i);
Pipoca *vender(Pipoca *i);


int main(){
    Pipoca *inicio = NULL, *fim;
    char op;

    do{
        printf("\nDigite 1 - inserir pipoca, 2 - listar estoque, 3 - vender pipoca e 4 - sair : ");
        fflush(stdin);
        op = getchar();

        switch(op){

        case '1':
            printf("\nInserir\n");
            inserir(&inicio, &fim);
            break;

        case '2':
            printf("\nListar\n");
            listar(inicio);
            break;

        case '3':
            printf("Remover\n");
            inicio = vender(inicio);
            break;

        default:
            printf("Sair\n");
            break;
        }

    }while (op != '4');
    return 0;
}

void inserir(Pipoca **i, Pipoca **f){

    Pipoca *aux;
    aux = (Pipoca *) malloc(sizeof(Pipoca));

    if(aux == NULL)
    printf("Sem memoria\n");
    //sabor, série e a data e hora de fabricação
    printf("\nInforme o sabor: ");
    scanf("%s", &aux->sabor);
    printf("\nInforme a serie: ");
    scanf("%d", &aux->serie);
    printf("\nInforme a data de fabricacao (somente numeros): ");
    scanf("%d", &aux->dataFab);
    printf("\nInforme a hora de fabricacao: ");
    scanf("%d", &aux->horaFab);
    aux->prox = NULL;

    if(*i == NULL)
        *i = aux;
    else
        (*f)->prox = aux;

    *f = aux;
}



void listar(Pipoca *i){
    if(i == NULL){
        printf("\nSem pipocas no estoque!");
    }
    while(i != NULL){
        printf("Sabor: %s \n", i->sabor);
        printf("Nro Serie: %d \n", i->serie);
        printf("Data de Fabricacao: %d \n", i->dataFab);
        printf("Hora de Fabricacao: %d \n", i->horaFab);
        i = i->prox;
    }
}

Pipoca *vender(Pipoca *i){
    Pipoca *aux = i->prox;
    free(i);
    return aux;
}

