#include <stdio.h>
#include "modulo.h"

int main() {
    int n = 10;
    int v[n];
    
    leVetor(v, n);
    insertion(v, n);
    imprimeVetor(v, n);

    return 0;
}