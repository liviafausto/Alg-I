#include "produtos.h"
#include <stdio.h>
#include <string.h>

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
        return ERRO_CHEIA;
    }

    if(pesquisa_posicao(l, novo_produto.codigo) >= 0){
        printf("Produto ja existe.\n\n");
        return JA_EXISTE;
    }

    l->ultimo++;
    l->pecas[l->ultimo] = novo_produto;
    
    return SUCESSO;
}

int pesquisar(lista *l, produto *pesquisar_produto){
    if(vazia(l)){
        printf("Lista vazia.\n");
    }
    marcador posicao_produto = pesquisa_posicao(l, pesquisar_produto->codigo);

    if(posicao_produto < 0){
        printf("Esse produto nao existe\n");
        return NAO_ENCONTROU;
    }

    strcpy(pesquisar_produto->nome, l->pecas[posicao_produto].nome);
    pesquisar_produto->quantidade = l->pecas[posicao_produto].quantidade;
    pesquisar_produto->peso = l->pecas[posicao_produto].peso;

    return SUCESSO;
}

int alterar(lista *l, chave codigo_antigo){
    if(vazia(l)){
        printf("Lista vazia.\n");
        return ERRO_VAZIA;
    }
    marcador alterar_posicao = pesquisa_posicao(l, codigo_antigo);

    if(alterar_posicao < 0){
        printf("Esse produto nao existe.\n");
        return NAO_ENCONTROU;
    }

    escolher(&l->pecas[alterar_posicao]);

    return SUCESSO;
}

int remover(lista *l, chave codigo_produto){
    if(vazia(l)){
        printf("Lista vazia");
        return ERRO_VAZIA;
    }

    marcador remover_posicao = pesquisa_posicao(l, codigo_produto);
    
    if(remover_posicao < 0){
        printf("Esse item nao existe.\n");
        return NAO_ENCONTROU;
    }

    for(int i=remover_posicao; i < l->ultimo; i++){
        l->pecas[i] = l->pecas[i+1];
    }

    l->ultimo--;
    return SUCESSO;

}

static marcador pesquisa_posicao(lista *l, chave codigo_produto){
    marcador posicao=0;

    for(posicao=0; posicao <= l->ultimo; posicao++){

        if(l->pecas[posicao].codigo == codigo_produto)
            return posicao;
    }

    return NAO_ENCONTROU;

}

static void escolher(produto *antigo){
    int opcao=0;

    while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
        printf("\nO que voce deseja alterar?\n\n");
        printf("1- Trocar codigo do produto\n"); 
        printf("2- Trocar nome do produto\n");
        printf("3- Trocar quantidade do produto\n"); 
        printf("4- Trocar peso do produto\n\n");

        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Digite o novo codigo do produto: "); 
            scanf("%d", &antigo->codigo);

            break;
        
        case 2:
            printf("Digite o novo nome do produto: "); 
            scanf("%s", antigo->nome);

            break;

        case 3:
            printf("Digite a nova quantidade do produto: "); 
            scanf("%d", &antigo->quantidade);

            break;

        case 4:
            printf("Digite o novo peso do produto: "); 
            scanf("%lf", &antigo->peso);

            break;
        
        default:
            printf("Insira uma opcao valida para continuar.\n");
            break;
        }
    }

}