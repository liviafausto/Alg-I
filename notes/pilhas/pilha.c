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

void menu(int *opcao){
    printf("\nO que voce deseja fazer?\n");
    printf("1 - Adicionar pagina no historico\n");
    printf("2 - Remover pagina do historico\n");
    printf("3 - Saber qual a ultima pagina pesquisada\n");
    printf("4 - Saber quantas paginas estao no historico\n");
    printf("5 - Ver historico completo\n");
    printf("6 - Sair.\n");

    scanf("%d", opcao);
}