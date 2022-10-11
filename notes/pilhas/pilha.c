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
    //if (item.codigo ja existe)

    novo->item = item;

    novo->proximo = p->topo;
    p->topo = novo;

    numero_nos++;
    return SUCESSO;
}

int pop(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");
        return ERRO_VAZIA;
    }

    apontador remover = p->topo;
    p->topo = p->topo->proximo;

    free(remover);
    numero_nos--;

    return SUCESSO;
}

no topo(pilha *p){
    return *p->topo;
}

int contar(pilha *p){
    return numero_nos;
}
//inverte(pilha *p);

void imprime(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");
    }

    apontador imprime = p->topo;

    while(imprime != NULL){
        printf("\nHistorico de Navegacao:\n");
        printf("%d - %s\n", imprime->item.codigo, imprime->item.nome);
        imprime = imprime->proximo;
    }
}

void menu(int *opcao){
    printf("\nO que voce deseja fazer?\n");
    printf("\n1 - Adicionar pagina no historico\n");
    printf("2 - Remover pagina do historico\n");
    printf("3 - Saber qual a ultima pagina pesquisada\n");
    printf("4 - Saber quantas paginas estao no historico\n");
    printf("5 - Ver historico completo\n");
    printf("6 - Sair.\n\n");

    scanf("%d", opcao);
}

void ler_elemento(elemento *item){
    printf("\nCODIGO: "); scanf("%d", &item->codigo);
    printf("NOME: "); scanf("%s", item->nome);
}

void libera(pilha *p){
    apontador libera_no = p->topo;

    while(libera_no != NULL){
        p->topo = p->topo->proximo;
        free(libera_no);
        libera_no = p->topo;
    }
}