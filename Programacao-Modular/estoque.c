#include <stdio.h>
#include "estoque.h"
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