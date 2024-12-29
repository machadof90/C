#include <stdio.h>
#include "subtracao.h"

void subtracao() {
    int a, b;
    printf("Digite dois números para subtrair: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d\n", a - b);
}