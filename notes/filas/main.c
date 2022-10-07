#include <stdio.h>
#include <string.h>
#include "fila.h"

int main() {
    fila supermercado; elemento pessoa; int opcao=0;

    criar(&supermercado);

    while(opcao != 6){
        opcao = menu(opcao);

        switch(opcao){
            case 1:
                printf("\nINSERIR PESSOA NA FILA\n");
                pessoa = ler_item(pessoa);

                if(enfileirar(&supermercado, pessoa) == SUCESSO){
                    printf("%s agora esta esperando na fila.\n", pessoa.nome);
                }

                break;
            
            case 2:
                if(desenfileirar(&supermercado) == SUCESSO){
                    imprimir(&supermercado);
                }

                break;
            case 5:
                imprimir(&supermercado);
                
                break;
            
            case 6:
                liberar_fila(&supermercado);
                
                break;
            
            default:
                printf("Insira uma opcao valida.\n");
                break;
        }
    }

    return 0;
}