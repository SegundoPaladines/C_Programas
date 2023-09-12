#include <stdio.h>
#include <math.h>

int main() {
    double serie[10];
    serie[0]=0;
    serie[1]=1;

    printf("0, 1, ");

    for (int i = 2; i < 10; i++)
    {
        serie[i]=2*(1+serie[i-1]*serie[i-2])-3*serie[i-2];
        printf("%.0f,  ", serie[i]);
    }

    return 0;
}