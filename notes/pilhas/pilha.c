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

static int pesquisa_codigo(pilha *p, chave codigo){
    apontador pesquisa = p->topo;

    while(pesquisa != NULL){
        if(pesquisa->item.codigo == codigo){
            return 1;
        }
        pesquisa = pesquisa->proximo;
    }

    return 0;
}

int push(pilha *p, elemento item){
    apontador novo = (apontador) malloc(sizeof(no));

    if(cheia(novo)){
        printf("Pilha cheia.\n");
        return ERRO_CHEIA;
    }
    
    if(pesquisa_codigo(p, item.codigo)){
        printf("Ja existe um item com esse codigo.\n");
        return JA_EXISTE;
    }

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

    if(p->topo->proximo == NULL){
        free(remover);
        criar(p);
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

void imprime(pilha *p){
    if(vazia(p)){
        printf("Pilha vazia.\n");
        return;
    }

    apontador imprime = p->topo;

    printf("\nHistorico de Navegacao:\n");
    while(imprime != NULL){
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
    printf("6 - Inverter historico\n");
    printf("7 - Sair.\n\n");

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