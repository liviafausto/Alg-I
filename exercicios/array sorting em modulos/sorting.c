#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>

void insertion(vetor *v) {
  int key, y;
  for(int x = 1; x < v->n; x++) {
    key = v->elementos[x];
    y = x - 1;

    v->T++;

    while(y >= 0 && v->elementos[y] > key) {
      v->elementos[y+1] = v->elementos[y];
      y--;
      v->C++;
      v->T++;
    }

    if(y >= 0 && v->elementos[y] <= key)
      v->C++;

    v->elementos[y+1] = key;
    v->T++;

   }
}

void merge(vetor *v){
    int *v_aux = (int*) malloc(sizeof(int) * v->n);

    mergeBreak(v, 0, v->n-1, v_aux);

    free(v_aux);
}

void mergeBreak(vetor *v, int inicio, int fim, int *v_aux){
    if(inicio >= fim){
        return;
    }

    int meio = (inicio + fim)/2;

    mergeBreak(v, inicio, meio, v_aux);
    mergeBreak(v, meio+1, fim, v_aux);

    mergeSort(v, inicio, meio, fim, v_aux);
}

void mergeSort(vetor *v, int inicio, int meio, int fim, int *v_aux){
    int num1 = inicio;
    int num2 = meio+1;
    int k = 0;

    while(num1 <= meio && num2 <= fim){
        v->C++;
        if(v->elementos[num1] <= v->elementos[num2]){
            v_aux[k] = v->elementos[num1];
            num1++;

            v->T++;

         } else {
            v_aux[k] = v->elementos[num2];
            num2++;

            v->T++;
         }

         k++;
    }

    while(num1 <= meio){
        v_aux[k] = v->elementos[num1];
        num1++;
        k++;

        v->T++;
    }

    while(num2 <= fim){
        v_aux[k] = v->elementos[num2];
        num2++;
        k++;

        v->T++;
    }

    k=0;
    for(int i=inicio; i<=fim; i++){
        v->elementos[i] = v_aux[k];
        k++;

        v->T++;
    }

}