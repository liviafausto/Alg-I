#ifndef SORTING_H
    #define SORTING_H

    typedef struct {int n; int *elementos; int C; int T;} vetor;

    void insertion(vetor *v);
    void merge(vetor *v);
    void mergeBreak(vetor *v, int inicio, int fim, int *v_aux);
    void mergeSort(vetor *v, int inicio, int meio, int fim, int *v_aux);

    int ler_quantidade();
    void inicializar_vetores(vetor v1[], vetor v2[], int Q);
    void ler_elementos(vetor v1[], vetor v2[], int Q);
    void imprimir_insertion(vetor v[], int Q);
    void imprimir_merge(vetor v[], int Q);
    void liberar_elementos(vetor v[], int Q);

#endif