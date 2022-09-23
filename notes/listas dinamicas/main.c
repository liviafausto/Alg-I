#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dim.h"

int main() {

    lista minhas_series; elemento serie;
    criar(&minhas_series);

    int opcao=0;

    while(opcao != 5){
        opcao = menu(opcao);

        switch (opcao){
            case 1: //inserir
                printf("INSERIR NOVO ITEM NA LISTA\n");
                serie = ler_novo_item(serie);

                if (inserir(&minhas_series, serie) == SUCESSO) {
                    printf("O novo item foi inserido na lista com sucesso.\n");
                }
                break;

            case 2: //pesquisar
                printf("PESQUISAR ITEM DA LISTA\n");
                serie.codigo = ler_chave(serie.codigo);

                if(pesquisar(&minhas_series, serie) == SUCESSO){
                    printf("Item encontrado.\n");
                }
                break;
            
            case 3: //remover
                printf("REMOVER ITEM DA LISTA\n");
                serie.codigo = ler_chave(serie.codigo);
                
                if(remover(&minhas_series, serie.codigo) == SUCESSO){
                    imprimir(&minhas_series);
                }
                break;
            
            default:
                if(opcao != 5){
                    printf("Opcao invalida, tente novamente.\n\n");
                }
                break;
        }

    }

    return 0;
}