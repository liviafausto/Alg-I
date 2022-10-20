#include "ex03.h"
#include <stdio.h>
#include <stdlib.h>

static int numero_nos;

int criar_pilha(pilha *p){
    p->topo = NULL;
    numero_nos = 0;
}

int pilha_vazia(pilha *p){
    if(p->topo == NULL){
        return 1;
    } else {
        return 0;
    }
}

int pilha_cheia(apontador item){
    if(item == NULL){
        return 1;
    } else {
        return 0;
    }
}

static int pesquisa_codigo(pilha *p, chave num){
    apontador pesquisa = p->topo;

    while(pesquisa != NULL){
        if(pesquisa->item.num == num){
            return 1;
        }
        pesquisa = pesquisa->proximo;
    }

    return 0;
}

int push(pilha *p, elemento item){
    apontador novo = (apontador) malloc(sizeof(no));

    if(pilha_cheia(novo)){
        printf("Pilha cheia.\n");
        return ERRO_CHEIA;
    }
    
    if(pesquisa_codigo(p, item.num)){
        printf("Ja existe um item com esse num.\n");
        return JA_EXISTE;
    }

    novo->item = item;

    novo->proximo = p->topo;
    p->topo = novo;

    numero_nos++;
    return SUCESSO;
}

int pop(pilha *p){
    if(fila_vazia(p)){
        printf("Pilha vazia.\n");
        return ERRO_VAZIA;
    }

    apontador remover = p->topo;

    if(p->topo->proximo == NULL){
        free(remover);
        criar_pilha(p);
    } else {
        p->topo = p->topo->proximo;
        free(remover);
        numero_nos--;
    }

    return SUCESSO;
}

no topo(pilha *p){
    return *p->topo;
}

int contar(pilha *p){
    return numero_nos;
}

pilha inverte(pilha *p){
    pilha invertida; criar(&invertida);
    apontador copia = p->topo;

    while(copia != NULL){
        push(&invertida, copia->item);
        copia = copia->proximo;
    }

    return invertida;
}

void imprimir_pilha(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");
        return;
    }

    apontador imprime = p->topo;

    printf("\nHistorico de Navegacao:\n");
    while(imprime != NULL){
        printf("%d \n", imprime->item.num);
        imprime = imprime->proximo;
    }
}

void liberar_pilha(pilha *p){
    apontador libera_no = p->topo;

    while(libera_no != NULL){
        p->topo = p->topo->proximo;
        free(libera_no);
        libera_no = p->topo;
    }
}