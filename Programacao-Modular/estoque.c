#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"
#include "cJSON.h"
#include "reutilizavel.h"

/*
	Compilacao: gcc -o "nome_executavel" "nome_arquivo.c" cJSON/cJSON.c -IcJSON -LcJSON -lcjson
	
	Coisas que faltam:
		- Criar um editor de no da lista encadeada, onde passo codigo e ele pergunta o que tem que ser editado
*/

/*  Nome: criaNo
    Objetivo: Funcao auxiliar para criar um novo nó
    Requisitos: 
	    Criar um estoque

    Assertivas de entrada 
     **********
    Assertivas de saida 
     - o programa aborta com saida -1.
*/
Estoque* criaNo(Jogo dado) {
    Estoque* novo = (Estoque*)malloc(sizeof(Estoque));
    if (novo == NULL) {
        printf ("Erro na alocacao de memoria da criaNo\n");
        exit (-1);
    } 
    novo->dados = dado;
    novo->prox = NULL;

    return novo;
}

/*  Nome: insereNo
    Objetivo: Insere um nó no início da lista encadeada

    Requisitos: 
	    Criar um estoque

    Assertivas de entrada 
     **********
    Assertivas de saida 
     **********
*/
void insereNo(Estoque** lista, Jogo dado) {
    Estoque* novoNo = criaNo(dado);
    novoNo->prox = *lista;
    *lista = novoNo;
}

/*  Nome: leArquivoJSON
    Objetivo: Lê o arquivo JSON e cria a lista encadeada 

    Requisitos: 
	*******

    Assertivas de entrada 
     **********
    Assertivas de saida 
     - o programa aborta com saida -1.
*/
Estoque* leArquivoJSON(char* nomeArquivo) {
	// ========= Tratamento do arquivo =========

	// Realiza a abertura do arquivo
    FILE* arquivo = abreArq(nomeArquivo, "r");

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
        exit(-1);
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

/*  Nome: imprimeEstoque
    Objetivo: Imprimir o estoque 

    Requisitos: 
	- Exibir o estoque.

    Assertivas de entrada 
     **********
    Assertivas de saida 
     - o programa aborta com saida -1.
*/
void imprimeEstoque(Estoque* lista) {
    if(lista == NULL){
        printf("Lista vazia\n");
        exit(-1);
    }
    Estoque* aux = lista;
    printf("==== Estoque ====\n");
    while (aux != NULL) {
        printf("Codigo: %d - Nome: %s - Disponibilidade: %d\n", aux->dados.codigo, aux->dados.nome, aux->dados.disponibilidade);
        aux = aux->prox;
    }
}
<<<<<<< HEAD
/*  Nome: geraJson
    Objetivo: Coloca um bloco de texto em um arquivo Json 

    Requisitos: 
	- *******.

    Assertivas de entrada 
     **********
    Assertivas de saida 
     - **********
*/

void geraJson(char* texto, char* caminho) {
    FILE* arq = abreArq(caminho, "w");

    fputs(texto, arq);
    fclose(arq);

    printf("Arquivo JSON criado com sucesso: %s\n", caminho);
}

/*  Nome: estoqueJson
    Objetivo: Transformar a lista encadeada em um arquivo Json

    Requisitos: 
	 ********

    Assertivas de entrada 
     **********
    Assertivas de saida 
     - o programa aborta com saida -1 e -2.
*/
void estoqueJson(Estoque* lista) {
    if(lista == NULL){
        printf("Lista vazia\n");
        exit(-1);
    }
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

    char* textoJson = cJSON_Print(listaJson);
    if(textoJson == NULL){
        printf("Erro na transformacao da lista em string (estoqueJson)\n");
        exit(-2);
    }
	geraJson(textoJson, "estoque.json");
}





Estoque* alteraEstoque(Estoque* lista){

    Jogo dado;
    int codigo;
    //printf("==== Estoque ====\n");
    imprimeEstoque(lista);

    printf("\nDigite o codigo do produto a ser alterado: ");
    scanf("%d", &codigo);
    //printf("\n%d", codigo);

    Estoque* aux = lista;
    for(int i = 0; aux != NULL; i++){
        if(aux->dados.codigo == codigo){
            printf("\n== Produto a ser alterado ==\n");
            printf("Nome: %s\nCodigo: %d\nDisponibilidade: %d\n", aux->dados.nome,aux->dados.codigo, aux->dados.disponibilidade);
            int x; 

            printf("\n== Alteracao ==");
            printf("\n1 - Nome\n2- Codigo\n3- Disponibilidade");
            printf("\nEscolha o campo a ser alterado: ");
            scanf("%d", &x);
            
            switch (x)
            {
                char auxNome[20];
            case 1:
                printf("Digite o novo nome: ");
                scanf(" %19[^\n]", auxNome);
                strcpy(aux->dados.nome, auxNome);
                printf("\nNome alterado\n");
                break;
            case 2:
                //printf("Altera Codigo\n");
                printf("Digite o valor do codigo: ");
                scanf("%d", &aux->dados.codigo);
                printf("\nCodigo alterado\n");
                break;
            case 3:
                printf("Digite o valor da disponibilidade: ");
                scanf("%d", &aux->dados.disponibilidade);
                printf("\nDisponibilidade alterada\n");
                break;
            
            default:
                break;
            }
            break;
        }
        aux = aux->prox;
    }
    

    return lista;
}


=======
/*
>>>>>>> 63c914ef94a368e6463b59d970a0792b606e5b85
int main(){

	char* nomeArquivo = "estoque.json";
    

	Estoque* lista = leArquivoJSON(nomeArquivo);

	printf("Bem vindo a Locadora !\n"); // Header
	//imprimeEstoque(lista);
    lista = alteraEstoque(lista);
	imprimeEstoque(lista);


	//Salva o estoque em um arquivo json
	estoqueJson(lista);

	return 0;
}

<<<<<<< HEAD
=======



>>>>>>> 63c914ef94a368e6463b59d970a0792b606e5b85
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