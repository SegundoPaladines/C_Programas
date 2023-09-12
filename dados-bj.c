#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int pusuario=0;
int pmaquina=0;
int uganados=0;
int mganados=0;
int rondas=1;

//Imprime un texto de forma que parece que alguien lo está escribiendo
void escribirCadena(char cadena []){
    char c = cadena[0];
    int count = 1;
    while (c != '\0')
    {
        printf("%c",c);
        usleep(25000);
        c=cadena[count++];
    }
}

void lanzamientosUsuario(){

    escribirCadena("\n Lanzamientos del Usuario: ");

    pusuario = 0;
    for (int i = 0; i < 3; i++){
        int dado;
        srand(time(NULL));
        dado = rand() % 6 + 1;
        escribirCadena("\n Dado #");
        printf("%d: %d", i, dado);
        pusuario = pusuario+dado;
    }

    while (1){
        escribirCadena("\n Su puntaje actual es: ");
        printf("%d", pusuario);
        escribirCadena("\n1.Si desea detenerse ahora \nEnter para lanzar otro dado \n");
        fflush(stdin);
        char letra = getchar();
        while((letra != '\n')&&(letra!='1')){
            letra = getchar();
        }
        if(letra == '1'){break;}
        else{
            int dado;
            srand(time(NULL));
            dado = rand() % 6 + 1;
            escribirCadena("\n Dado: ");
            printf("%d", dado);
            pusuario=pusuario+dado;
            if(pusuario>21){
                escribirCadena("\nEl puntaje del usuario es: ");
                printf(" %d ",pusuario);
                escribirCadena(" Pierde la ronda\n");
                mganados++;
                break;
            }else if(pusuario == 21){
                escribirCadena("\nEl puntaje del usuario es: 21\n");
                break;
            }
        }
    }

}

void lanzamientosMaquina(){

    escribirCadena("\n Lanzamientos de la Maquina:");

    pmaquina = 0;
    for (int i = 0; i < 3; i++){
        int dado;
        srand(time(NULL));
        dado = rand() % 6 + 1;
        escribirCadena("\n Dado #: ");
        printf("%d: %d", i, dado);
        pmaquina=pmaquina+dado;
    }
    if(pmaquina > pusuario){
        escribirCadena("\n El puntaje actual de la maquina es: ");
        printf("%d ",pmaquina);
        escribirCadena("\nGana la maquina \n"); mganados++;
    }else{
         while(pusuario > pmaquina){
            escribirCadena("\n El puntaje actual de la maquina es: ");
            printf("%d", pmaquina);
            escribirCadena(" \n Decide lanzar denuevo \n ");

            int dado;
            srand(time(NULL));
            dado = rand() % 6 + 1;
            escribirCadena("\n Dado: ");
            printf("%d", dado);
            pmaquina=pmaquina+dado;

            if(pmaquina>21){
                escribirCadena("\nEl puntaje la maquina es: ");
                printf(" %d ",pmaquina);
                escribirCadena("Pierde la ronda\n");
                uganados++;
                break;
            }else if(pmaquina == 21){
                escribirCadena("\nEl puntaje la maquina es: 21 Gana la ronda");
                mganados++;
                break;
            }else if(pmaquina > pusuario){
                escribirCadena("\nEl puntaje la maquina es: ");
                printf(" %d ",pmaquina);
                escribirCadena("Gana la ronda\n");
                mganados++;
                break;
            }else if(pmaquina == pusuario){
                escribirCadena("\nEl puntaje de la maquina es: ");
                printf("%d",pmaquina);
                escribirCadena("Empate \n");
                break;
            }
        }   
    }
}

void funcionReiniciar(){
    uganados=0;
    mganados=0;
    escribirCadena("\n1.Si desea Salir \n Enter para Jugar Denuevo \n");
    fflush(stdin);
    char letra = getchar();
    while((letra != '\n')&&(letra!='1')){
        letra = getchar();
    }

    if(letra == '1'){escribirCadena("Fin Programa"); getchar();}
    else{nuevoJuego();}
}

void nuevoJuego(){
    for (int i = 0; i < 5; i++)
    {
        escribirCadena("\n Nueva ronda: Ronda #");
        printf("%d ",rondas);
        lanzamientosUsuario();
        if(pusuario <= 21){lanzamientosMaquina();}
        rondas++;
    }

    escribirCadena("\n\n La maquina ganó ");
    printf(" %d ",mganados);
    escribirCadena("\n\n El usuario ganó ");
    printf(" %d ",uganados);

    if (uganados > mganados){escribirCadena("\nEl usuario es el ganador\n");}
    else if(uganados == mganados){escribirCadena("\n\nEmpate\n\n");}
    else{escribirCadena("\nLa maquina es el ganador\n");}
    funcionReiniciar();
}

int main(){
    printf("\n______________________________________________________________________________________\n\n");
    setlocale(LC_ALL, "es_ES.utf-8");
    escribirCadena("\n\n Black Jack \n Tira 3 dados inicialmente, luego 1 a la vez \n");
    escribirCadena("\n No debes superar 21 de puntaje o perderás\n");
    escribirCadena("\n Puedes parar en cualquier momento o seguir lanzando\n");
    nuevoJuego();
    return 0;
}