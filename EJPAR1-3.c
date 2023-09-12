#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

char numero[3];
int intento;

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
    escribirCadena("\n1. Continuar \nEnter Para Rendirse: \n");
    fflush(stdin);
    char letra = getchar();
    while((letra != '\n')&&(letra!='1')){
        letra = getchar();
    }
    if(letra == '1'){
        escribirCadena("\nLos numeros se pueden repetir Ejm: 111...\n");
        nuevoIntento();
    }
    else{
        escribirCadena("HA FALLADO!, El numero era: ");
        escribirCadena(numero);
        escribirCadena(", Hasta la proxima...");}
}

void funcionReiniciar(){
    escribirCadena("\n1. Nuevo Juego \nEnter Para Salir: \n");
    fflush(stdin);
    char letra = getchar();
    while((letra != '\n')&&(letra!='1')){
        letra = getchar();
    }
    if(letra == '1'){
        printf("\n______________________________________________________________________________________\n\n");
        int numero_aleatorio;
        srand(time(NULL));
        numero_aleatorio = rand() % 900 + 100;
        sprintf(numero, "%d", numero_aleatorio);
        //printf(numero);
        intento = 1;
        nuevoIntento();
    }
    else{escribirCadena("Hasta la proxima...");}
}

void nuevoIntento(){

    int adivinado = 0;
    escribirCadena("\nIntente adivinar el numero de 3 cifras");
    escribirCadena("\nBomba: Digito correcto posicion correcta");
    escribirCadena("\nMisil: Digito correcto posicion incorrecta");

    for (int k = 0; k < 4; k++)
    {
        char cadena[20];
        sprintf(cadena, "\nIntento #%d Num: ", intento);
        escribirCadena(cadena);

        fflush(stdin);
        char entrada[4];
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        int bombas = 0;
        int misiles = 0;
        int count = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(entrada[i] == numero [j]){
                    if(i == j){bombas++;}
                    else{misiles++;}
                }
            }        
        }
        
        if(bombas>2){
            escribirCadena("FELICIDADES, Adivinaste");
            char cadena[20];
            sprintf(cadena, "\n#Intentos %d ", intento);
            escribirCadena(cadena);
            escribirCadena(" Numero: ");
            escribirCadena(numero);
            k=10;
            adivinado=1;
        }else{
            escribirCadena("Bombas: ");
            char c[1];
            sprintf(c, "%d", bombas);
            escribirCadena(c);
            sprintf(c, "%d", misiles);
            escribirCadena(", Misiles: ");
            escribirCadena(c);
        }
        intento++;
    }
    if(adivinado == 0){funcionPausar();}
    else{funcionReiniciar();}
}

int main(){
    printf("\n______________________________________________________________________________________\n\n");
    setlocale(LC_ALL, "es_ES.utf-8");
    int numero_aleatorio;
    srand(time(NULL));
    numero_aleatorio = rand() % 900 + 100;
    sprintf(numero, "%d", numero_aleatorio);
    //printf(numero);
    intento = 1;
    nuevoIntento();

    return 0;
}