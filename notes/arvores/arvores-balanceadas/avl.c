#include "avl.h"
#include <stdio.h>

//A eficiência das operações numa ABB depende da profundidade dos nós folha
//Tal profundidade depende do seu balanceamento

//AVL: nome vem dos seus criadores - Adelson-Velsky e Landis

static int max(int a, int b);
static void rotacao_esquerda(arvore *avl);

int criar(arvore *avl){
    //ideal seria limpar caso houvesse algo
    *avl = NULL;
}

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

int inserir(arvore *avl, elemento folha);
elemento pesquisar(arvore *avl, chave codigo);
int remover(arvore *avl, chave codigo);

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