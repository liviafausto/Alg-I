#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int criar(arvore *arvore){
    arvore->raiz = NULL;
}

int vazia(arvore *arvore){
    if(arvore->raiz == NULL){
        return 1;
    } else {
        return 0;
    }
}

apontador static criar_folha(arvore *arvore, elemento folha){

    apontador novo = (apontador) malloc(sizeof(no));
    if(novo == NULL){
        printf("Nao ha memoria disponivel para criar uma nova folha\n");
        return NULL;
    }

    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->folha = folha; printf("folha adicionada: %d\n", novo->folha.codigo);
    return novo;

}

int inserir(arvore *arvore, elemento nova_folha){

    if(pesquisar(arvore, nova_folha.codigo) != NULL){
        printf("Ja existe uma folha com esse codigo\n");
        return JA_EXISTE;
    }

    apontador novo = criar_folha(arvore, nova_folha);
    if(novo == NULL){
        return ERRO_CHEIA;
    }

    if(vazia(arvore)){
        arvore->raiz = novo;
        printf("Raiz da arvore criada: %d\n", arvore->raiz->folha.codigo);
        return SUCESSO;
    }

    apontador inserir_pos = arvore->raiz;

    while(inserir_pos != NULL){

        if(novo->folha.codigo < inserir_pos->folha.codigo){

            if(inserir_pos->esquerda == NULL){
                inserir_pos->esquerda = novo; 
                printf("FOLHA: %d <- %d\n", inserir_pos->esquerda->folha.codigo, inserir_pos->folha.codigo);
                break;
            } else {
                inserir_pos = inserir_pos->esquerda;
            }
        }
        else if(novo->folha.codigo > inserir_pos->folha.codigo){

            if(inserir_pos->direita == NULL){
                inserir_pos->direita = novo;
                printf("FOLHA: %d -> %d\n", inserir_pos->folha.codigo, inserir_pos->direita->folha.codigo);
                break;
            } else {
                inserir_pos = inserir_pos->direita;
            }
        }

    }
    
    return SUCESSO;
}

apontador pesquisar(arvore *arvore, chave codigo){
    apontador posicao = arvore->raiz;

    while(posicao != NULL){

        if(codigo == posicao->folha.codigo){
            return posicao;
        }

        if(codigo < posicao->folha.codigo){
            //codigo eh menor, vai para a esquerda
            posicao = posicao->esquerda;
        }
        else if(codigo > posicao->folha.codigo){
            //codigo eh maior, vai para a direita
            posicao = posicao->direita;
        }
    }

    return posicao;
}