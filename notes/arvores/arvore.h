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
        } elemento;

        typedef struct no *apontador;
        typedef struct no{
            elemento folha;
            apontador esquerda;
            apontador direita;
        } no;

        typedef apontador arvore;

        int criar(arvore *abb);
        int vazia(arvore *abb);
        int inserir(arvore *abb, elemento nova_folha);
        elemento pesquisar(arvore *abb, chave codigo);
        int remover(arvore *abb, chave codigo);
        void visita(arvore *abb);
        void pre_order(arvore *abb);
        void in_order(arvore *abb);
        void pos_order(arvore *abb);

#endif