#include <stdio.h>

int siguientePeell(int a, int b){
    return 2*b+a;
}

int seriePell(int a, int b, int val){
    int c = siguientePeell(a,b);
    printf("%d  ",c);
    val--;
    //Parte recursiva
    if(val>0){seriePell(b, c, val);}
}

int main() {

    int max_p=0;
    printf("\nIngrese la cantidad de numeros de la serie Pell que desea Imprimir:\n");
    scanf("%d", &max_p);
    printf("\nPRIMEROS %d NUMEROS DE LA SERIE DE PELL:\n");
    printf("0  1  ");
    seriePell(0, 1, max_p-2);

    return 0;
}
