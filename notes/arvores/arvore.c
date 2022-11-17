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

int remover(arvore *abb, chave codigo){
    if(*abb == NULL){
        return NAO_ENCONTROU;
    }

    //busca: direita ou esquerda
    if(codigo > (*abb)->folha.codigo){
        return remover(&(*abb)->direita, codigo);
    } else if(codigo < (*abb)->folha.codigo){
        return remover(&(*abb)->esquerda, codigo);
    }

    apontador remove_folha = *abb;
    //se passou, é porque achou a chave

    if((*abb)->esquerda == NULL && (*abb)->direita == NULL){ 
        //caso 1: folha
        *abb = NULL;
        free(abb);
    } else if((*abb)->esquerda == NULL){
        //caso 2: direita
        *abb = (*abb)->direita;
        free(abb);
    }
    
}

void imprimir_arvore(arvore *abb){
    //nao da para percorrer em apenas uma passagem
    //depende do tamanho da arvore e da quantidade de niveis
}