#ifndef FILA_H
    #define FILA_H

        #define JA_EXISTE -3
        #define NAO_ENCONTROU -2
        #define ERRO_VAZIA -1
        #define ERRO_CHEIA 0
        #define SUCESSO 1

        typedef int chave;

        typedef struct elemento {
            chave num;
            char nome[50];
        } elemento;

        typedef struct no *apontador;

        typedef struct no {
            apontador proximo;
            elemento item_fila;
        } no;

        typedef struct {
            apontador primeiro;
            apontador ultimo;
        } fila;

        int criar(fila *nova_fila);
        int enfileirar(fila *fila, elemento item);
        int desenfileirar(fila *fila);
        int item_inicio(fila *fila);
        int vazia(fila *fila);
        int contar(fila *fila);
        void imprimir(fila *fila);
        void liberar_fila(fila *fila);

        int menu(int opcao);
        elemento ler_item(elemento item);

#endif