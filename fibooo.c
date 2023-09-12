#include <stdio.h>

int main() {
    
    double fib[100];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < 100; i++) {
        fib[i] = fib[i-2] + fib[i-1];
    }

    for (int i = 0; i < 100; i++)
    {
        printf("\n %.0f\n", fib[i]);
    }
    
    return 0;
}