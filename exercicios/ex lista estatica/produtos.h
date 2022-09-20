#ifndef PRODUTOS_H
    #define PRODUTOS_H

        #define TAM_MAX 50

        #define SUCESSO 1
        #define LISTA_CHEIA 0
        #define ERRO -2

        typedef int chave;
        typedef int marcador;

        typedef struct {
            chave codigo;
            char nome[100];
            int quantidade;
            double peso;
        } produto;

        typedef struct {
            produto pecas[TAM_MAX];
            marcador ultimo;
        } lista;

        int criar(lista *l);
        int vazia(lista *l);
        int cheia(lista *l);

        int inserir(lista *l, produto novo_produto);
        int remover(lista *l, chave codigo_produto);
        produto pesquisar(lista *l, chave codigo_produto);
        int alterar(lista *l, chave codigo_antigo);

        void imprimir_lista(lista *l);
        void imprimir_produto(produto pesquisado);
        produto ler_produto();
        chave ler_codigo();

#endif