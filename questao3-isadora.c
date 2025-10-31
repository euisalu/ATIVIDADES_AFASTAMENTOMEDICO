/*
-----------------------------------------------------------
Aluno(a): Isadora Luísa Candini Marques
RA: 10730955

 Questão 3 - Arquivos Digitais (Estratégia Gulosa)

Selecionar o maior número de arquivos que cabem em um pendrive
de capacidade 'c', priorizando os arquivos menores primeiro.

*/

#include <stdio.h>
#include <stdlib.h>

// Função de comparação usada pelo qsort (ordena de forma crescente)
int cmp(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

int main() {
    int n;          // número de arquivos
    int capacidade; // capacidade do pendrive (em MB)
    int *tamanho;   // vetor com os tamanhos dos arquivos
    int i, qtd = 0, soma = 0;

    // Entrada de dados
    printf("Digite o número de arquivos e a capacidade do pendrive (em MB): ");
    scanf("%d %d", &n, &capacidade);

    tamanho = malloc(n * sizeof(int));

    printf("Digite o tamanho de cada arquivo (em MB):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &tamanho[i]);
    }

    // Ordena os arquivos em ordem crescente (menores primeiro)
    qsort(tamanho, n, sizeof(int), cmp);

    // Estratégia gulosa: incluir o menor arquivo possível enquanto couber
    for (i = 0; i < n; i++) {
        if (soma + tamanho[i] <= capacidade) {
            soma += tamanho[i];
            qtd++;
        } else {
            break; // os próximos arquivos serão maiores, então pode parar
        }
    }

    // Saída de dados
    printf("\nMaior número de arquivos que cabem no pendrive: %d\n", qtd);
    printf("Espaço total ocupado: %d MB de %d MB\n", soma, capacidade);

    free(tamanho);
    return 0;
}
