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
            if(pop(&historico) == SUCESSO){
                printf("A ultima pagina pesquisada foi removida do historico.\n");
            }
            break;

        case 3:
            if(vazia(&historico)){
                printf("Pilha vazia.\n");
                break;
            }

            pagina = topo(&historico).item;
            printf("A pagina %s foi a ultima a ser pesquisada\n", pagina.nome);

            break;

        case 4:
            printf("Existem %d paginas no historico.\n", contar(&historico));
            
            break;

        case 5:
            imprime(&historico);
            break;

        case 6:
            if(!vazia(&historico)){
                libera(&historico);
            }
            break;

        default:
            printf("Insira uma opcao valida.\n");
            break;
        }

    }
    

    return 0;
}