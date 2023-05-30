#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
//#include "reutilizavel.h"
//#include "estoque.h"

#include "reutilizavel.h"

typedef struct jogo Jogo;
struct jogo {
	char nome[20];
	int disponibilidade;
};


// Nome/Objetivo: void controlaAluguel
// Requsitos: Receber 
// Assertivas de acoplamento: 
//    Entrada -
//    Saida - 
// Acoplamento: nomeJogo recebe o nome do jogo que o estoque agira em cima || ato recebe 'a' de aluguel ou 'd' de devolucao para operacao logica no estoque.
// Interface com  o usuario:  

/*
void controlaAlguel(char* nomeJogo , char ato) {

	Jogo* jogoQuery = (Jogo*)malloc( sizeof(Jogo) ); // um ponteiro para rodar o arquivo.
	FILE* tempSearch;
	switch (ato)
	{
	case 'a':

	case 'd':
		tempSearch = abreArq("" , "w");

	default: 

		break;
	}

	
	if ( strcmp(nomeJogo,jogoQuery->nome) == 0  ){}
		if (Jogo->disponibilidade == 0) {


		}
		antigo asterisico/


		free(jogoQuery);// libera memoria do search
}

*/


int main(void) {
	// variaveis quando cadastra cliente for ser utilizado
	char cadastraNome[40], endereco[80];
	int cpf, celular;
	int opcaoInterface = 0;
	char valtest[11] = "1234567890";

	
	printf("%d\n", strlen(valtest) );
	// Testando cadastro
	printf("Bem vindo a nossa Locadora !:)\n"); // tst
	printf("  - O que desejas ? \n");
	printf("    1. Cadastrar cliente.\n");
	printf("    2. Modificar estoque.\n");
	printf("    3. Sair. \n");
	scanf("%d", &opcaoInterface);

	switch(opcaoInterface) {
		case 1:
			printf("\n   -  Cadastrando cliente...\n");
			printf("   Qual nome do cliente ?\n");
			scanf("%s", cadastraNome);
			printf("   Qual cpf do cliente ?\n");
			scanf("%d", &cpf);
			printf("	Qual celular do cliente ?\n");
			scanf("%d", &celular);
			printf("	Qual endereco do cliente ?\n");
			scanf("%s", endereco);

			cadastraCliente(cadastraNome, cpf, celular, endereco);
			printf("\n     /\n");
			printf("   \\/ Cliente cadastrado com sucesso !\n"); 


		default:
			printf("Opção invalida.");
			break;
			
	}



	/*
	printf(" - Jogos disponíveis :\n");
	printf("    1. War\n");
	printf("    2. Combat\n");
	printf("    3. Clue\n");
	printf("    4. Damas\n");
	printf("    5. Xadrez\n");
	printf("    6. Gamão\n");
	printf("    7. Trilha\n");
	printf("    8. Ludo \n");
	printf("    9. Monopoly\n");
	printf("    10. Carcassonne\n");
	printf("    11. Catan\n");
	printf("    12. Go\n");
	printf("    13. Battle for Rokugan\n");
	printf("    14. Majong\n");
	printf("    15. Shogi\n");
	*/

	return 0;
}