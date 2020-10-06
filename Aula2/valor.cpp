#include <stdio.h>

int tabuada(int numero1, int numero2);

int main(){
    int n = 2, r =0, i;

    printf("Tabuada por Valor\n");

    for(i = 0; i < 11; i++){

	r = tabuada(n, i);
	printf("%d vezes %d eh: %d \n", n, i, r);

    }


return 0;
}

int tabuada(int numero1, int numero2 ){

	int resultado = numero1 * numero2;
	return resultado;
}

