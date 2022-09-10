//testando modularizacao em C
#include "modulo.h"
#include <stdio.h>

void leVetor(int v[], int tam){
    printf("Insira os elementos de um vetor de %d posicoes: ", tam);
    for(int k=0; k<tam; k++){
        scanf("%d", &v[k]);
    }
}

void insertion (int v[], int tam){

    for(int p=1; p<tam; p++){
        int x = v[p];
        int i = p-1;

        while(i >= 0 && x < v[i]){
            v[i+1] = v[i];
            i--;
        }

        v[i+1] = x;
    }
    
}

void imprimeVetor(int v[], int tam){
    printf("v =");
    for(int k=0; k<tam; k++){
        printf(" %d", v[k]);
    } printf("\n");

}