#include <stdio.h>
#include <string.h>
#include "contatinhos.h"

int main() {
    char operacao = '-1';
    char fim_do_programa = '0';
    //int contador = -1;
    //int num_operacao[MAX_OPERACOES];

    lista agenda; elemento contatinho;

    while(operacao != fim_do_programa){

        scanf("%c", &operacao); scanf("%s", contatinho.nome_pessoa);

        switch (operacao){
        
        case 'I':
            scanf("%s", contatinho.num_telefone);
            inserir(&agenda, contatinho);
            break;
        
        case 'P':
            pesquisar(&agenda, contatinho.nome_pessoa);
            break;
        
        case 'R':
            remover(&agenda, contatinho.nome_pessoa);
            break;

        case 'A':
            scanf("%s", contatinho.num_telefone);
            alterar(&agenda, contatinho.nome_pessoa);
            break;
        
        default:
            break;
        }
        

    }

    return 0;
}