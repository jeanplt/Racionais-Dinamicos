# Racionais-Dinamicos
Este repositório contém um programa modular em C que opera números racionais por meio de alocação dinâmica de vetores, determinando a quantidade exata de memória necessária para conter a sequência de racionais inseridos e realizar operações matemáticas com eles. Abaixo temos o enunciado adaptado deste trabalho para melhor contextualização:

Para este prgrama modular, temos os seguintes arquivos base contidos:
- racionais.h: arquivo de header com todos os protótipos das funções para manipular números racionais;
- racionais.c: um esqueleto de arquivo racionais.c;
- makefile: ferramenta de compilação;
- tp3.c: um esqueleto de arquivo tp3.c;
- exemplos: um conjunto de entradas para fins de testes;

Inicialmente, o programa irá alocar dinamicamente um vetor de ponteiros para números racionais. Em seguida, irá gerar vários ponteiros para números racionais gerados aleatoriamente e vai inserir estes ponteiros em ordem no vetor. Após estes passos iniciais, o programa irá manipular este vetor para eliminar os racionais inválidos e em seguida ordená-lo em ordem crescente. Por fim, também fará a soma destes racionais, irá imprimar o valor da soma e, após as impressões feitas em ordem como dito no pseudo-código abaixo, fará a liberação de memória usado pelo vetor dos racionais e sua soma: 

```
leia um n tal que 0 < n < 100
crie um vetor de n posicoes contendo ponteiros para numeros racionais
- Os racionais deverao ser inicializados com valores lidos do teclado
- Este vetor tambem deve ser alocado dinamicamente
imprima os racionais apontados pelos elementos do vetor
elimine deste vetor os racionais invalidos
imprima o vetor resultante
ordene este vetor
imprima o vetor ordenado
calcule e imprima a soma de todos os racionais apontados pelo vetor
libere toda a mem´oria alocada
- todos os racionais
- o vetor
- o espa¸co utilizado para fazer o c´alculo da soma
ao final, mude de linha
retorne 0
```
