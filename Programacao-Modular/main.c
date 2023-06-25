#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "reutilizavel.h"
#include "financas.h"
#include "estoque.h"

int main(void) {
	// variaveis quando cadastra cliente for ser utilizado
	int opcaoInterface = 0;
	float testaFinancas=0;
	//char* nomeArquivo = "estoque.json";
	Estoque* lista = leArquivoJSON("estoque.json");

	int opcaoMenu = -10; // variavel para menu
	// variaveis para alterar estoque
	// Interface	
	while (1) { // Loop
		printf("Menu - Bem vindo a Locadora !\n");
		printf("  1) Cadastrar Cliente\n");
		printf("  2) Alterar estoque\n");
		printf("  3) Exibir estoque\n");
		printf("  4) Registrar aluguel\n");
		printf("  5) Sair\n\n");

		// Manutenciador de eventos
		scanf("%d", &opcaoMenu);// Seleciona opcao
		switch (opcaoMenu) {
		case 1:
			printf("  ==> 1 - CADASTRAR CLIENTE\n");
			cadastraCliente();
			printf("\n     /\n");
			printf("   \\/ Cliente cadastrado com sucesso !\n");
			break;
		case 2:
			printf("  ==> 2 - ALTERAR ESTOQUE\n");
			alteraEstoque(lista);

			break;
		case 3:
			//printf("  ==> 2 - ALTERAR ESTOQUE\n");
			imprimeEstoque(lista);

			break;
		case 4:
			printf("  ==> 3 - REGISTRO DE ALUGUEL\n");
			registraAluguel(lista);
			break;

		case 5:
			printf("   Saindo.");
			estoqueJson(lista);
			exit(1);
			break;
		default:
			break;
		}
	}


	return 0;
}