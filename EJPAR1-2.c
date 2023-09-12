#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>

// constantes
#define VERDE 3
#define AMARILLO 2
#define ROJO 1

#define RESET_COLOR "\x1b[0m"
#define ROJO_T      "\x1b[31m"
#define VERDE_T     "\x1b[32m"
#define AMARILLO_T  "\x1b[33m"

//Imprime un texto de forma que parece que alguien lo está escribiendo
void escribirCadena(char cadena []){
    char c = cadena[0];
    int count = 1;
    while (c != '\0')
    {
        printf("%c",c);
        usleep(50000);
        c=cadena[count++];
    }
}

void funcionPausar(){
    printf("\n______________________________________________________________________________________\n");
    escribirCadena("\n1. Para Reiniciar \nEnter Para salir: \n");
    fflush(stdin);
    char letra = getchar();
    while((letra != '\n')&&(letra!='1')){
        letra = getchar();
    }
    if(letra == '1'){calcularSiguiente();}
    else{escribirCadena("Hasta la proxima...");}
}

void calcularSiguiente(){
    escribirCadena("Ingrese el Color Actual:");
    printf(ROJO_T "\n");
    escribirCadena("1. Rojo");
    printf(AMARILLO_T "\n");
    escribirCadena("2. Amarillo");
    printf(VERDE_T "\n");
    escribirCadena("3. Verde");
    printf(RESET_COLOR "\n");
    int color=0;
    scanf("%d", &color);

    if(color == ROJO){
        escribirCadena("Sige el color: ");
        printf(VERDE_T " ");
        escribirCadena("Verde");
        printf(RESET_COLOR "\n");
    }else if(color == AMARILLO){
        escribirCadena("Ingrese el Color Anterior:");
        printf(ROJO_T "\n");
        escribirCadena("1. Rojo");
        printf(VERDE_T "\n");
        escribirCadena("2. Verde");
        printf(RESET_COLOR "\n");
        scanf("%d", &color);
        if(color == ROJO){
            escribirCadena("Sige el color: ");
            printf(VERDE_T " ");
            escribirCadena("Verde");
            printf(RESET_COLOR "\n");
        }else if(color == 2){
            escribirCadena("Sige el color: ");
            printf(ROJO_T " ");
            escribirCadena("Rojo");
            printf(RESET_COLOR "\n");
        }else{escribirCadena("\nEl color ingresado es Invalido\n");}
    }else if(color == VERDE){
        escribirCadena("Sige el color: ");
        printf(ROJO_T " ");
        escribirCadena("Rojo");
        printf(RESET_COLOR "\n");
    }else{escribirCadena("\nEl color ingresado es Invalido\n");}
    funcionPausar();
}

int main(){
    printf("\n______________________________________________________________________________________\n\n");
    setlocale(LC_ALL, "es_ES.utf-8");
    calcularSiguiente();

    return 0;
}