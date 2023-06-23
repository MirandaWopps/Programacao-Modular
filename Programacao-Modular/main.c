#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "reutilizavel.h"
#include "financas.h"
//#include "estoque.h"

typedef struct jogo Jogo;
struct jogo {
	char nome[20];
	int disponibilidade;
};


int main(void) {
	// variaveis quando cadastra cliente for ser utilizado
	char cadastraNome[40], endereco[80], cpf[12], celular[16];
	int opcaoInterface = 0;
	float testaFinancas=0;


	printf("Bem vindo a Locadora !\n"); // Introducao
	printf("");
	//testaFinancas = consultaValor();
	editaValor(0);
	//cadastraCliente("Lucas", "12345678991", "+5521974328709", "Rua X");

	return 0;
}



	/*
	printf("%d\n", strlen(valtest) );
	printf("conta digitos %d\n", contaDigitos(valtest2));
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

	*/

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
	

	return 0;
}


*/