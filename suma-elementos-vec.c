#include <stdio.h>

int sumaLista(int vector[], int pos, int suma) {
    if (pos == 0) {
        return suma;
    }
    else{
        suma = suma + vector[pos];
        sumaLista(vector, pos--, suma);
    }
    
}

int main() {
    int vector[] = {1, 2, 3, 4, 5}; 

    int suma = sumaLista(vector, 4, 0);
    printf("La suma de los elementos del vector es: %d\n", suma);
    return 0;
}