#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void orAscburbuja(int vector[], int tamano) {
  for (int i = 0; i < tamano - 1; i++) {
    for (int j = 0; j < tamano - i - 1; j++) {
      if (vector[j] > vector[j + 1]) {
        int tmp = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = tmp;
      }
    }
  }
}

int main() {

  int vector[]={10,15,5,15,7,8,1,2,3,4};

    orAscburbuja(vector,10);

    for (int i = 0; i < 10; i++)
    {
         printf("\n %d",vector[i]);
    }
    
  return 0;
}