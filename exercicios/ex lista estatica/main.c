#include <stdio.h>
#include <string.h>
#include "produtos.h"

int main() {
    lista ouro; produto anel; chave codigo_produto;
    
    criar(&ouro);

    int opcao=0;

    while(opcao != 6){
        opcao = menu();

        switch (opcao){
        case 1:
            printf("\nADICIONAR NOVO PRODUTO\n");

            anel = ler_produto();
            if(inserir(&ouro, anel) == SUCESSO)
                printf("O produto %s foi inserido com sucesso.\n\n", anel.nome);

            break;
        
        case 2:
            printf("\nPESQUISAR PRODUTO\n");        

            anel.codigo = ler_codigo();
            if (pesquisar(&ouro, &anel) == SUCESSO)
                imprimir_produto(anel);

            break;

        case 3:
            printf("\nALTERAR PRODUTO\n");

            codigo_produto = ler_codigo();
            if(alterar(&ouro, codigo_produto) == SUCESSO){
                printf("Produto alterado com sucesso.\n");
            }
            break;

        case 4:
            printf("\nREMOVER PRODUTO\n");

            chave codigo_produto = ler_codigo();
            if (remover(&ouro, codigo_produto) == SUCESSO)
                printf("Produto removido com sucesso.\n");

            break;
        
        case 5: //imprimir lista
            printf("\nLISTA\n");
            imprimir_lista(&ouro);
            break;
        
        default:
            if(opcao != 6){
                printf("Insira uma opcao valida.\n");
            }
            break;
        }

    }

    return 0;
}