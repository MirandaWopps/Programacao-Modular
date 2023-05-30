#include <stdio.h>
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

void cadastraCliente(char* nome, int cpf, int celular, char* endereco) { // Recebe no parametros 'nome', 'cpf', 'celular' e 'endereco', respectivamente, o nome, cpf, celular e endereco do cliente. 
	printf("%d", contaDigitos(cpf));
	if (contaDigitos(cpf) != 11) {
		printf("CPF requer 11 digitos !\n");
		exit(-1);
	}
	FILE* file = abreArq("Cadastros Clientes.txt", "a");
	fprintf(file, "%s | %d | %d | %s\n", nome, cpf, celular, endereco);

	fclose(file);
	printf("Dados guardados !\n");
	return ; 
}

// Interface com o usuario: "nome | cpf | celular | endereco"       "Dados guardados"      





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
