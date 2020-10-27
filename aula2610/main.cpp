#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

typedef struct Aluno{

    int ra;
    Aluno *prox;

};

Aluno *novoElemento();
void listar(Aluno *ini);
Aluno *remover(Aluno *ini);
Aluno *esvaziar(Aluno *ini);
Aluno *insereInicio(Aluno *ini);
void insereMeio(Aluno *enc);
Aluno *insereFim(Aluno *f);
char opcao();
void inserir(Aluno **ini, Aluno **f);
Aluno *localizar(Aluno *enc, int r);


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
            inicio = remover(inicio);
            break;

        case '4':
            printf("Esvaziar\n");
            inicio = esvaziar(inicio);
            break;

        case '5':

            break;

        default:
            inicio = esvaziar(inicio);

        }
    }
    while(op!='6');

    return 0;

}

Aluno *novoElemento(){
    return (Aluno *) malloc(sizeof(Aluno));
}

void listar(Aluno *ini){
    if(ini == NULL)
        printf("Fila vazia\n");

    else{
        while(ini != NULL){
            printf("RA: %d \n", ini->ra);
            ini = ini->prox;
        }
    }

}

Aluno *remover(Aluno *ini){
    if(ini == NULL)
        printf("Fila Vazia\n");

    else{
        Aluno *aux = ini->prox;
        free(ini);
        return aux;
    }

    return NULL;

}

Aluno *esvaziar(Aluno *ini){

        if(ini == NULL)
            printf("Fila Vazia\n");

        else
            while(ini!=NULL){
                ini = remover(ini);
            }
            return ini;
}

Aluno *insereInicio(Aluno *ini){
    Aluno *aux = novoElemento();
    aux->prox = ini;
    return aux;
}

void insereMeio(Aluno *enc){
    Aluno *aux = novoElemento();
    aux->prox = enc->prox;
    enc->prox = aux;
}

Aluno *insereFim(Aluno *f){
    Aluno *aux = novoElemento();
    aux->prox = NULL;
    f->prox = aux;
    return aux;
}

char opcao(){
    char op;
    do{
        printf("Deseja inserir antes ou depois? Digite (A)ntes ou (D)epois: ");
        op = toupper(getchar());
        if(op != 'A' || op != 'D'){
            printf("Opcao invalida!");
        }
    }while(op != 'A' || op != 'D');
    return op;
}

void inserir(Aluno **ini, Aluno **f){
    Aluno *aux;
    if(*ini == NULL){
        aux = novoElemento();
        aux->prox = NULL;
        *ini = *f = aux;
    }else if(*ini ==*f){
        if(opcao() == 'A')
            *ini = insereInicio(*ini);
        else
            *f = insereFim(*f);
        }else{
            int raProc;
            printf("Deseja inserir antes/depois de qual elemento?");
            scanf("%d", &raProc);
            char op = opcao();
            if((*ini)->ra == raProc){
                if(op == 'A')
                    *ini = insereInicio(*ini);
                else
                    insereMeio(*ini);
            }else if(op == 'D' && (*f)->ra == raProc)
                *f = insereFim(*f);
        else{
            Aluno *enc = localizar(*ini, raProc);
            if(enc == NULL)
                printf("Impossivel inserir... Pivo nao encontrado!");
            else{
                if(op == 'D')
                    enc = enc->prox;
                insereMeio(enc);
            }
        }
    }
}

Aluno *localizar(Aluno *enc, int r){
    while(enc->prox != NULL && enc->prox->ra != r)
        enc = enc->prox;
    if (enc->prox == NULL)
        return NULL;
    else
        return enc;

}
