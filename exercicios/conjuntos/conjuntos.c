#include "conjuntos.h"

#include <stdio.h>
#include <string.h>

void inicializar(conjunto A){
    memset(A, 0, sizeof(conjunto));
}

void imprimir(conjunto A){
    printf("{ ");
    for(int k=0; k<max; k++){
        printf("%d ", A[k]);
    } printf("}\n");
}

char pertence(elemento x, conjunto A){
    for(int k=0; k<max; k++){
        if(A[k] == x){
            return JA_EXISTE;
        }
    }

    return SEM_ERRO;
}

char inserir(elemento x, conjunto A){
    if(pertence(x, A)){
        printf("O elemento %d ja pertence ao conjunto.\n", x);
        return JA_EXISTE;
    }

    for(int k=0; k<max; k++){
        if(A[k] == 0){
            A[k] = x;
            return SEM_ERRO;
        }
    }

    printf("O elemento %d nao foi inserido, pois o conjunto esta cheio.\n", x);
    return OUTRO_ERRO;
}

char remover(elemento x, conjunto A){
    if(!pertence(x, A)){
        printf("O elemento %d nao pertence ao conjunto. Nao eh possivel remove-lo.\n", x);
        return OUTRO_ERRO;
    }

    for(int k=0; k<max; k++){
        if(A[k] == x){
            A[k] = 0;
            printf("O elemento %d foi removido do conjunto.\n", x);
            return SEM_ERRO;
        }
    }
}