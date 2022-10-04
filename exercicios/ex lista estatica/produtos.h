#ifndef PRODUTOS_H
    #define PRODUTOS_H

        #define TAM_MAX 50

        #define JA_EXISTE -3
        #define NAO_ENCONTROU -2
        #define ERRO_VAZIA -1
        #define ERRO_CHEIA 0
        #define SUCESSO 1

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

        //produtos.c
        int criar(lista *l);
        int vazia(lista *l);
        int cheia(lista *l);
        int inserir(lista *l, produto novo_produto);
        int pesquisar(lista *l, produto *pesquisar_produto);
        int alterar(lista *l, chave codigo_antigo);
        int remover(lista *l, chave codigo_produto);
        static marcador pesquisa_posicao(lista *l, chave codigo_produto);
        static void escolher(produto *antigo);

        //menu.c
        int menu();
        produto ler_produto();
        chave ler_codigo();
        void imprimir_lista(lista *l);
        void imprimir_produto(produto pesquisado);

#endif