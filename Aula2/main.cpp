#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    int ra;
    struct Aluno *prox;
};

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
                printf("Digite o RA: ");
                scanf("%d", &aux->ra);
                aux->prox = NULL;

                if(inicio == NULL)
                    inicio = aux;
                else
                    fim->prox = aux;

                fim = aux;
            }

            break;

        case '2':
            printf("\nListar\n");
            if (inicio == NULL)
                printf("Fila Vazia\n");
            else{
                aux = inicio;
                while(aux != NULL){
                    printf("RA: %d \n", aux->ra);
                    aux = aux ->prox;
                }
            }

            break;

        case '3':
            printf("Remover\n");
            if (inicio == NULL)
                printf("Fila Vazia\n");
            else{
                aux = inicio;
                inicio = inicio->prox;
                free(aux);
                inicio = aux;
                }

            break;

        case '4':
            printf("Esvaziar\n");
            if (inicio == NULL)
                printf("Fila Vazia\n");
            else{
                aux = inicio;
                fim = NULL;
                while(aux != NULL){
                    inicio = inicio->prox;
                    free(aux);
                    aux = inicio;
                }
            }
            break;

        case '5':
            printf("Sair\n");
            while(inicio != NULL){
                aux = inicio -> prox;
                free(inicio);
                inicio = aux;
            }
            break;

        default:

            printf("Opcao invalida!");

        }

    }while (op != '5');
    return 0;
}
