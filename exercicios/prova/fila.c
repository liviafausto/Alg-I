#include "ex03.h"
#include <stdio.h>
#include <stdlib.h>
        
int criar_fila(fila *nova_fila){
    nova_fila->primeiro = NULL;
    nova_fila->ultimo = NULL;
}

int enfileirar(fila *fila, elemento item){
    apontador novo = (apontador) malloc(sizeof(no));

    if(novo == NULL){
        printf("Fila cheia.\n");
        return ERRO_CHEIA;
    }

    novo->item = item;
    novo->proximo = NULL;

    if(fila_vazia(fila)){
        fila->primeiro = novo;

    } else {
        fila->ultimo->proximo = novo;
    }

    fila->ultimo = novo;
    return SUCESSO;

}

int desenfileirar(fila *fila){

    if(fila_vazia(fila)){
        printf("Fila vazia.\n");
        return ERRO_VAZIA;
    }

    apontador remover = fila->primeiro;

    if(remover == fila->ultimo){
        free(remover);
        criar_fila(fila);
        return SUCESSO;
    }

    fila->primeiro = fila->primeiro->proximo;
    free(remover);
    return SUCESSO;
}

elemento item_inicio(fila *fila){

    return fila->primeiro->item;

}

int fila_vazia(fila *fila){

    if(fila->primeiro == NULL && fila->ultimo == NULL){
        return 1;
    } else {
        return 0;
    }
}

int contar_fila(fila *fila){

    if(fila_vazia(fila)){
        printf("Fila vazia.\n");
        return ERRO_VAZIA;
    }

    apontador percorre = fila->primeiro; int contador=0;

    while(percorre != NULL){
        contador++;
        percorre = percorre->proximo;
    }

    return contador;
}

void imprimir_fila(fila *fila){

    if(fila_vazia(fila)){
        printf("Fila vazia.\n");

    } else {
        printf("\nFILA:\n");
        apontador percorre_fila = fila->primeiro;

        while(percorre_fila != NULL){

            printf("%d \n", percorre_fila->item.num);
            percorre_fila = percorre_fila->proximo;
        }
    }

}

void liberar_fila(fila *fila){

    if(fila_vazia(fila)){
        return;
    }

    apontador libera_no = fila->primeiro;

    while(libera_no != NULL){

        fila->primeiro = fila->primeiro->proximo;
        free(libera_no);
        libera_no = fila->primeiro;
    }
}