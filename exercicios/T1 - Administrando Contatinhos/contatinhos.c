#include "contatinhos.h"
#include <stdio.h>
#include <string.h>

void criar(lista *agenda){
    agenda->ultimo = -1;
}

int inserir(lista *agenda, elemento novo_contatinho);
int pesquisar(lista *agenda, nome contatinho);
int remover(lista *agenda, nome contatinho);
int alterar(lista *agenda, nome contatinho);

static elemento pesquisa_nome(lista *agenda, nome contatinho);