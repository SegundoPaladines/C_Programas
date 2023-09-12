#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <stdlib.h>

// constantes
#define FALSE 0
#define TRUE 1

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
    escribirCadena("\n1. Para recalcular \nEnter Para salir: \n");
    fflush(stdin);
    char letra = getchar();
    while((letra != '\n')&&(letra!='1')){
        letra = getchar();
    }
    if(letra == '1'){calcularImpuestos();}
    else{escribirCadena("Hasta la proxima...");}
}

void calcularImpuestos(){
    double salario = 0;
    double impuestos = 0;
    int casado = FALSE;

    escribirCadena("Ingrese el valor de su salario en dolares\n$");
    scanf("%lf",&salario);
    escribirCadena("Cual es su estado civil? \n1. Casado \n2. Soltero \n3. Otro \n");
    scanf("%d", &casado);

    if((casado != TRUE)&&(salario < 50000)){
        impuestos = 0;
       escribirCadena("caso 1");
    }else if((casado != TRUE)&&(salario >= 50000)&&(salario <= 100000)){
        impuestos = (salario-50000)*0.1;
        escribirCadena("caso 2");
    }else if((casado == 2)&&(salario > 100000)){
        impuestos = (salario-100000)*0.2;
        escribirCadena("caso 3");
    }else if((casado == TRUE)&&(salario < 100000)){
        impuestos = 0;
        escribirCadena("caso 4");
    }else if((casado == TRUE)&&(salario >= 100000)&&(salario <= 200000)){
        impuestos = (salario-100000)*0.1;
        escribirCadena("caso 5");
    }else if((casado == TRUE)&&(salario > 200000)){
        impuestos = (salario-200000)*0.2;
       escribirCadena("caso 6");
    }

    char cadena [250] = "";
    sprintf(cadena, " Impuestos a Pagar: %f", impuestos);
    escribirCadena(cadena);
    funcionPausar();
}

int main(){
    printf("\n______________________________________________________________________________________\n\n");
    setlocale(LC_ALL, "es_ES.utf-8");
    calcularImpuestos();

    return 0;
}