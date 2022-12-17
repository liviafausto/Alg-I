#ifndef AVL_H
    #define AVL_H

        #define JA_EXISTE -3
        #define NAO_ENCONTROU -2
        #define ERRO_VAZIA -1
        #define ERRO_CHEIA 0
        #define SUCESSO 1

        typedef int chave;

        typedef struct {
            chave codigo;
        } elemento;

        typedef struct no *apontador;
        typedef struct no {
            elemento folha;
            apontador esq;
            apontador dir;
            int altura;
        } no;

        typedef apontador arvore;

        int criar(arvore *avl);
        int vazia(arvore *avl);
        int inserir(arvore *avl, elemento folha);
        elemento pesquisar(arvore *avl, chave nome);
        int remover(arvore *avl, chave nome);
        void imprimir(arvore *avl);
        void apagar(arvore *avl);

        int retornar_altura(arvore *avl);
        int fatorBalanceamento(arvore *avl);

#endif