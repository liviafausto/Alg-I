#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

//A eficiência das operações numa ABB depende da profundidade dos nós folha
//Tal profundidade depende do seu balanceamento

static int max(int a, int b);
static void rotacao_esquerda(arvore *avl);
static void rotacao_direita(arvore *avl);

int vazia(arvore *avl){
    if(*avl == NULL){
        return 1;
    } else {
        return 0;
    }
}

int criar(arvore *avl){
    apagar(avl);
    *avl = NULL;
}

int static criar_raiz(arvore *avl, elemento folha){
    *avl = (arvore)malloc(sizeof(no));
    if(*avl == NULL){
        return ERRO_CHEIA;
    }

    (*avl)->esq = NULL;
    (*avl)->dir = NULL;
    (*avl)->folha = folha;
    (*avl)->altura = 0;

    return SUCESSO;
}

int inserir(arvore *avl, elemento folha){
    if(*avl == NULL){
        return criar_raiz(avl, folha);
    }

    if(folha.codigo == (*avl)->folha.codigo){
        return JA_EXISTE;
    }

    if(folha.codigo < (*avl)->folha.codigo){
        inserir(&(*avl)->esq, folha);
        (*avl)->altura = max((*avl)->altura, retornar_altura(&(*avl)->esq + 1));
    } else {
        return inserir(&(*avl)->dir, folha);
        (*avl)->altura = max((*avl)->altura, retornar_altura(&(*avl)->dir + 1));
    }

    int Fb = fatorBalanceamento(avl);
    if(Fb > 1){
        
    }
    
}

elemento pesquisar(arvore *avl, chave nome);

int remover(arvore *avl, chave nome);

void imprimir(arvore *avl){
    if((*avl) != NULL){
        printf("%d ", (*avl)->folha.codigo);
        imprimir(&(*avl)->esq);
        imprimir(&(*avl)->dir);
    }
}

void apagar(arvore *avl){
    if((*avl) != NULL){
        apagar(&(*avl)->esq);
        apagar(&(*avl)->dir);
        free(avl);
    }
}

int retornar_altura(arvore *avl){
    if((*avl) == NULL){
        return -1;
    } else {
        return (*avl)->altura;
    }
}

int fatorBalanceamento(arvore *avl){
    if((*avl) == NULL){
        return 0;
    } else {
        int Fb;
        Fb = retornar_altura(&(*avl)->esq) - retornar_altura(&(*avl)->dir);
        return Fb;
    }
}

//----------------------------------------------

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