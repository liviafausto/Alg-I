#ifndef ARVORE_H
    #define ARVORE_H

        #define JA_EXISTE -3
        #define NAO_ENCONTROU -2
        #define ERRO_VAZIA -1
        #define ERRO_CHEIA 0
        #define SUCESSO 1

        typedef int chave;

        typedef struct elemento{
            chave codigo;
            char nome[50];
        } elemento;

        typedef struct no *apontador;
        typedef struct no{
            elemento folha;
            apontador esquerda;
            apontador direita;
        } no;

        typedef struct{
            apontador raiz;
        } arvore;

        int criar(arvore *arvore);
        int inserir(arvore *arvore, elemento nova_folha);
        apontador pesquisar_direita(arvore *arvore, chave codigo);
        apontador pesquisar_esquerda(arvore *arvore, chave codigo);

#endif