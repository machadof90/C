// main.c
#include <stdio.h>
#include "funcao/soma.h"
#include "funcao/subtracao.h"


int opcao;

int main() {
    printf("BEM VINDO A CALCULADOR:\n\n");
    printf("escolha a operação:\n");
    printf("[1]  +      [2]  -\n");
    printf("[3]  *      [4]  /\n");
    scanf("%d",&opcao);


    switch (opcao)
    {
    case 1: soma();
        break;
    
    case 2: subtracao();
        break;
    default: printf("Opção inválida\n");
    }


}