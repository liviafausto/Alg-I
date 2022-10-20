#include "arvore.h"
#include <stdio.h>

int criar(arvore *arvore){
    arvore->raiz = NULL;
}

int static criar_raiz(arvore *arvore, elemento folha){

    apontador novo = (apontador) malloc(sizeof(no));
    if(novo == NULL){
        return ERRO_CHEIA;
    }

    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->folha = folha;

    arvore->raiz = novo;
    
    return SUCESSO;
}

int inserir(arvore *arvore, elemento nova_folha){

    //caso a arvore esteja vazia
    if(arvore->raiz == NULL){
        return criar_raiz(arvore, nova_folha);
    }

    //caso o codigo da raiz seja igual ao novo codigo
    if(arvore->raiz->folha.codigo == nova_folha.codigo){
        return JA_EXISTE;
    }



    return SUCESSO;
}

elemento pesquisar(arvore *arvore, chave codigo){
    apontador posicao;

    //menor vai para a esquerda e maior vai para a direita
    if(arvore->raiz->folha.codigo > codigo){
        posicao = pesquisar_esquerda(arvore, codigo);
    }

    if(arvore->raiz->folha.codigo < codigo){
        posicao = pesquisar_direita(arvore, codigo);
    }

}

apontador pesquisar_direita(arvore *arvore, chave codigo);
apontador pesquisar_esquerda(arvore *arvore, chave codigo);