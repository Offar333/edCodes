#include <stdio.h>

int main(void){
    int a, *b, c;
    a =5;
    b = &a;
    c = 10;
    scanf("%d", b);
    printf("%d %d\n", a, c);

}
