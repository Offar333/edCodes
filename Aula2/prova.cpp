
#include <stdio.h>

void tabuada(int *val1, int *val2, int *res);

int main(){
	int n = 2, r =0, i;

	printf("Tabuada por Referencia\n");

	for(i = 0; i < 11; i++){

	tabuada(&n, &i, &r);
	printf("%d vezes %d eh: %d \n", n, i, r);

	}

return 0;

}

void tabuada(int *val1, int *val2, int *res){

	*res = (*val1)*(*val2);

}

