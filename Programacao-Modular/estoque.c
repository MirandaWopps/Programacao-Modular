#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"
#include "cJSON.h"
//#include "reutilizavel.h"

/*
	Compilacao: gcc -o "nome_executavel" "nome_arquivo.c" cJSON/cJSON.c -IcJSON -LcJSON -lcjson
	
	Coisas que faltam:
		- Criar um editor de no da lista encadeada, onde passo codigo e ele pergunta o que tem que ser editado
*/

// Funcao auxiliar para criar um novo nó
Estoque* criaNo(Jogo dado) {
    Estoque* novo = (Estoque*)malloc(sizeof(Estoque));
    novo->dados = dado;
    novo->prox = NULL;

    return novo;
}

// Insere um nó no início da lista
void insereNo(Estoque** lista, Jogo dado) {
    Estoque* novoNo = criaNo(dado);
    novoNo->prox = *lista;
    *lista = novoNo;
}

// Lê o arquivo JSON e cria a lista encadeada 
Estoque* leArquivoJSON(char* nomeArquivo) {
	// ========= Tratamento do arquivo =========

	// Realiza a abertura do arquivo
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

	// Pega o tamanho do arquivo indo com o ponteiro ate o final usando seek
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
	// Volta o ponteiro para o inicio do arquivo
    fseek(arquivo, 0, SEEK_SET);

	// Realiza um malloc para conteudoArquivo, onde vai ser salvo o arquivo todo json
    char* conteudoArquivo = (char*)malloc(tamanhoArquivo + 1);
	// Faz a leitura o arquivo Json e salva em conteudoJson
    fread(conteudoArquivo, 1, tamanhoArquivo, arquivo);
	// Coloca um '\0' para finalizar a string
    conteudoArquivo[tamanhoArquivo] = '\0';

    fclose(arquivo);

	// ========= Inclusao na lista encadeada =========

	// Retorna a estrutura de dados do Json e atribui em listaJson
    cJSON* listaJson = cJSON_Parse(conteudoArquivo);
    if (listaJson == NULL) {
        printf("Erro ao fazer o parsing do JSON.\n");
        free(conteudoArquivo);
        return NULL;
    }

    Estoque* lista = NULL;
    cJSON* noJson = NULL;

    cJSON_ArrayForEach(noJson, listaJson) {
		// Pega os elementos para serem adicionados e coloca em um auxiliar
        cJSON* nomeJson = cJSON_GetObjectItem(noJson, "nome");
        cJSON* codigoJson = cJSON_GetObjectItem(noJson, "codigo");
        cJSON* dispJson = cJSON_GetObjectItem(noJson, "disponibilidade");

        if (nomeJson && codigoJson && dispJson) {
			// atribui os elementos na struct jogo
            Jogo jogo;
			strcpy(jogo.nome, nomeJson->valuestring);
            jogo.codigo = codigoJson->valueint;
            jogo.disponibilidade = dispJson->valueint;

			// adiciona na lista encadeada, passando a struct preenchida
            insereNo(&lista, jogo);
        }
    }

	// deleta o json e da free no arquivo onde tem todo o texto json
    cJSON_Delete(listaJson);
    free(conteudoArquivo);

    return lista;
}

// Imprime o estoque
void imprimeEstoque(Estoque* lista) {
    Estoque* aux = lista;
    printf("==== Estoque ====\n");
    while (aux != NULL) {
        printf("Codigo: %d - Nome: %s - Disponibilidade: %d\n", aux->dados.codigo, aux->dados.nome, aux->dados.disponibilidade);
        aux = aux->prox;
    }
}

// Cria um arquivo json a partir de uma lista enca
void geraJson(char* texto, const char* caminho) {
    FILE* arq = fopen(caminho, "w");
    if (arq == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fputs(texto, arq);
    fclose(arq);

    printf("Arquivo JSON criado com sucesso: %s\n", caminho);
}

// Do estoque cria um arquivo em json
cJSON* estoqueJson(Estoque* lista) {
    cJSON* listaJson = cJSON_CreateArray();
    Estoque* aux = lista;

    while (aux != NULL) {
        cJSON* noJson = cJSON_CreateObject();
        cJSON_AddStringToObject(noJson, "nome", aux->dados.nome);
        cJSON_AddNumberToObject(noJson, "codigo", aux->dados.codigo);
        cJSON_AddNumberToObject(noJson, "disponibilidade", aux->dados.disponibilidade);
        cJSON_AddItemToArray(listaJson, noJson);
        aux = aux->prox;
    }

    return listaJson;
}

int main(){

	char* nomeArquivo = "estoque.json";
    

	Estoque* lista = leArquivoJSON(nomeArquivo);

	printf("Bem vindo a Locadora !\n"); // Introducao
	imprimeEstoque(lista);
	


	//Bloco para finalizar o programa e salvar o estoque
	cJSON* dadoJson = estoqueJson(lista);
    char* textoJson = cJSON_Print(dadoJson);
    //printf("JSON: %s\n", textoJson);
	geraJson(textoJson, "estoque.json");

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