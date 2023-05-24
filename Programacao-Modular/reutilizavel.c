#include <stdio.h>
#include "reutilizavel.h"
FILE* abreArq(char* arqNome, char* mode) {
	FILE* arq = fopen(arqNome, mode);
	if (arq == NULL) {
		printf("Erro ao abrir o arquivo %s no modo %s !\n", arqNome, mode);
	}
	return arq;
}