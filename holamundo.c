#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>

#define TAMANO_MAXIMO_CADENA 1000

//Imprime un texto de forma que parece que alguien lo está escribiendo

void escribirCadena(char cadena []){
    char c = cadena[0];
    int count = 1;
    while (c != '\0')
    {
        printf("%c",c);
        usleep(100000);
        c=cadena[count++];
    }
}

int main(){
    setlocale(LC_ALL, "es_ES.utf-8");
    escribirCadena("Hola, ¿como estás?\n");
    while(1){
        char cadena [TAMANO_MAXIMO_CADENA];
        fgets(cadena, TAMANO_MAXIMO_CADENA, stdin);
        cadena[strcspn(cadena, "\n")]='\0';
        if((strcmp(cadena, "salir") != 0) && (strcmp(cadena, "chao") != 0) && (strcmp(cadena, "adios") != 0)){
            escribirCadena(cadena);
            printf("\n");
        }else{break;}
    }
    escribirCadena("Hasta la proxima\n");
    char c[TAMANO_MAXIMO_CADENA];
    scanf(c);
    return 0;
}