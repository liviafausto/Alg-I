#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conjuntos.h"

int main() {
    conjunto idades;

    inicializar(idades);
    imprimir(idades);

    inserir(19, idades);
    imprimir(idades);
    inserir(27, idades);
    imprimir(idades);

    remover(20, idades);
    inserir(13, idades);
    imprimir(idades);
    inserir(201, idades);
    imprimir(idades);
    inserir(0, idades);
    inserir(-1, idades);
    imprimir(idades);
    
    return 0;
}