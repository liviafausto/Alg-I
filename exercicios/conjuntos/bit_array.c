#include "conjuntos.h"

#include <stdio.h>
#include <string.h>

void inicializar(conjunto A){
    memset(A, 0, sizeof(conjunto));
}

void imprimir(conjunto A){
    printf("{ ");
    for(int k=0; k<max; k++){
        if(pertence(k, A))
            printf("%d ", k);
    } printf("}\n");
}

char pertence(elemento x, conjunto A){
    if(x < 0 || x >= max){
        printf("Digite um elemento valido (entre 0 e %d).\n", max);
        return OUTRO_ERRO;
    } else {
        return A[x];
    }
    
}

char inserir(elemento x, conjunto A){
    if(pertence(x, A)){
        printf("O elemento ja pertence ao conjunto.\n");
        return JA_EXISTE;
    } else {
        A[x] = 1;
        return SEM_ERRO;
    }
    
}

char remover(elemento x, conjunto A){
    if(!pertence(x, A)){
        printf("O elemento nao pertence ao conjunto.\n");
        return OUTRO_ERRO;
    } else {
        A[x] = 0;
        return SEM_ERRO;
    }
}