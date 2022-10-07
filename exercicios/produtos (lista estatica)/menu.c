#include "produtos.h"
#include <stdio.h>
#include <string.h>

int menu(){
    int opcao;

    printf("\nO que voce deseja fazer?\n");
    printf("\n1 - Adicionar novo produto\n");
    printf("2 - Pesquisar produto\n");
    printf("3 - Alterar produto\n");
    printf("4 - Remover produto\n");
    printf("5 - Imprimir lista\n");
    printf("6 - Sair\n\n");

    scanf("%d", &opcao);

    return opcao;
}

produto ler_produto(){
    produto novo;

    printf("\nCodigo: "); scanf("%d", &novo.codigo);
    printf("Nome: "); scanf("%s", novo.nome);
    printf("Quantidade: "); scanf("%d", &novo.quantidade);
    printf("Peso: "); scanf("%lf", &novo.peso);

    return novo;
}

chave ler_codigo(){
    chave codigo_produto;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo_produto);

    return codigo_produto;
}

void imprimir_lista(lista *l){
    if(vazia(l)){
        printf("Lista vazia\n");
    } else {

        for(int i=0; i <= l->ultimo; i++){
            printf("\n[%d] %s\n", l->pecas[i].codigo, l->pecas[i].nome);
            printf("Qtde = %d | Peso: %.2fg\n", l->pecas[i].quantidade, l->pecas[i].peso);
        }
    }
}

void imprimir_produto(produto pesquisado){
    printf("\n[%d] %s\n", pesquisado.codigo, pesquisado.nome);
    printf("Qtde = %d | Peso = %.2lfg\n", pesquisado.quantidade, pesquisado.peso);
}