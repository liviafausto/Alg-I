#ifndef PILHA_H
    #define PILHA_H

        #define JA_EXISTE -3
        #define NAO_ENCONTROU -2
        #define ERRO_VAZIA -1
        #define ERRO_CHEIA 0
        #define SUCESSO 1

        typedef int chave;

        typedef struct elemento {
            chave codigo;
            char nome[50];
        } elemento;

        typedef struct no *apontador;

        typedef struct no {
            elemento item;
            apontador proximo;
        } no;

        typedef struct {
            apontador topo;
        } pilha;

        int criar(pilha *p);
        int vazia(pilha *p);
        int cheia(apontador item);

        int push(pilha *p, elemento item); //empilhar
        int pop(pilha *p); //desempilhar
        no topo(pilha *p);
        int contar(pilha *p);
        //inverte(pilha *p);

        void imprime(pilha *p);
        void menu(int *opcao);
        void ler_elemento(elemento *item);
        void libera(pilha *p);
#endif

/*
especialização de lista
inserções e remoções sao feitas no topo
last-in / first-out (LIFO)
*/