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