#include "produtos.h"
#include <stdio.h>
#include <string.h>

static marcador pesquisa_posicao(lista *l, chave codigo_produto); //função que pesquisa o codigo de um produto e retorna sua posição como um marcador

int criar(lista *l){
    l->ultimo = -1;
}

int vazia(lista *l){
    if(l->ultimo == -1)
        return 1;
    else
        return 0;
}

int cheia(lista *l){
    if(l->ultimo == TAM_MAX-1)
        return 1;
    else
        return 0;
}


int inserir(lista *l, produto novo_produto){
    if(cheia(l)){
        printf("Lista cheia.\n");
        return ERRO;
    }

    if(pesquisa_posicao(l, novo_produto.codigo) >= 0){
        printf("Produto ja existe.\n");
        return ERRO;
    }

    l->ultimo++;
    l->pecas[l->ultimo] = novo_produto;
    
    return SUCESSO;
}

int remover(lista *l, chave codigo_produto){
    if(vazia(l)){
        printf("Lista vazia");
        return ERRO;
    }

    marcador remover_posicao = pesquisa_posicao(l, codigo_produto);
    
    if(remover_posicao >= 0){

        for(int i=remover_posicao; i < l->ultimo; i++){
            l->pecas[i] = l->pecas[i+1];
        }

        l->ultimo--;
        return SUCESSO;

    } else {
        return ERRO;
    }

}

produto pesquisar(lista *l, chave codigo){
    marcador produto = pesquisa_posicao(l, codigo);

    if(produto >= 0)
        return l->pecas[produto];

}

int alterar(lista *l, chave codigo_antigo){
    if(vazia(l))
        return ERRO;

    marcador modificar_posicao = pesquisa_posicao(l, codigo_antigo);

    if(modificar_posicao >= 0){


        return SUCESSO;
    } else {
        return ERRO;
    }
}

void escolher(produto produto_antigo){
    int escolha, aux;

    //1- trocar codigo
    //2- trocar nome
    //3 - trocar quantidade
    //4 - trocar peso
    scanf("%d", &escolha);

    switch (escolha){
    case 1:
        aux = produto_antigo.codigo;

        break;
    
    default:
        break;
    }
}


void imprimir_lista(lista *l){
    if(!vazia(l)){
        printf("\n");
        for(int i=0; i <= l->ultimo; i++){
            printf("Codigo: %d\n", l->pecas[i].codigo);
            printf("Nome do produto: %s\n", l->pecas[i].nome);
            printf("Quantidade: %d\n", l->pecas[i].quantidade);
            printf("Peso: %.2fg\n", l->pecas[i].peso); printf("\n");
        }

    } else {
        printf("A lista esta vazia.\n");
    }
}

void imprimir_produto(produto pesquisado){
    printf("\n[%d] %s\n", pesquisado.codigo, pesquisado.nome);
    printf("Qtde = %d  Peso = %.2lf\n", pesquisado.quantidade, pesquisado.peso);
}

produto ler_produto(){
    produto novo;

    printf("Codigo: "); scanf("%d", &novo.codigo);
    printf("Nome: "); scanf("%s", novo.nome);
    printf("Quantidade: "); scanf("%d", &novo.quantidade);
    printf("Peso: "); scanf("%lf", &novo.peso);

    return novo;
}

chave ler_codigo(){
    chave codigo_produto;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo_produto);

    return codigo_produto;
}


static marcador pesquisa_posicao(lista *l, chave codigo_produto){
    marcador posicao=0;

    for(posicao=0; posicao <= l->ultimo; posicao++){

        if(l->pecas[posicao].codigo == codigo_produto)
            return posicao;
    }

    return ERRO;

}