#include <stdio.h>
#include <stdlib.h>
int opcao, posicao = 0;

struct segredo {
	char palavra[50];
	char dica[100];
	int item;
};
struct segredo enigma[];

void lista();
void cadastrar();
void jogar();
void menu();

int main()
{
	printf(".");
	menu();
	
return 0;	
}

void menu(){
	printf("Escolha a opcao:\n");
	printf("[1]Lista palavras\n");
	printf("[2]Cadastra nova palavra\n");
	printf("[3]Vamos jogar\n");
	scanf("%d", &opcao);
	while(opcao > 3 || opcao < 1){
		printf("Opcao invalida, digite novamente:\n");
		scanf("%d", &opcao);
	}
	switch(opcao){
	case 1: lista();
		break;
	case 2: cadastrar();
		break;
	case 3: jogar();
		break;
	}
}
void cadastrar()
{
	opcao = 0;
	char entrada_palavra[50]; 
    char entrada_dica[100]; 
    printf("Digite a palavra:\n"); 
    scanf("%s", entrada_palavra); 
    printf("Me fale uma dica:\n"); 
    scanf(" %[^\n]", entrada_dica); // Lê até a nova linha//
}
void lista()
{
	printf("2\n");	
}
void jogar()
{
	printf("3\n");	
}