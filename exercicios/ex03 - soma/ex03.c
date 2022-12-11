#include <stdio.h>
#include <stdlib.h>

/**Soma
 * Resolver o problema conhecido como 2-sum.
 * Nele, você recebe um grande conjunto A de inteiros e algumas consultas.
 * Cada consulta consiste em um número inteiro K, de forma que a resposta ao problema será positiva se houver quaisquer dois elementos distintos de A cuja soma seja k.
 * IMPORTANTE: a solução deve contemplar uma tabela hash.
*/

/**Exemplo de entrada e saída
 * ENTRADA:
 * 6
 * 33 10 22 15 123 9
 * 5
 * 133
 * 124
 * 27
 * 24
 * 15
 * SAÍDA:
 * S
 * N
 * N
 * S
 * N
*/

int buscaPar(int *A, int k); //busca dois elementos distintos em A cuja soma seja k

int main(){
    int N;      //número de elementos do conjunto A
    int M;      //número de consultas a serem feitas
    int *A;     //conjunto A de inteiros

    //1. Ler número de elementos do conjunto A
    scanf("%d", &N);
    A = (int*)malloc(sizeof(int)*N);

    //2. Ler elementos do conjunto A
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    //3. Ler número de consultas a serem feitas
    scanf("%d", &M);

    //4. Para cada uma das M consultas, ler um inteiro k e buscar a soma de par
    for(int i=0; i<M; i++){
        int k; //número que deve ser buscado
        scanf("%d", &k);

        int saida = buscaPar(A, k);
        //5. Se for possível encontrar a 2-sum, imprimir 'S'
        if(saida == 1){
            printf("S\n");
        } else {
            //6. Caso contrário, imprimir 'N'
            printf("N\n");
        }
    }

    return 0;
}

int buscaPar(int *A, int k){
    //1. Buscar dois elementos DISTINTOS de A, cuja soma seja k

    //2. Utilizar uma tabela hash

    //3. Se tais elementos existirem, retornar 1

    //4. Se os elementos não forem encontrados, retornar 0
}