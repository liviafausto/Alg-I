#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int criar(arvore *abb){
    *abb = NULL;
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
        printf("Nao foi possivel encontrar essa folha.\n");
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

        apontador troca_folha = *subarvore;

        *subarvore = (*subarvore)->esquerda;

        free(troca_folha);
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
        free(abb);
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