#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"
//#include "reutilizavel.h"

// Funcao auxiliar de criaNo, e usada para preencher a struct Jogo dado
Jogo preencheDado(char* nome, int codigo, int qntd){
	Jogo novoDado;
	strcpy(novoDado.nome, nome);
	novoDado.codigo = codigo;
	novoDado.disponibilidade = qntd;

	return novoDado;
}

// Funcao para criar um novo no
Estoque* criaNo(Jogo dado){
	Estoque* novo = (Estoque*) malloc(sizeof(Estoque));
	novo->dados = dado;
	novo->prox = NULL;

	return novo;
}

// Insere um no no inicio da lista
void insereNo(Estoque** lista, Jogo dado){
	Estoque* novoNo = criaNo(dado);
	novoNo->prox = *lista;
	*lista = novoNo;
}

// Imprime o estoque
void imprimeEstoque(Estoque* lista){
	Estoque* aux = lista;
	printf("==== Estoque ====\n");
	while (aux != NULL) {
        printf("Codigo: %d - Nome: %s - Disponibilidade: %d\n", aux->dados.codigo, aux->dados.nome, aux->dados.disponibilidade);
        aux = aux->prox;
    }
}
/*
int main(){
	Estoque* lista = NULL;
	Jogo dado;
	
	dado = preencheDado("Teste", 1, 2);
	insereNo(&lista, dado);
	dado = preencheDado("Teste2", 2, 0);
	insereNo(&lista, dado);
	imprimeEstoque(lista);


	return 0;
}




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