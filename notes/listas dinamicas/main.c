#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dim.h"

int main() {

    lista minhas_series; elemento serie; chave codigo_serie;

    criar(&minhas_series);

    serie = ler_novo_item(&minhas_series, serie);

    if (inserir(&minhas_series, serie) == SUCESSO) {
        printf("O novo item foi inserido na lista com sucesso.\n");
    }

    codigo_serie = ler_chave(codigo_serie);
    serie.codigo = codigo_serie;

    if(pesquisar(&minhas_series, serie) == SUCESSO){
        imprimir_elemento(serie);
    }
    

    //codigo_serie = ler_chave(codigo_serie);

    return 0;
}