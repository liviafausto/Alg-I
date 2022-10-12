#ifndef LISTA06_H
    #define LISTA06_H

        #define ERRO 0
        #define SUCESSO 1

        typedef int chave;
        typedef struct elemento{
            chave codigo;
            char paridade;
        } elemento;

        typedef struct no *apontador;
        typedef struct no{
            elemento item;
            apontador proximo;
        } no;

        typedef struct {
            apontador primeiro;
            apontador ultimo;
        } lista;

        void criar(lista *l);
        int vazia(lista *l);
        int inserir(lista *l, elemento item);
        int rearranjar(lista *l);
        void imprimir(lista *l);
        void liberar(lista *l);

#endif