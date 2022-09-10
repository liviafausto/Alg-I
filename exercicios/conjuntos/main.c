#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conjuntos.h"

int main() {
    conjunto A;

    inicializar(A);
    imprimir(A);

    inserir(1, A);
    inserir(2, A);
    inserir(3, A);
    inserir(4, A);
    inserir(5, A);
    inserir(6, A);
    inserir(7, A);
    inserir(8, A);
    inserir(9, A);
    inserir(10, A);
    inserir(11, A);

    imprimir(A);

    remover(4, A);
    imprimir(A);

    inserir(11, A);
    imprimir(A);
    
    
    return 0;
}