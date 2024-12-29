#include <stdio.h>
#include "soma.h"

void soma() {
    int a, b;
    printf("Digite dois números para somar: ");
    scanf("%d %d", &a, &b);
    printf("Resultado: %d\n", a + b);
}