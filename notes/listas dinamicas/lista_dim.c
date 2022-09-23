#include "lista_dim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criar(lista *lista){
    lista->head = NULL;
    lista->ultimo = NULL;
}

int vazia(lista *lista){

    if(lista->head == NULL)
        return 1;
    else 
        return 0;
}

int inserir(lista *lista, elemento novo_item){

    if(pesquisar (lista, novo_item) == SUCESSO){
        printf("Esse item ja esta na lista.\n");
        return JA_EXISTE;
    }

    apontador novo = (apontador) malloc (sizeof(no));
    if(novo == NULL){
        printf("Lista cheia.\n");
        return ERRO_CHEIA;
    }

    novo->proximo = NULL;
    novo->item = novo_item;

    if(vazia(lista)){
        lista->head = novo;
        lista->ultimo = novo;

    } else {
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
    }

    return SUCESSO;
}

int remover(lista *lista, chave codigo_item){

    if(vazia(lista)){
        printf("Lista vazia.\n");
        return ERRO_VAZIA;
    }

    apontador remover_no = pesquisa_posicao(lista, codigo_item);

    if(remover_no == NULL){
        printf("Esse item nao existe.\n");
        return NAO_ENCONTROU;
    }

    if(remover_no == lista->head && remover_no == lista->ultimo){
       criar(lista);
       free(remover_no);
       printf("O unico elemento da lista foi removido.\n");
       return SUCESSO;
    }

    if(remover_no == lista->head){
        lista->head = lista->head->proximo;
        free(remover_no);
        printf("O primeiro elemento da lista foi removido.\n");
        return SUCESSO;
    }

    apontador no_anterior = lista->head;

    while(no_anterior != NULL && no_anterior != remover_no){
        no_anterior = no_anterior->proximo;
    }

    no_anterior->proximo = remover_no->proximo;

    if(remover_no == lista->ultimo){
        lista->ultimo = no_anterior;
        printf("O ultimo elemento da lista foi removido.\n");
    }

    free(remover_no);
    return SUCESSO;
     
}

int pesquisar(lista *lista, elemento pesquisar_item){

    if (vazia(lista)){
        printf("Lista vazia.\n");
        return ERRO_VAZIA;
    }

    apontador pesquisar = pesquisa_posicao(lista, pesquisar_item.codigo);

    if(pesquisar == NULL){
        printf("O item pesquisado nao existe.\n");
        return NAO_ENCONTROU;
    }

    pesquisar_item = pesquisar->item;
    imprimir_elemento(pesquisar_item);
    return SUCESSO;

}

int alterar(lista *lista, elemento novo_elemento);

void imprimir(lista *lista){
    printf("\nLISTA:\n");

    apontador percorre_lista = lista->head;

    while(percorre_lista != NULL){
        printf("[ %d ] - %s\n", percorre_lista->item.codigo, percorre_lista->item.nome);
        percorre_lista = percorre_lista->proximo;
    }
}

void imprimir_elemento(elemento item){
    printf("\nCODIGO: %d\n", item.codigo);
    printf("NOME: %s\n", item.nome);
}

apontador pesquisa_posicao(lista *lista, chave codigo_item){

    apontador pesquisa_pos = lista->head;

    while (pesquisa_pos != NULL){

        if(pesquisa_pos->item.codigo == codigo_item){
            return pesquisa_pos;
        }
        else {
            pesquisa_pos = pesquisa_pos->proximo;
        }
    }

    return NULL;
}

elemento ler_novo_item(elemento novo_item){
    
    printf("\nInsira os dados do novo item que deseja inserir.\n\n");
    printf("CODIGO: "); scanf("%d", &novo_item.codigo);
    printf("NOME: "); scanf("%s", novo_item.nome);

    return novo_item;

}

chave ler_chave(chave codigo_item){

    printf("\nDigite o codigo do item: "); scanf("%d", &codigo_item);

    return codigo_item;
}

int menu(int opcao) {
    printf("\nO que deseja fazer?\n\n");

    printf("1 - Inserir novo item na lista.\n");
    printf("2 - Pesquisar item da lista.\n");
    printf("3 - Remover item da lista.\n");
    printf("5 - Sair.\n\n");

    scanf("%d", &opcao);
    return opcao;
}