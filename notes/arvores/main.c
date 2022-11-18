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

    pre_order(&arvore_binaria);
    printf("\n");

    folha = pesquisar(&arvore_binaria, 6);

    if(folha.codigo < 0){
        printf("Nao foi possivel encontrar essa folha.\n");
    } else {
        printf("Codigo encontrado: %d\n", folha.codigo);
    }

    if(remover(&arvore_binaria, 10) == SUCESSO){
        printf("10 removido com sucesso.\n");
    }

    if(remover(&arvore_binaria, 12) == SUCESSO){
        printf("12 removido com sucesso.\n");
    }
    
    if(remover(&arvore_binaria, 4) == SUCESSO){
        printf("4 removido com sucesso.\n");
    }

    pre_order(&arvore_binaria);
    printf("\n");

    return 0;
}