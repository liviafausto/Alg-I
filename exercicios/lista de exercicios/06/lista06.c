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
    //considerando o primeiro elemento impar
    apontador num_impar = l->primeiro;
    apontador anterior = l->primeiro;
    apontador parar = l->ultimo;

    l->primeiro = l->primeiro->proximo; //primeiro aponta para par

    while(anterior != parar){
        l->ultimo->proximo = num_impar; //liga o final com o impar
        anterior->proximo = num_impar->proximo; //liga o par com o proximo par

        l->ultimo = num_impar; //ultimo aponta para impar
        anterior = num_impar->proximo; //anterior aponta para par antes do proximo impar
        num_impar = num_impar->proximo->proximo; //impar aponta para proximo impar

        l->ultimo->proximo = NULL; //o impar que esta no fim da lista aponta para NULL
    }

}

void imprimir(lista *l){
    if(!vazia(l)){
        apontador imprime = l->primeiro;
        printf("LISTA: ");

        while(imprime != NULL){
            printf("%d ", imprime->item.codigo);
            imprime = imprime->proximo;
        }
        printf("\n");
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