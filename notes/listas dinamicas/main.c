#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dim.h"

int main() {

    lista minhas_series; elemento serie;
    criar(&minhas_series);

    int opcao=0;

    while(opcao != 6){
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

                if(pesquisar(&minhas_series, &serie) == SUCESSO){
                    imprimir_elemento(serie);
                }
                break;
            
            case 3: //remover
                printf("REMOVER ITEM DA LISTA\n");
                serie.codigo = ler_chave(serie.codigo);
                
                if(remover(&minhas_series, serie.codigo) == SUCESSO){
                    imprimir(&minhas_series);
                }
                break;

            case 4: //alterar
                printf("ALTERAR ITEM DA LISTA\n");
                serie.codigo = ler_chave(serie.codigo);

                if (alterar(&minhas_series, serie) == SUCESSO){
                    imprimir(&minhas_series);
                }

                break;

            case 5: //imprimir lista
                imprimir(&minhas_series);
                break;

            case 6:
                liberar_lista(&minhas_series);
                break;
            
            default:
                printf("Opcao invalida, tente novamente.\n\n");
                break;
        }

    }

    return 0;
}