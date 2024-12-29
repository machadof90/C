#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//funcooes
int contarCaracteres(const char *str) {
        int contador = 0;
        while (str[contador] != '\0') {
            contador++;
        } 

    return contador;
}
int posicaoletra(const char *palavra, char letra){
    int i = 0;
    while (palavra[i] != '\0'){
        if(palavra[i] == letra){
            return i;
        }
        i++;
    }
    return -1;    
}

//variaveis
int opcao, posicao = 1;

struct segredo {
	char palavra[50];
	char dica[100];
	int item;
};
struct segredo enigma[100];

//void
void lista();
void cadastrar();
void jogar();
void jogo();
void menu();
void banner();// banner do jogo

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
    int i = 0, encontrado = 0;
    int indice = posicao;
	char entrada_palavra[50]; 
    char entrada_dica[100]; 
    printf("Digite a palavra:\n"); 
    scanf("%s", entrada_palavra); 
    printf("Me fale uma dica:\n"); 
    scanf(" %[^\n]", entrada_dica); // Lê até a nova linha//
    printf("Confirma a palavra %s com a dica %s?\n", entrada_palavra, entrada_dica);
    printf("[1]Sim\t");
    printf("[2]Nao\n");
    scanf("%d", &opcao);
    while(opcao > 2 || opcao < 1){
        printf("Opcao invalida, digite novamente:\n");
        scanf("%d", &opcao);
    }
    switch (opcao){
    case 1: 
     do {
        if(entrada_palavra == enigma[i].palavra){
            encontrado = 1;
        }
        indice++;
    }while ( i < indice);
    if (encontrado == 1) { 
        printf("Palavra ja cadastrada\n"); 
        Sleep(2000); 
        menu(); 
        }else{
            strcpy(enigma[posicao].palavra, entrada_palavra);
            strcpy(enigma[posicao].dica, entrada_dica);
            enigma[posicao].item = posicao;
            posicao++;
            system("cls");
            printf("Palavra cadastrada com sucesso\n");
            Sleep(2000);
        main();
        }  
    case 2: 
        system("cls");  
        menu();
        break; 
}
}

void lista()
{
	printf("Item\tPalavra\t\tDica\t\t\t\t\n");
    for(int i = 1; i < posicao; i++){
        printf("%d\t%s\t\t%s\n", enigma[i].item, enigma[i].palavra, enigma[i].dica);
    }
    printf("aperter qualquer tecla para voltar ao menu\n");
    getch();
    system("cls");
    main();	
}
void jogar()
{
	opcao = 0;
    system("cls");
    banner();
    printf("qual o numero da palavra secreta?\n");
    scanf("%d", &opcao);
    printf("%d,%d", opcao, posicao);
    while (opcao < 1 || opcao > posicao){
        printf("enigma nao existe, escolha outro numero:\n");
        scanf("%d", &opcao);
    } 
   jogo(opcao);
}
void jogo(int opcao){
    int acerto = 0;
    char letra[1];
    char segredo[50];
    char vazio[10] = "<<>>";
    int letras = contarCaracteres(enigma[opcao].palavra);
    for(int i = 1; i < letras; i++){
        segredo[i] = '___  ';
    }
    }
    printf("A PALAVRA TEM %d LETRAS\n",letras);
    for(int i = 1; i < letras; i++){
        printf("%c", segredo[i]);
    }
    printf("Digite a letra:\t");
    scanf("%d", &letra);    
    int indice = posicaoletra(enigma[posicao].palavra, letra);
    while (acerto < letras) {
        if (indice >= 0){
            strcpy(segredo[indice], letra);
            system("cls");
            for(int i = 1; i < letras; i++){
            printf("%c", segredo[i]);
            printf("outra letra:\n");
            acerto++;
            }
        }else{
            printf("\nerrou!!!, outra letra\n");
            }
        scanf("%d", &letra); 
    }
}
void banner()
{
     printf("HORA DA DIVERSÃO!!!!!\n\n");
}