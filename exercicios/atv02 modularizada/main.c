#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"

int main() {
    int Q;

    printf("Insira a quantidade de vetores que serao lidos.\n");
    scanf("%d", &Q);

    vetor v_insertion[Q]; vetor v_merge[Q];
    
    inicializar_vetores(v_insertion, v_merge, Q);
    ler_elementos(v_insertion, v_merge, Q);

    imprimir_insertion(v_insertion, Q);
    imprimir_merge(v_merge, Q);

    liberar_elementos(v_insertion, Q);
    liberar_elementos(v_merge, Q);

    return 0;
}