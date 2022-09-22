#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dim.h"

int main() {
    lista minhas_series; elemento nova_serie;

    criar(&minhas_series);

    nova_serie = ler_novo_item(&minhas_series, nova_serie);

    if (inserir(&minhas_series, nova_serie)) {
        printf("SUCESSO!\n");
    }
}