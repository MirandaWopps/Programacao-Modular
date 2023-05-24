#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "cliente.h"
//#include "reutilizavel.h"

FILE* abreArq(char* arqNome, char* mode) {
	FILE* arq = fopen(arqNome, mode);
	if (arq == NULL) {
		printf("Erro ao abrir o arquivo %s no modo %s !\n", arqNome, mode);
	}
	return arq;
}

void cadastraCliente(char* nome, int cpf) {
	FILE* file = abreArq("Cadastros Clientes.txt", "a");
	fprintf(file, "%s | %d \n", nome, cpf);

	fclose(file);
	printf("Dados guardados !\n");
	return;
}

int main(void) {

	// Testando cadastro
	cadastraCliente("Arnaldo", 123456789);

	printf("Bem vindo a nossa Locadora !:)\n");
	printf("    1. War\n");
	printf("    2. Combat\n");
	printf("    3. Clue\n");
	printf("    4. \n");
	printf("    5. \n");
	printf("    6. \n");
	printf("    7. \n");
	printf("    8. \n");
	printf("    9. \n");
	printf("    10. \n");




	return 0;
}