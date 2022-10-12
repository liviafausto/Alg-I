#include "lista06.h"
#include <stdio.h>
#include <stdlib.h>

void criar(lista *l){
    l->primeiro = NULL;
    l->ultimo = NULL;
}

int vazia(lista *l){
    if(l->primeiro == NULL && l->ultimo == NULL){
        return 1;
    } else {
        return 0;
    }
}

int inserir(lista *l, elemento item){
    apontador novo = (apontador)malloc(sizeof(no));

    if(novo == NULL){
        return ERRO;
    }

    novo->item = item;
    novo->proximo = NULL;

    if(vazia(l)){
        l->primeiro = novo;
        l->ultimo = novo;
    } else {
        l->ultimo->proximo = novo;
        l->ultimo = novo;
    }

}

int rearranjar(lista *l){

}

void imprimir(lista *l){
    if(!vazia(l)){
        apontador imprime = l->primeiro;
        printf("LISTA: ");

        while(imprime != NULL){
            printf("%d ", imprime->item.codigo);
            imprime = imprime->proximo;
        }
    }
}

void liberar(lista *l){
    if(!vazia(l)){
        apontador libera_no = l->primeiro;

        while(libera_no != NULL){
            l->primeiro = l->primeiro->proximo;
            free(libera_no);
            libera_no = l->primeiro;
        }

    }
}