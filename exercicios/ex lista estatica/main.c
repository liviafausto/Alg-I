#include <stdio.h>
#include <string.h>
#include "produtos.h"

int main() {
    lista ouro;
    criar(&ouro);

    produto novo; chave codigo_produto; int opcao=0;

    do {
        printf("Digite:\n1- Adicionar novo produto.\n2- Pesquisar produto.\n3- Alterar produto.\n4- Remover produto.\n5 - Sair");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Adicionar novo produto\n\n");

            novo = ler_produto();
            if(inserir(&ouro, novo) == SUCESSO)
                printf("O produto %s foi inserido com sucesso.\n", novo.nome);

            break;
        
        case 2:
            printf("Pesquisa de produto\n\n");        

            codigo_produto = ler_codigo();
            novo = pesquisar(&ouro, codigo_produto);
            imprimir_produto(novo);

            break;

        case 3:
            printf("Alterar produto\n\n");

            codigo_produto = ler_codigo();

            break;

        case 4:
            printf("Remover produto\n\n");

            chave codigo_produto = ler_codigo();
            if (remover(&ouro, codigo_produto) == SUCESSO)
                printf("Produto removido com sucesso.\n");

            break;
        
        default:
            printf("Insira uma opcao valida.\n");
            break;
        }

    } while(opcao != 5);

    return 0;
}