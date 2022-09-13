#ifndef CONJUNTOS_H

    #define CONJUNTOS_H
        #define max 100

        #define SEM_ERRO 0
        #define JA_EXISTE 1
        #define OUTRO_ERRO 2

        typedef int elemento;
        typedef elemento conjunto[max];

        void inicializar(conjunto A); //inicializa o conjunto
        void imprimir(conjunto A); //imprime o conjuto

        char pertence(elemento x, conjunto A); //verifica se um elemento pertence ao conjunto
        char inserir(elemento x, conjunto A); //insere elementos no conjunto
        char remover(elemento x, conjunto A); //remove elementos do conjunto

#endif