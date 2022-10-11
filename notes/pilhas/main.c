#include <stdio.h>
#include "pilha.h"

int main() {
    pilha historico; elemento pagina; int opcao=0;
    criar(&historico);

    while(opcao!=6){
        menu(&opcao);

        switch (opcao){
        case 1:
            ler_elemento(&pagina);
            if(push(&historico, pagina) == SUCESSO){
                printf("A pagina %s foi adicionada ao historico.\n", pagina.nome);
            }
            break;
        
        case 2:
            pagina = topo(&historico).item;
            if(pop(&historico) == SUCESSO){
                printf("A pagina %s foi removida do historico\n", pagina.nome);
            }
            break;

        case 3:
            pagina = topo(&historico).item;
            if(!vazia(&historico)){
                printf("A pagina %s foi a ultima a ser pesquisada\n", pagina.nome);
            }
            break;

        case 4:
            if(!vazia(&historico)){
                printf("Existem %d paginas no historico.\n", contar(&historico));
            }
            break;

        case 5:
            imprime(&historico);
            break;

        case 6:
            libera(&historico);
            break;

        default:
            printf("Insira uma opcao valida.\n");
            break;
        }

    }
    

    return 0;
}