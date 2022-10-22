#include <stdio.h>
#include "arvore.h"

int main() {
    arvore arvore_binaria; criar(&arvore_binaria);

    elemento folha;
    folha.codigo = 8;
    inserir(&arvore_binaria, folha);
    
    folha.codigo = 4;
    inserir(&arvore_binaria, folha);

    folha.codigo = 12;
    inserir(&arvore_binaria, folha);

    folha.codigo = 2;
    inserir(&arvore_binaria, folha);

    folha.codigo = 6;
    inserir(&arvore_binaria, folha);

    folha.codigo = 10;
    inserir(&arvore_binaria, folha);

    folha.codigo = 14;
    inserir(&arvore_binaria, folha);

    return 0;
}