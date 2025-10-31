/*
-----------------------------------------------------------
Aluno(a): Isadora Luísa Candini Marques
RA: 10730955
Questão 1 Problema do Troco
Ler um valor em reais (com duas casas decimais) e calcular
o menor número possível de notas e moedas necessárias
para representar esse valor.

*/

#include <stdio.h>

int main() {
    double valor;   
    int centavos;   


    printf("Digite o valor em R$: ");
    scanf("%lf", &valor);

    //  Converto o valor em reais para centavos
    // Multiplico por 100 para trabalhar só com inteiros e evitar erros com ponto flutuante
    // Adiciono 0.0001 para corrigir possíveis imprecisões (ex: 576.73 pode virar 57672.9999)
    centavos = (int)((valor + 0.0001) * 100);


    int notas[] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[] = {100, 50, 25, 10, 5, 1};
    int qtd;  

    printf("\nNOTAS:\n");
    for (int i = 0; i < 6; i++) {
        qtd = centavos / notas[i];  // calcula quantas notas desse tipo cabem
        printf("%d nota(s) de R$ %.2f\n", qtd, notas[i] / 100.0);
        centavos = centavos % notas[i];  // atualiza o valor restante
    }

    // -----------------------------------
    //  Moedas (valores em centavos)
    // -----------------------------------
    printf("\nMOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        qtd = centavos / moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", qtd, moedas[i] / 100.0);
        centavos = centavos % moedas[i];
    }


    // Esse programa calcula o troco mínimo com base no valor digitado,
    // mostrando a quantidade ideal de cada nota e moeda.
    return 0;
}
