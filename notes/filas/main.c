#include <stdio.h>
#include <string.h>
#include "fila.h"

int main() {
    fila supermercado; elemento pessoa; int contador, opcao=0;

    criar(&supermercado);

    while(opcao != 5){
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

            case 3:
                if(vazia(&supermercado)){
                    printf("Fila vazia.\n");
                } else {
                    pessoa = item_inicio(&supermercado);
                    printf("A primeira pessoa da fila eh: %d - %s\n", pessoa.num, pessoa.nome);
                }

                break;

            case 4:
                contador = contar(&supermercado);
                
                if(contador >= 0){
                    printf("Existem %d pessoas na fila.\n", contador);
                }
                break;
            
            case 5:
                liberar_fila(&supermercado);
                
                break;
            
            default:
                printf("Insira uma opcao valida.\n");
                break;
        }
    }

    return 0;
}