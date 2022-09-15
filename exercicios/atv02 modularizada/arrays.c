#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>

void inicializar_vetores(vetor v1[], vetor v2[], int Q){

    for(int i = 0; i < Q; i++) {
        printf("Insira o tamanho do %dº vetor.\n", i+1);

        scanf("%d", &v1[i].n);
        v2[i].n = v1[i].n;

        v1[i].elementos = (int*)malloc(v1[i].n * sizeof(int));
        v1[i].C = 0;
        v1[i].T = 0;

        v2[i].elementos = (int*)malloc(v2[i].n * sizeof(int));
        v2[i].C = 0;
        v2[i].T = 0;

    }

}

void ler_elementos(vetor v1[], vetor v2[], int Q){

    for(int i=0; i<Q; i++){
        printf("Insira os %d elementos do %dº vetor.\n", v1[i].n, i+1);

        for(int j=0; j<v1[i].n; j++){
            scanf("%d", &v1[i].elementos[j]);
            v2[i].elementos[j] = v1[i].elementos[j];
        }
    }

}

void imprimir_insertion(vetor v[], int Q){

    for(int i=0; i<Q; i++){
        insertion(&v[i]);
        printf("I %d %d %d\n", v[i].n, v[i].T, v[i].C);
    }
}

void imprimir_merge(vetor v[], int Q){

    for(int i=0; i<Q; i++){
        merge(&v[i]);
        printf("M %d %d %d\n", v[i].n, v[i].T, v[i].C);
    }
}

void liberar_elementos(vetor v[], int Q){

    for(int i=0; i<Q; i++){
        free(v[i].elementos);
    }
}