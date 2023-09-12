#include <stdio.h>

void invertir_imprimir(char* cadena) {
    if (*cadena == '\0') {
        return;
    }
    invertir_imprimir(cadena + 1);
    printf("%c", *cadena);
}

int main() {
    char cadena[] = "123456789";
    
    printf("Cadena original: %s\n", cadena);
    printf("Cadena invertida: ");
    invertir_imprimir(cadena);
    printf("\n");
    
    return 0;
}