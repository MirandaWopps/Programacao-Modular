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
	int opcaoInterface = 0;
	float testaFinancas=0;


	int opcaoMenu = -10; // variavel para menu
	char cadastraNome[40], endereco[40], cpf[11]; int  celular;// variaveis para cadastrar cliente
	// variaveis para alterar estoque
	char nomeJogo[30]; int dias = 0;// variaveis para registrar aluguel

	// Interface
	while (opcaoMenu != 4) { // Loop
		printf("Menu - Bem vindo a Locadora !\n");
		printf("  1) Cadastrar Cliente\n");
		printf("  2) Alterar estoque\n");
		printf("  3) Registrar aluguel\n");
		printf("  4 ) Sair\n\n");

		// Manutenciador de eventos
		scanf("%d", &opcaoMenu);// Seleciona opcao
		switch (opcaoMenu) {
		case 1:
			printf("  ==> 1 - CADASTRAR CLIENTE\n");
			printf("     -  Cadastrando cliente...\n");
			printf("     Qual nome do cliente ?\n");
			scanf("%s", cadastraNome);
			printf("     Qual cpf do cliente ?\n");
			scanf("%s", cpf);
			printf("  	Qual celular do cliente ?\n");
			scanf("%d", &celular);
			printf("  	Qual endereco do cliente ?\n");
			scanf("%s", endereco);

			cadastraCliente(cadastraNome, cpf, celular, endereco);
			printf("\n     /\n");
			printf("   \\/ Cliente cadastrado com sucesso !\n");
			break;
		case 2:
			printf("  ==> 2 - ALTERAR ESTOQUE\n");


			break;
		case 3:
			printf("  ==> 3 - REGISTRO DE ALUGUEL\n");
			printf("     Qual cpf do cliente ?\n");
			scanf("%s", cpf);
			printf("     Quantos dias o alguel ?\n");
			scanf("%d", &dias);
			printf("  	Qual nome do jogo ?\n");
			scanf("%s", nomeJogo);

			registraAluguel(cpf, dias, nomeJogo);
			printf("\n     /\n");
			printf("   \\/ Aluguel registrado com sucesso !\n");
			break;

		case 4:
			printf("   Saindo.");
			break;
		default:
			break;
		}
	}


	return 0;
}