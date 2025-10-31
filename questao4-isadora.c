/*

Aluno(a): Isadora Luísa Candini Marques
RA: 10730955
Atividade: Questão 4 - Menor número de paradas em viagem


objetiva o alcance do carro (m), as distâncias dos postos e o 
destino final, determinar o menor número de paradas 
necessárias para chegar ao destino, abastecendo apenas 
quando for realmente preciso.

algoritmo guloso: o carro anda o máximo possível 
com o tanque atual antes de parar, ou seja, para sempre no 
último posto alcançável antes de ficar sem combustível.

Complexidade de tempo:
O(n), pois percorre os postos uma única vez.

*/

#include <stdio.h>

int main() {

 // número de postos
    int m;          
    int destino;    
    int d[100];     // vetor que vai armazenar as distâncias dos postos
    int i;          


    // Entrada de dados

    printf("Digite o número de postos na estrada: ");
    scanf("%d", &n);

    printf("Digite a autonomia do carro (m) em km: ");
    scanf("%d", &m);

    printf("Digite a distância até o destino final (em km): ");
    scanf("%d", &destino);

    printf("Digite as distâncias dos postos (em ordem crescente):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    // Adiciona o destino como um "posto extra" (facilita a lógica)
    d[n] = destino;

    // -----------------------------
    // Inicialização
    // -----------------------------
    int paradas = 0;            // contador de paradas
    int alcance = m;            // distância máxima que o carro percorre com o tanque cheio
    int ultimo_posto = 0;       // guarda o último posto em que foi feito o abastecimento

    // -----------------------------
    // Lógica principal do algoritmo guloso
    // -----------------------------
    // Ideia: percorre os postos, e quando o próximo estiver fora do alcance,
    // o carro para no último posto possível antes de ficar sem combustível.
    for (i = 0; i <= n; i++) {
        if (d[i] > alcance) {
            // Se o próximo posto estiver fora do alcance atual:
            // - precisa parar no último posto alcançável (d[i-1])
            paradas++;
            ultimo_posto = d[i - 1];     // salva o posto onde parou
            alcance = ultimo_posto + m;  // redefine o novo alcance depois de abastecer

            // Se mesmo assim não for possível alcançar o próximo posto, é impossível chegar
            if (d[i] > alcance) {
                printf("\n  Não é possível chegar ao destino com essa autonomia.\n");
                return 0;
            }
        }
    }

    printf("\nMenor número de paradas necessárias: %d\n", paradas);
    printf("Último posto em que parou: %d km da origem.\n", ultimo_posto);
    printf("Distância total até o destino: %d km\n", destino);

 
    return 0;
}
