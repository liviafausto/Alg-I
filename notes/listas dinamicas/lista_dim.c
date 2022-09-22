#include "lista_dim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criar(lista *lista){
    lista->head = NULL;
    lista->ultimo = NULL;
}

int vazia(lista *lista){

    if(lista->head == NULL)
        return 1;
    else 
        return 0;
}

int cheia(lista *lista){

}

elemento ler_novo_item(lista *lista, elemento novo_item){
    
    printf("\nInsira os dados do novo item que deseja inserir.\n\n");
    printf("CODIGO: "); scanf("%d", &novo_item.codigo);
    printf("NOME: "); scanf("%s", novo_item.nome);

    return novo_item;

}

int inserir(lista *lista, elemento novo_item){

    apontador novo = (apontador) malloc (sizeof(no));
    if(novo == NULL){
        printf("Lista cheia.\n");
        return ERRO_CHEIA;
    }

    novo->proximo = NULL;
    novo->item = novo_item;

    if(vazia(lista)){
        lista->head = novo;
        lista->ultimo = novo;

    } else {
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
    }

    printf("O elemento %s de chave %d foi inserido com sucesso.", novo->item.nome, novo->item.nome);
    return SUCESSO;
}

int remover(lista *lista, chave chave);
elemento pesquisar(lista *lista, chave chave);
int alterar(lista *lista, elemento novo_elemento);
void imprimir(lista *lista);

void imprimir_elemento(elemento item){
    printf("\nCODIGO: %d\n", item.codigo);
    printf("NOME: %s\n", item.nome);
}