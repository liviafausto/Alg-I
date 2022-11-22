#include "avl.h"
#include <stdio.h>

//A eficiência das operações numa ABB depende da profundidade dos nós folha
//Tal profundidade depende do seu balanceamento

//AVL: nome vem dos seus criadores - Adelson-Velsky e Landis

int criar(arvore *avl);
int retornar_altura(arvore *avl);
int checar_fatorBalanceamento(arvore *avl);
int inserir(arvore *avl, elemento folha);
elemento pesquisar(arvore *avl, chave codigo);
int remover(arvore *avl, chave codigo);