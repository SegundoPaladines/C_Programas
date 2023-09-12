#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PALABRAS 30
#define MAX_LONGITUD_PALABRA 20
#define MAX_INTENTOS 30

int texto = 0;
char aux[20];

void escribirCadena(char cadena []){
    char c = cadena[0];
    int count = 1;
    while (c != '\0')
    {
        printf("%c",c);
        usleep(10000);
        c=cadena[count++];
    }
}

void escribrirTexto(int texto){
    if(texto == 1){
        escribirCadena("En la cocina, el chef preparaba exquisitos platos. En el transito, ");
        escribirCadena("los conductores evitaban accidentes. En una tienda de ropa, un cliente ");
        escribirCadena("elegia una camisa y un pantalon. Un camionero conducia su camion lleno de mercancias.");
    }else if(texto == 2){
        escribirCadena("En tecnologia, los dispositivos electronicos son cada vez mas innovadores. Los amantes del ");
        escribirCadena("deporte celebraban en el estadio. El dentista atendia a pacientes de todas las edades. El ");
        escribirCadena("medico y el cirujano cuidaban de la salud. El veterinario se ocupaba de las mascotas.");
    }else if(texto == 3){
        escribirCadena("En las carreteras, los motociclistas se desplazaban agilmente. Los profesores impartian ");
        escribirCadena("conocimientos a los estudiantes. El director supervisaba la escuela. El escritor creaba ");
        escribirCadena("nuevas historias.");
    }
}

char palabras[MAX_PALABRAS][MAX_LONGITUD_PALABRA] = {
    "cocina",
    "chef",
    "platos",
    "transito",
    "conductores",
    "tienda",
    "ropa",
    "cliente",
    "camisa",
    "camionero",
    "dispositivos",
    "innovadores",
    "amantes",
    "deporte",
    "estadio",
    "dentista",
    "pacientes",
    "edades",
    "cirujano",
    "salud",
    "veterinario",
    "mascotas",
    "carreteras",
    "motociclistas",
    "profesores",
    "estudiantes",
    "director",
    "escuela",
    "scritor",
    "historias"
};

char* palabraAleatoria() {
    srand(time(NULL));
    int indice = rand() % MAX_PALABRAS;

    if(indice<10){
        texto=1;
    }else if(indice<22){
        texto=2;
    }else{
        texto=3;
    }
    return palabras[indice];
}

void comparar(char *palabra, char entrada){
    char c = palabra[0];
    int count = 0;
    while (c != '\0')
    {
        if(palabra[count] == entrada){
            aux[count]=entrada;
        }
        c=palabra[count++];
    }
}

void llenarAux(char *palabra){
    char c = palabra[0];
    int count = 0;
    while (c != '\0') 
    {
        aux[count]='X';
        count++;
        c=palabra[count];
    }
    aux[count]='\0';
}
void nuevoJuego(){
     char* palabra = palabraAleatoria();
    escribirCadena("\n******************TEXTO**************** \n");
    escribrirTexto(texto);
    escribirCadena("\n******************FIN TEXTO**************** \n");
    escribirCadena("\n Adivina la palabra de acuerdo al texto anterior: \n");
    int intentos = 0;

    llenarAux(palabra);
    
    while (intentos < MAX_INTENTOS)
    {
        if(strcmp(palabra, aux) == 0){
            escribirCadena("\n FELICIDADES HA ADIVINADO LA PALABRA\n palabra:");
            escribirCadena(palabra);
            escribirCadena(" En ");
            printf("%d",intentos);
            escribirCadena(" Intentos\n");
            break;
        }else{
            escribirCadena("\nIntento# :");
            printf("%d",intentos+1);
            escribirCadena("\nPista: ");
            escribirCadena(aux);
            printf("\n");
            char entrada = getchar();
            comparar(palabra,entrada);
        }
        intentos++;
    }
    funcionPausar();
}

void funcionPausar(){
    escribirCadena("\nFIN DEL JUEGO...\n");
    escribirCadena("\n1.Si desea Salir \nEnter para Jugar Denuevo \n");
    fflush(stdin);
    char letra = getchar();
    while((letra != '\n')&&(letra!='1')){
        letra = getchar();
    }

    if(letra == '1'){escribirCadena("Fin Programa"); getchar();}
    else{nuevoJuego();}
}

int main() {
    nuevoJuego();
    return 0;
}
