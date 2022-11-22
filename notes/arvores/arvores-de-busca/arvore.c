#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

//abb = Árvore Binária de Busca

int criar(arvore *abb){
    *abb = NULL;
}

int vazia(arvore *abb){
    if(*abb == NULL){
        return 1;
    } else {
        return 0;
    }
}

int static criar_raiz(arvore *abb, elemento folha){
    *abb = (arvore) malloc(sizeof(no));
    if(*abb == NULL){
        return ERRO_CHEIA;
    }

    (*abb)->esquerda = NULL;
    (*abb)->direita = NULL;
    (*abb)->folha = folha;

    return SUCESSO;
}

int inserir(arvore *abb, elemento nova_folha){
    if(*abb == NULL){
        return criar_raiz(abb, nova_folha); 
    }

    //considerar chaves primárias
    if (nova_folha.codigo == (*abb)->folha.codigo){
        return JA_EXISTE;
    }

    if(nova_folha.codigo < (*abb)->folha.codigo){
        return inserir(&(*abb)->esquerda, nova_folha);
    } else {
        return inserir(&(*abb)->direita, nova_folha);
    }

}

elemento pesquisar(arvore *abb, chave codigo){
    if(*abb == NULL){
        elemento e;
        e.codigo = NAO_ENCONTROU;
        return e;
    }

    if(codigo  == (*abb)->folha.codigo){
        printf("A folha foi encontrada.\n");
        return (*abb)->folha;
    }

    if(codigo < (*abb)->folha.codigo){
        return pesquisar(&(*abb)->esquerda, codigo);
    } else {
        return pesquisar(&(*abb)->direita, codigo);
    }

}

static void buscaMaiorEsquerda(arvore *raiz, arvore *subarvore){

    if((*subarvore)->direita == NULL){

        (*raiz)->folha = (*subarvore)->folha;

        apontador remove_folha = *subarvore;

        *subarvore = (*subarvore)->esquerda;

        free(remove_folha);
    }
    else {
        buscaMaiorEsquerda(raiz, &(*subarvore)->direita);
    }
}

int remover(arvore *abb, chave codigo){
    if(*abb == NULL){
        return NAO_ENCONTROU;
    }

    //busca: direita ou esquerda
    if(codigo > (*abb)->folha.codigo){
        return remover(&(*abb)->direita, codigo);
    } 
    else if(codigo < (*abb)->folha.codigo){
        return remover(&(*abb)->esquerda, codigo);
    }

    //se passou, é porque achou a chave
    apontador remove_folha = *abb;

    if((*abb)->esquerda == NULL && (*abb)->direita == NULL){ //caso 1: não há folhas na direita ou esquerda
        *abb = NULL;
        free(remove_folha);
    } 
    else if((*abb)->esquerda == NULL){ //caso 2: há uma folha na direita
        *abb = (*abb)->direita;
        free(remove_folha);
    }
    else if((*abb)->direita == NULL){ //caso 3: há uma folha na esquerda
        *abb = ((*abb)->esquerda);
        free(remove_folha);
    }
    else{ //caso 4: há folhas nas duas direções
        buscaMaiorEsquerda(abb, &(*abb)->esquerda);
    }

    return SUCESSO;
    
}

void visita(arvore *abb){
    //visitar pode significar qualquer tipo de operação feita no nó
    printf("%d ", (*abb)->folha.codigo);
}

void pre_order(arvore *abb){
    //visita o nó antes de acessar qualquer um de seus filhos
    if(*abb != NULL){
        visita(abb);
        pre_order(&(*abb)->esquerda);
        pre_order(&(*abb)->direita);
    }
}

void in_order(arvore *abb){
    //visita o nó entre o acesso a cada um de seus dois filhos
    if(*abb != NULL){
        in_order(&(*abb)->esquerda);
        visita(abb);
        in_order(&(*abb)->direita);
    }
}

void pos_order(arvore *abb){
    //visita o nó somente depois de acessar seus filhos
    if(*abb != NULL){
        pos_order(&(*abb)->esquerda);
        pos_order(&(*abb)->direita);
        visita(abb);
    }
}