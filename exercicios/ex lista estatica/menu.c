#include "produtos.h"
#include <stdio.h>
#include <string.h>

produto ler_produto(){
    produto novo;

    printf("Codigo: "); scanf("%d", &novo.codigo);
    printf("Nome: "); scanf("%s", novo.nome);
    printf("Quantidade: "); scanf("%d", &novo.quantidade);
    printf("Peso: "); scanf("%lf", &novo.peso);

    return novo;
}

chave ler_codigo(){
    chave codigo_produto;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo_produto);

    return codigo_produto;
}

void imprimir_lista(lista *l){
    if(!vazia(l)){
        printf("\n");
        for(int i=0; i <= l->ultimo; i++){
            printf("Codigo: %d\n", l->pecas[i].codigo);
            printf("Nome do produto: %s\n", l->pecas[i].nome);
            printf("Quantidade: %d\n", l->pecas[i].quantidade);
            printf("Peso: %.2fg\n", l->pecas[i].peso); printf("\n");
        }

    } else {
        printf("A lista esta vazia.\n");
    }
}

void imprimir_produto(produto pesquisado){
    printf("\n[%d] %s\n", pesquisado.codigo, pesquisado.nome);
    printf("Qtde = %d  Peso = %.2lfg\n", pesquisado.quantidade, pesquisado.peso);
}

produto escolher(produto antigo){
    int opcao; produto aux;

    printf("\nO que voce deseja alterar?\n\n");
    printf("1- Trocar codigo do produto\n"); 
    printf("2- Trocar nome do produto\n");
    printf("3- Trocar quantidade do produto\n"); 
    printf("4- Trocar peso do produto\n\n");

    scanf("%d", &opcao);

    switch (opcao){
    case 1:
        printf("Digite o novo codigo do produto: "); 
        scanf("%d", &aux.codigo);

        antigo = copy(antigo, aux, opcao);
        break;
    
    case 2:
        printf("Digite o novo nome do produto: "); 
        scanf("%s", aux.nome);

        antigo = copy(antigo, aux, opcao);
        break;

    case 3:
        printf("Digite a nova quantidade do produto: "); 
        scanf("%d", &aux.quantidade);

        antigo = copy(antigo, aux, opcao);
        break;

    case 4:
        printf("Digite o novo peso do produto: "); 
        scanf("%lf", &aux.peso);

        antigo = copy(antigo, aux, opcao);
        break;
    
    default:
        printf("Insira uma opcao valida para continuar.\n");
        break;
    }

    return antigo;

}

produto copy(produto antigo, produto modificado, int escolha){

    if(escolha == 1){
        strcpy(modificado.nome, antigo.nome);
        modificado.quantidade = antigo.quantidade;
        modificado.peso = antigo.peso;

    } else if(escolha == 2){
        modificado.codigo = antigo.codigo;
        modificado.quantidade = antigo.quantidade;
        modificado.peso = antigo.peso;

    } else if(escolha == 3){
        modificado.codigo = antigo.codigo;
        strcpy(modificado.nome, antigo.nome);
        modificado.peso = antigo.peso;

    } else if(escolha == 4){
        modificado.codigo = antigo.codigo;
        strcpy(modificado.nome, antigo.nome);
        modificado.quantidade = antigo.quantidade;
    }

    return modificado;
}