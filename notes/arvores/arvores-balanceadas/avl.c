#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//A eficiência das operações numa ABB depende da profundidade dos nós folha
//Tal profundidade depende do seu balanceamento
//AVL: nome vem dos seus criadores - Adelson-Velsky e Landis

static int max(int a, int b);
static void rotacao_esquerda(arvore *avl);


int retornar_altura(arvore *avl){
    if((*avl) == NULL){
        return -1;
    } else {
        return (*avl)->altura;
    }
}

int checar_fatorBalanceamento(arvore *avl){
    if((*avl) == NULL){
        return 0;
    } else {
        int Fb;
        Fb = retornar_altura(&(*avl)->esq) - retornar_altura(&(*avl)->dir);
        return Fb;
    }
}

int criar(arvore *avl){
    //ideal seria limpar caso houvesse algo
    *avl = NULL;
}

int vazia(arvore *avl){
    if(*avl == NULL){
        return 1;
    } else {
        return 0;
    }
}

int static criar_raiz(arvore *avl, elemento folha){
    *avl = (arvore)malloc(sizeof(no));
    if(*avl == NULL){
        return ERRO_CHEIA;
    }

    (*avl)->esq = NULL;
    (*avl)->dir = NULL;
    (*avl)->folha = folha;

    return SUCESSO;
}

int inserir(arvore *avl, elemento folha){
    if(*avl == NULL){
        return criar_raiz(avl, folha);
    }

    //considerar se os nomes são iguais
    if(strcmp(folha.nome, (*avl)->folha.nome) == 0){
        return JA_EXISTE;
    }

    
}

elemento pesquisar(arvore *avl, chave nome);

int remover(arvore *avl, chave nome);

void imprimir(arvore *abb){

}

void in_order(arvore *abb){

}

static int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

static void rotacao_esquerda(arvore *avl){
    apontador aux, B;

    // filho à esquerda da raiz
    aux = (*avl)->esq;

    // filho à esquerda à direita da raiz
    B = aux->dir;

    //a sub-arv muda de pai pela antiga raiz
    (*avl)->esq = B;
    //aux passa a ser a raiz
    aux = (*avl);

    (*avl)->altura = max(retornar_altura(&(*avl)->esq), retornar_altura(&(*avl)->dir + 1));
}