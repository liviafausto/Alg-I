#include "avl.h"
#include <stdio.h>

//A eficiência das operações numa ABB depende da profundidade dos nós folha
//Tal profundidade depende do seu balanceamento

//AVL: nome vem dos seus criadores - Adelson-Velsky e Landis

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