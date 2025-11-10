#include <stdio.h>
#include <stdlib.h>
#include "racionais.h"

/* Impressao dos elementos com espacamento e quebra de linha */
void laco_impressao (int n, struct racional **v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        imprime_r(v[i]);
        printf(" ");
    }

    printf("\n");
}

/* Funcao de troca do quicksort */
void troca(struct racional **vet, int M, int I) 
{
    struct racional *temp = vet[M];
    vet[M] = vet[I];
    vet[I] = temp;
}

/* Funcao de particao do quicksort */
int particao(struct racional **vet, int a, int b) 
{
    /* Struct para elemento engessado e indices */
    struct racional *pivo = vet[b];
    int i = a - 1;
    int j;

    /* Troca os elementos com base no pivo */
    for (j = a; j < b; j++) 
    {
        if (compara_r(vet[j], pivo) <= 0) 
        {
            i++;
            troca(vet, i, j);
        }
    }

    /* Ajusta a posicao do pivo */
    troca(vet, i + 1, b);
    return i + 1;
}

/* Quicksort recursivo */
void quicksort(struct racional **vetor, int a, int b) 
{
    if (a < b) 
    {
        int m = particao(vetor, a, b);
        /* Recursao da primeira parte do vetor*/
        quicksort(vetor, a, m - 1);
        /* Recursao da segunda parte do vetor */
        quicksort(vetor, m + 1, b);
    }
}

int main ()
{
    /* Vetor de ponteiros para racionais e struct da soma */
    struct racional **v, *soma;  
    /* Variaveis para tamanho do vetor, indices e elementos num/den */
    int N, i, j, dado1, dado2;

    scanf("%d", &N);

    v = malloc(N * sizeof(struct racional *));

    /* Verifica se a alocacao deu certo */
    if (v == NULL)
        return 1;
    
    /* For para Leitura de dados e inicializacao do vetor */
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &dado1, &dado2);
        v[i] = cria_r(dado1, dado2);
    }

    laco_impressao(N, v);

    /* For para remover elementos invalidos */
    for (i = 0; i < N; i++)
    {
        if (!valido_r(v[i]))
        {
            free(v[i]);
            for (j = i; j < N - 1; j++)
                v[j] = v[j + 1];

            N--;
            i--;
        }
    }

    laco_impressao(N, v);
    
    /* Ordena o vetor de racionais com base no quicksort */
    quicksort(v, 0, N - 1);

    laco_impressao(N, v);
    
    /* Inicializacao da soma com 0 */
    soma = cria_r(0, 1);

    /* Soma os racionais e libera os ja somados */
    for (i = 0; i < N; i++)
    {
        soma_r(v[i], soma, soma);
        destroi_r(v[i]);
    }

    /* Liberacao de v, impressao da soma e liberacao da soma */
    free(v);
    printf("a soma de todos os elementos eh: ");
    imprime_r(soma);
    free(soma);
    printf("\n");
        
    return 0;
}
