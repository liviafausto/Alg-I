#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

static int numero_nos;

int criar(pilha *p){
    p->topo = NULL;
    numero_nos = 0;
}

int vazia(pilha *p){
    if(p->topo == NULL){
        return 1;
    } else {
        return 0;
    }
}

int cheia(apontador item){
    if(item == NULL){
        return 1;
    } else {
        return 0;
    }
}

int push(pilha *p, elemento item){
    apontador novo = (apontador) malloc(sizeof(no));

    if(cheia(novo)){
        printf("Pilha cheia.\n");
        return ERRO_CHEIA;
    }

    novo->item = item;

    novo->proximo = p->topo;
    p->topo = novo;

    numero_nos++;
    return SUCESSO;
}

int pop(pilha *p);
no topo(pilha *p);

int contar(pilha *p){
    return numero_nos;
}
//inverte(pilha *p);

void imprime(pilha *p);