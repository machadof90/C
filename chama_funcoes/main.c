// main.c
#include <stdio.h>
#include "funcao.h"

int main() {
    int num1, num2;

    // Solicita ao usuário dois números
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    // Chama a função de soma e exibe o resultado
    int resultado = soma(num1, num2);
    printf("A soma de %d e %d é: %d\n", num1, num2, resultado);

    return 0;
}
