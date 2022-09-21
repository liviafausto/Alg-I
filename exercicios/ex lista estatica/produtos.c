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
        printf("Lista cheia.\n\n");
        return ERRO;
    }

    if(pesquisa_posicao(l, novo_produto.codigo) >= 0){
        printf("Produto ja existe.\n\n");
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

static marcador pesquisa_posicao(lista *l, chave codigo_produto){
    marcador posicao=0;

    for(posicao=0; posicao <= l->ultimo; posicao++){

        if(l->pecas[posicao].codigo == codigo_produto)
            return posicao;
    }

    return ERRO;

}
produto pesquisar(lista *l, chave codigo){
    marcador produto = pesquisa_posicao(l, codigo);

    if(produto >= 0){
        return l->pecas[produto];
    }
    else {

    }

}

int alterar(lista *l, chave codigo_antigo){
    if(vazia(l))
        return ERRO;

    marcador posicao = pesquisa_posicao(l, codigo_antigo);

    if(posicao >= 0){
        l->pecas[posicao] = escolher(l->pecas[posicao]);
        return SUCESSO;

    } else {
        return ERRO;
    }
}