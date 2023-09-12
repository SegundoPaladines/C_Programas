#include <stdio.h>
#include <unistd.h>


int main(){
    char list_ch [4] [2] = {
        {'A','a'},
        {'B','b'},
        {'C','c'},
        {'D','d'}
    };


    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
         printf("%c ", list_ch[i][j]);
      }
      printf("\n");
   }  
    return 0;
}

