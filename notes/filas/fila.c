#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
        
int criar(fila *nova_fila){
    nova_fila->primeiro = NULL;
    nova_fila->ultimo = NULL;
}

int enfileirar(fila *fila, elemento item){
    apontador novo = (apontador) malloc(sizeof(no));

    if(novo == NULL){
        printf("Fila cheia.\n");
        return ERRO_CHEIA;
    }

    novo->item_fila = item;
    novo->proximo = NULL;

    if(vazia(fila)){
        fila->primeiro = novo;

    } else {
        fila->ultimo->proximo = novo;
    }

    fila->ultimo = novo;
    return SUCESSO;

}

int desenfileirar(fila *fila);
int item_inicio(fila *fila);

int vazia(fila *fila){

    if(fila->primeiro == NULL && fila->ultimo == NULL){
        return 1;
    } else {
        return 0;
    }
}

int contar(fila *fila);

void imprimir(fila *fila){

    if(vazia(fila)){
        printf("Fila vazia.\n");

    } else {
        printf("\nFILA:\n");
        apontador percorre_fila = fila->primeiro;

        while(percorre_fila != NULL){

            printf("%d - %s\n", percorre_fila->item_fila.num, percorre_fila->item_fila.nome);
            percorre_fila = percorre_fila->proximo;
        }
    }

}

void liberar_fila(fila *fila){

    if(vazia(fila)){
        return;
    }

    apontador libera_no = fila->primeiro;

    while(libera_no != NULL){

        fila->primeiro = fila->primeiro->proximo;
        free(libera_no);
        libera_no = fila->primeiro;
    }
}

int menu(int opcao){
    printf("\nO que voce deseja fazer?\n");
    printf("\n1 - Inserir pessoa na fila\n");
    //printf("2 - Tirar pessoa da fila\n");
    //printf("3 - Saber quem eh o primeiro da fila\n");
    //printf("4 - Saber quantas pessoas estao na fila\n");
    printf("5 - Imprimir toda a fila\n");
    printf("6 - Sair\n\n");

    scanf("%d", &opcao);
    return opcao;
}

elemento ler_item(elemento item){
    printf("\nNome: "); scanf("%s", item.nome);
    printf("Numero: "); scanf("%d", &item.num);
    return item;
}