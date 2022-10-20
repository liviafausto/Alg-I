#include <stdio.h>
#include "ex03.h"

fila NovaOrdem(fila *f, int n){
    pilha aux; fila invertida; no item_no;
    apontador percorre = f->primeiro;
    int contador;

    while(percorre != NULL){
        contador = 0;

        while(contador < n){
            item_no.item = percorre->item;
            push(&aux, item_no.item);
            contador++;
        }

        while(contador > 0){
            item_no = topo(&aux);
            enfileirar(&invertida, item_no.item);
            pop(&aux);
            contador--;
        }

        return invertida;
    }
}

int main() {
    fila numeros; criar_fila(&numeros);
    int n; int op; elemento novo_num;

    printf("n = "); scanf("%d", &n);
    printf("1: inserir numero na fila | 2: imprimir fila em nova ordem\n");
    scanf("%d", &op);

    if(op == 1){
        scanf("%d", &novo_num.num);
        enfileirar(&numeros, novo_num);

    } else if(op == 2){
        imprimir_fila(&numeros);
    }


    return 0;
}