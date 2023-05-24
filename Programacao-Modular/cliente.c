#include <stdio.h>
#include "cliente.h"
#include "reutilizavel.h"


void cadastraCliente(char* nome, int cpf, int aluguel){
	FILE* file = abreArq("Cadastros Clientes.txt","a");
	fprintf(file, "%s | %d | Dias alugado: %d\n", nome, cpf, aluguel);

	fclose(file);
	printf("Dados guardados !\n");
	return ; 
}

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
