#include <stdio.h>
#include "lista06.h"

int main() {
    lista numeros; criar(&numeros);
    elemento item;

    printf("Insira os 7 numeros da lista.\n\n");
    
    for(int i=0; i<7; i++){
        printf("Numero: "); scanf("%d", &item.codigo);
        inserir(&numeros, item);
    }

    printf("Lista original:\n");
    imprimir(&numeros);

    printf("Lista com elementos de posicoes pares antes dos impares:\n");
    rearranjar(&numeros);
    imprimir(&numeros);

    liberar(&numeros);

    return 0;
}