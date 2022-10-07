#ifndef CONTATINHOS_H

    #define CONTATINHOS_H
    #define MAX_OPERACOES 110
    #define MAX_NOME 11
    #define MAX_TELEFONE 10

    #define JA_EXISTE -1
    #define NAO_ENCONTRADO 0
    #define SUCESSO 1

    typedef char nome;
    typedef char marcador;

    typedef struct{
        nome contato[MAX_NOME];
        char num_telefone[MAX_TELEFONE];
    } elemento;

    typedef struct{
        elemento contatinho[MAX_OPERACOES];
        marcador ultimo;
    } lista;

    void criar(lista *agenda);
    int inserir(lista *agenda, elemento novo_contatinho);
    int pesquisar(lista *agenda, nome contatinho);
    int remover(lista *agenda, nome contatinho);
    int alterar(lista *agenda, nome contatinho);

    static elemento pesquisa_nome(lista *agenda, nome contatinho);

#endif