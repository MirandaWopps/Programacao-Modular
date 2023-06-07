#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "reutilizavel.h"

/* Cadastra cliente */

/* Requisitos
	- Cadastrar um cliente em algum arquivo com os dados: nome, cpf, celular e endereco.
*/

/* Assertivas de entrada
	 - Lidar com os dados de um cliente.
   Assertivas de saida
	 - O programa aborta com saída -1.
	 - O programa nao retorna nada.
*/

void cadastraCliente(char* nome, char* cpf, char* celular, char* endereco) { // Recebe no parametros 'nome', 'cpf', 'celular' e 'endereco', respectivamente, o nome, cpf, celular e endereco do cliente. 
	if (strlen(cpf) != 11) {           // se cpf diferente de 11 digitos
		printf("CPF SEM 11 DIGITOS");
		exit(-1);
	}

	if (nome == "") {
		printf("NOME VAZIO");
		exit(-2);
	}

	if (celular == "") {
		printf("CELULAR VAZIO");
		exit(-3);
	}

	if (strlen(endereco) < 9) {
		printf("ENDERECO COM MENOS DE 9 DIGITOS");
		exit(-4);
	}

	FILE* file = abreArq("arquivo.txt", "a");
	fprintf(file, "%s | %s | %s | %s\n", nome, cpf, celular, endereco);

	fclose(file);
	printf("Dados guardados !\n");
	return;
}

// Interface com o usuario: "nome | cpf | celular | endereco"       "Dados guardados"       "CPF SEM 11 DIGITOS"


int alugaPeriodoCliente(int dias){
	char* escolha;
	if (dias== 1) {
		printf("Cliente escolheu usar por 1 dia na loja.");
	}
	else if (dias == 7){
		printf("Cliente escolheu alugar por 1 semana(7 dias).");
	}
	else {
		printf("ERRO ! Sistema nao indentificou se aluguel =  1 ou 7 dias.\n");
	}

	return 0;
}
