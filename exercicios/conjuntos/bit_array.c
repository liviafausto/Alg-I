#include "conjuntos.h"

#include <stdio.h>
#include <string.h>

void inicializar(conjunto A){
    memset(A, 0, sizeof(conjunto));
}
void imprimir(conjunto A){
    
}

char pertence(elemento x, conjunto A); //verifica se um elemento pertence ao conjunto
char inserir(elemento x, conjunto A); //insere elementos no conjunto
char remover(elemento x, conjunto A); //remove elementos do conjunto