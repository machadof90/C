#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

// funcões

//variaveis globais
char tarefa[100], informacao;
int indice, opcao, cont = 1;

// voids
void banner();
void menu();
void listar();
void cadastrar();
void excluir();

//inicio
int main(){
 banner();
 menu();

 return 0;
}

void banner(){
    printf("LISTA DE TAREFAS\n\n");
}
void menu(){
 system("cls");
 banner();
 printf("Escolha a opcao:\n");
 printf("[1] Lista tarefas\n");
 printf("[2] Cadastrar tarafa\n");
 printf("[3] Excluir tarefa\n");
 scanf("%d", &opcao);
 while (opcao > 3 || opcao < 1) {
    printf("Opcao invalida, digite novamente:\n");
    scanf("%d", &opcao);
 }
    switch (opcao) {
        case 1: listar();
            break;
        case 2: cadastrar();
            break;
        case 3: excluir();
            break;
    }
}
void listar(){
 system("cls");
 banner();
 printf("Nº  TAREFA\n");
 for(int i = 1; i < indice; i++){
 printf("[%d] %c", indice, tarefa[indice]);
 }
 printf("Aperte qualquer tecla para voltar ao menu\n");
 getch();
 system("cls");
 menu();
}
void cadastrar(){
 system("cls");
 printf("Informe a tarefa:\n");
 scanf(" %[^\n]", &informacao);
 printf("Salvar tarefa?\n");
    printf("[1]Sim\t");
    printf("[2]Nao\n");
    scanf("%d", &opcao);
    while(opcao > 2 || opcao < 1){
        printf("Opcao invalida, digite novamente:\n");
        scanf("%d", &opcao);
    }
if (opcao = 1){
    strcpy(tarefa[indice], informacao);
    indice++;
    system("cls");
    printf("Tarefa foi salva com sucesso.\nAperte qualquer tecla para voltar ao MENU:\n");

    getchar();
    menu();
    } else { 
        system("cls");
        printf("Cadastra cancelado, retornando ao MENU");
        Sleep(1500);
        menu();
    }

}
void excluir(){

}
