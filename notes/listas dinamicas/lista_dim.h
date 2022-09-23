#ifndef LISTA_DIM
    #define LISTA_DIM

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
            apontador head;
            apontador ultimo;
        } lista;

        int criar(lista *lista);
        int vazia(lista *lista);
        int inserir(lista *lista, elemento item);
        int remover(lista *lista, chave codigo_item);
        int pesquisar(lista *lista, elemento pesquisar_item);
        int alterar(lista *lista, elemento novo_elemento);
        int cheia(lista *lista);

        void imprimir(lista *lista);
        void imprimir_elemento(elemento item);

        apontador pesquisa_posicao(lista *lista, chave codigo_item);
        elemento ler_novo_item(lista *lista, elemento novo_item);
        chave ler_chave(chave codigo_item);

#endif