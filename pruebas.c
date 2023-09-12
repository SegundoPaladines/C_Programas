#include <stdio.h>

int main() {
    int x = 5;
    int y = 6;
    int *puntero = &x;
    *puntero = (*puntero) * y;
    printf("x = %d\n", x);
    return 0;
}




