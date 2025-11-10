#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

int mdc (int a, int b)
{
    /* Variavel temporaria para possibilitar trocas de a com b */
    int temp;

    /* Laço do MDC, metodo de Euclides */
    while (b != 0)
    {
        a %= b;
        temp = a;
        a = b;
        b = temp;
    }

    return a;
}

int mmc (int a, int b)
{
    return a*b/mdc(a,b);
}

struct racional *cria_r (long int numerador, long int denominador)
{
    struct racional *novoR = malloc(sizeof(struct racional));

    /* Verifica se alocou corretamente a memoria */
    if (novoR == NULL)
        return NULL;

    /* Arruma o novo racional e o simplifica */
    novoR->num = numerador;
    novoR->den = denominador;

    simplifica_r(novoR);

    return novoR;
}

void destroi_r (struct racional *r)
{
    free(r);
}

/* Nao utilizada */
long int numerador_r (struct racional *r)
{
    if (r == NULL)
        return 0;

    return r->num;
}

/* Nao utilizada */
long int denominador_r (struct racional *r)
{
    if (r == NULL)
        return 0;
    
    return r->den;
}

int valido_r (struct racional *r)
{
    if (r == NULL || r->den == 0)
        return 0;

    return 1;
}

void imprime_r (struct racional *r)
{
    /* Verificacoes de todos os casos especiais, antes da impressao */
    if (r == NULL)
    {
        printf("NULO");
        return;
	}

    if (r->den == 0)
    {
        printf("INVALIDO");
        return;
    }
	
    if (r->num == 0)
    {
        printf("0");
        return;
    }
    
    if (r->den == 1)
    {
        printf("%ld", r->num);
        return;
    }
       
    if (r->num == r->den)
    {
        printf("1");
        return;
    }
    
    if (r->num < 0 && r->den < 0)
    {
        printf("%ld/%ld", -r->num, -r->den);
        return;
	}
	
    if (r->num < 0 || r->den < 0)
    {
        printf("-%ld/%ld", labs(r->num), labs(r->den));
        return;    
    }
     
    printf("%ld/%ld", r->num, r->den);
}

int compara_r (struct racional *r1, struct racional *r2)
{
    /* Verifica se os racionais estao alocados ou sao validos */
    if (!valido_r(r1) || !valido_r(r2))
        return -2;
    
    /* Variaveis para comparar racionais */
    int MMC = mmc(r1->den, r2->den);
    int valorR1 = r1->num/MMC;
    int valorR2 = r2->num/MMC;

    if (valorR1 < valorR2)
        return -1;
    
    if (valorR1 == valorR2)
        return 0;
    
    return 1;
}

int simplifica_r (struct racional *r)
{
    if (!valido_r(r))
        return 0;
    
    /* Variavel para receber o MDC de num e den de r */
    int MDC = mdc(r->num, r->den);

    r->num /= MDC;
    r->den /= MDC;

    /* Troca o sinal caso r seja negativo */
    if (r->den < 0)
    {
        r->num = -r->num;
        r->den = -r->den;
    }

    return 1;
}

int soma_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if (!valido_r(r1) || !valido_r(r2))
        return 0;

    /* Propriedades da soma de racionais */
    r3->den = mmc(r1->den, r2->den);

    int Tnum1 = r1->num * (r3->den/r1->den);
    int Tnum2 = r2->num * (r3->den/r2->den);

    r3->num = Tnum1 + Tnum2;

    /* Simplificacao de r3 */
    simplifica_r(r3);

    return 1;
}

/* Nao utilizada */
int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if (!valido_r(r1) || !valido_r(r2))
        return 0;

    /* Propriedades da subtracao de racionais */
    r3->den = mmc(r1->den, r2->den);

    int Tnum1 = r1->num * (r3->den/r1->den);
    int Tnum2 = r2->num * (r3->den/r2->den);

    r3->num = Tnum1 - Tnum2;

    /* Simplificacao de r3 */
    simplifica_r(r3);

    return 1;
}

/* Nao utilizada */
int multiplica_r (struct racional *r1, struct racional *r, struct racional *r32)
{
    if (!valido_r(r1) || !valido_r(r))
        return 0;

    /* Propriedades da multiplicacao de racionais */
    r32->num = r1->num * r->num;
    r32->den = r1->den * r->den;

    simplifica_r(r32);

    return 1;
}

/* Nao utilizada */
int divide_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    if (!valido_r(r1) || !valido_r(r2))
        return 0;

    /* Propriedades da divisao de racionais */
    r3->num = r1->num * r2->den;
    r3->den = r2->den * r2->num;

    /* Verifica se r3 eh valido para nao simplifica-lo de forma errada */
    if (!valido_r(r3))
        return 0;

    simplifica_r(r3);

    return 1;
}
