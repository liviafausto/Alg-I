#ifndef LISTA_DIM
    #define LISTA_DIM

        #define JA_EXISTE -2
        #define NAO_ENCONTROU -1
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
            apontador head;
            apontador ultimo;
        } lista;

        int criar(lista *lista);
        int inserir(lista *lista, elemento item);
        int remover(lista *lista, chave chave);
        elemento pesquisar(lista *lista, chave chave);
        int alterar(lista *lista, elemento novo_elemento);
        int vazia(lista *lista);
        int cheia(lista *lista);
        void imprimir(lista *lista);

        elemento ler_novo_item(lista *lista, elemento novo_item);
        void imprimir_elemento(elemento item);

#endif