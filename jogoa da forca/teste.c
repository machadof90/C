#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Funções
int contarCaracteres(const char *str) {
    int contador = 0;
    while (str[contador] != '\0') {
        contador++;
    }
    return contador;
}

int posicaoLetra(const char *palavra, char letra) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] == letra) {
            return i;
        }
    }
    return -1;
}

// Variáveis globais
int opcao, posicao = 1;

typedef struct {
    char palavra[50];
    char dica[100];
    int item;
} Segredo;

Segredo enigma[100];

// Declaração das funções
void lista();
void cadastrar();
void jogar();
void jogo(int opcao);
void menu();
void banner();

int main() {
    menu();
    return 0;
}

void menu() {
    printf("Escolha a opcao:\n");
    printf("[1] Lista palavras\n");
    printf("[2] Cadastrar nova palavra\n");
    printf("[3] Vamos jogar\n");
    scanf("%d", &opcao);
    while (opcao > 3 || opcao < 1) {
        printf("Opcao invalida, digite novamente:\n");
        scanf("%d", &opcao);
    }
    switch (opcao) {
        case 1: lista();
            break;
        case 2: cadastrar();
            break;
        case 3: jogar();
            break;
    }
}

void cadastrar() {
    opcao = 0;
    int encontrado = 0;
    char entrada_palavra[50];
    char entrada_dica[100];
    printf("Digite a palavra:\n");
    scanf("%s", entrada_palavra);
    printf("Me fale uma dica:\n");
    scanf(" %[^\n]", entrada_dica); // Lê até a nova linha

    printf("Confirma a palavra %s com a dica %s?\n", entrada_palavra, entrada_dica);
    printf("[1] Sim\t");
    printf("[2] Nao\n");
    scanf("%d", &opcao);
    while (opcao > 2 || opcao < 1) {
        printf("Opcao invalida, digite novamente:\n");
        scanf("%d", &opcao);
    }
    if (opcao == 1) {
        for (int i = 0; i < posicao; i++) {
            if (strcmp(entrada_palavra, enigma[i].palavra) == 0) {
                encontrado = 1;
                break;
            }
        }
        if (encontrado) {
            printf("Palavra ja cadastrada\n");
            Sleep(2000);
            menu();
        } else {
            strcpy(enigma[posicao].palavra, entrada_palavra);
            strcpy(enigma[posicao].dica, entrada_dica);
            enigma[posicao].item = posicao;
            posicao++;
            system("cls");
            printf("Palavra cadastrada com sucesso\n");
            Sleep(2000);
            menu();
        }
    } else {
        system("cls");
        menu();
    }
}

void lista() {
    printf("Item\tPalavra\t\tDica\t\t\t\t\n");
    for (int i = 1; i < posicao; i++) {
        printf("%d\t%s\t\t%s\n", enigma[i].item, enigma[i].palavra, enigma[i].dica);
    }
    printf("Aperte qualquer tecla para voltar ao menu\n");
    getch();
    system("cls");
    menu();
}

void jogar() {
    opcao = 0;
    system("cls");
    banner();
    printf("Qual o numero da palavra secreta?\n");
    scanf("%d", &opcao);
    while (opcao < 1 || opcao >= posicao) {
        printf("Enigma nao existe, escolha outro numero:\n");
        scanf("%d", &opcao);
    }
    jogo(opcao);
}

void jogo(int opcao) {
    int acertos = 0;
    char letra;
    char segredo[50];
    int letras = contarCaracteres(enigma[opcao].palavra);
    for (int i = 0; i < letras; i++) {
        segredo[i] = '___  ';
    }
    segredo[letras] = '\0';

    printf("A PALAVRA TEM %d LETRAS\n", letras);
    while (acertos < letras) {
        printf("%s\n", segredo);
        printf("Digite uma letra:\t");
        scanf(" %c", &letra);

        int indice = posicaoLetra(enigma[opcao].palavra, letra);
        if (indice >= 0 && segredo[indice] == '_') {
            segredo[indice] = letra;
            acertos++;
            system("cls");
        } else {
            System("cls");
            printf("Errou!!! Tente outra letra\n");
            Sleep(1000);

        }
    }

    printf("Parabens! Você adivinhou a palavra: %s\n", segredo);
    Sleep(5000);
    menu();
}

void banner() {
    printf("HORA DA DIVERSAO!!!!!\n\n");
}
