#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conjuntos.h"

int main() {
    conjunto idades;
    int v[10];

    inicializar(idades);

    printf("Digite 10 idades diferentes.\n");
    for(int i=0; i<10; i++){
        scanf("%d", &v[i]);

        inserir(v[i], idades);
    }

    imprimir(idades);
    
    return 0;
}