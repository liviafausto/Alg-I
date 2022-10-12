#include <stdio.h>
#include "lista06.h"

int main() {
    lista numeros; criar(&numeros);
    elemento item;

    item.codigo = 1; item.paridade = 'i';
    inserir(&numeros, item);

    item.codigo = 2; item.paridade = 'p';
    inserir(&numeros, item);

    item.codigo = 3; item.paridade = 'i';
    inserir(&numeros, item);

    item.codigo = 4; item.paridade = 'p';
    inserir(&numeros, item);

    item.codigo = 5; item.paridade = 'i';
    inserir(&numeros, item);

    item.codigo = 6; item.paridade = 'p';
    inserir(&numeros, item);

    printf("Lista original:\n");
    imprimir(&numeros);

    liberar(&numeros);

    return 0;
}