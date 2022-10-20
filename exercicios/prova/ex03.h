#ifndef EX03_H
    #define EX03_H

        #define JA_EXISTE -3
        #define NAO_ENCONTROU -2
        #define ERRO_VAZIA -1
        #define ERRO_CHEIA 0
        #define SUCESSO 1

        typedef int chave;

        typedef struct elemento {
            chave num;
        } elemento;

        typedef struct no *apontador;

        typedef struct no {
            apontador proximo;
            elemento item;
        } no;

        typedef struct {
            apontador primeiro;
            apontador ultimo;
        } fila;

        typedef struct {
            apontador topo;
        } pilha;

        int criar_fila(fila *nova_fila);
        int enfileirar(fila *fila, elemento item);
        int desenfileirar(fila *fila);
        elemento item_inicio(fila *fila);
        int fila_vazia(fila *fila);
        int contar_fila(fila *fila);
        void imprimir_fila(fila *fila);
        void liberar_fila(fila *fila);

        int criar_pilha(pilha *p);
        int pilha_vazia(pilha *p);
        int pilha_cheia(apontador item);
        int push(pilha *p, elemento item);
        int pop(pilha *p);
        no topo(pilha *p);
        pilha inverte(pilha *p);
        void imprimir_pilha(pilha *p);
        void liberar_pilha(pilha *p);
        static int pesquisa_codigo(pilha *p, chave codigo);

#endif