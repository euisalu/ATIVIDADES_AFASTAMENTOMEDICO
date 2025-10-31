/*

Aluno(a): Isadora Luísa Candini Marques
RA: 10730955

Questão 5 - Problema da Mochila Fracionária

Objetivo:
Dado um conjunto de objetos com pesos e valores, e uma 
capacidade máxima da mochila, determinar a fração ideal de 
cada objeto (0 ≤ xi ≤ 1) que maximize o valor total.


Usando um algoritmo guloso:
1. Calcula o valor por peso (v[i]/p[i]) de cada item
2. Ordena em ordem decrescente dessa razão
3. Insere-se o item inteiro enquanto couber
4. Caso o próximo item não caiba inteiro, insere-se apenas 
   a fração que ainda cabe na mochila.

Complexidade de tempo:
O(n log n) devido à ordenação
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um item com peso, valor e razão
typedef struct {
    double peso;
    double valor;
    double razao; 
} Item;

// Função de comparação para ordenar em ordem decrescente de razão
int cmp(const void *a, const void *b) {
    double r1 = ((Item*)a)->razao;
    double r2 = ((Item*)b)->razao;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

int main() {
    int n, i;
    double capacidade, valor_total = 0.0;

    // Entrada de dados
    printf("Digite o número de objetos: ");
    scanf("%d", &n);

    printf("Digite a capacidade da mochila: ");
    scanf("%lf", &capacidade);

    Item *itens = malloc(n * sizeof(Item));
    double *x = malloc(n * sizeof(double)); // fração de cada item

    printf("Digite o peso e o valor de cada objeto:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &itens[i].peso, &itens[i].valor);
        itens[i].razao = itens[i].valor / itens[i].peso;
        x[i] = 0.0;
    }

    // Ordena os itens por valor/peso (decrescente)
    qsort(itens, n, sizeof(Item), cmp);

    double capacidade_restante = capacidade;

    // Processo guloso de preenchimento
    for (i = 0; i < n; i++) {
        if (itens[i].peso <= capacidade_restante) {
            // Cabe inteiro
            x[i] = 1.0;
            valor_total += itens[i].valor;
            capacidade_restante -= itens[i].peso;
        } else {
            // Cabe apenas uma fração
            x[i] = capacidade_restante / itens[i].peso;
            valor_total += itens[i].valor * x[i];
            capacidade_restante = 0;
            break; // mochila cheia
        }
    }

    // Saída dos resultados
    printf("\nSolução (fração de cada objeto):\n");
    for (i = 0; i < n; i++) {
        printf("Objeto %d: %.2lf%% (peso %.2lf, valor %.2lf, valor/peso %.2lf)\n",
               i + 1, x[i] * 100, itens[i].peso, itens[i].valor, itens[i].razao);
    }

    printf("\nValor total na mochila: %.2lf\n", valor_total);

    free(itens);
    free(x);
    return 0;
}
