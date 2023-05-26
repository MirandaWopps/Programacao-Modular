#include <stdio.h>
#include "reutilizavel.h"

/* Funcao dedicada a lidar com arquivos com tratamento de erros incluso. */

/* Assertivas de entrada 
     - Lidar com determinado arquivo e seu modo de abertura.
   Assertivas de saida 
     - o programa aborta com saída -1.
	 - O retorna arquivo aberto no modo escolhido. 
*/


FILE* abreArq(char* arqNome, char* mode) { // Parametro 'arqNome' recebe o nome do arquivo e 'mode' o modo de acesso, isto e, leitura, escrita, append ...
	FILE* arq = fopen(arqNome, mode); // A variavel arq recebe o arquivo aberto pelo comando fopen conforme os parametros da funcao.
	if (arq == NULL) { // Se a variavel for NULL a funcao nao conseguiu adquirir tudo que precisava.
		printf("Erro ao abrir o arquivo %s no modo %s !\n", arqNome, mode);
		exit(-1); // Arquivo nao encontrado  
	}
	return arq;   // Retorna parametro
}


// Interface com o usuário:  "Erro ao abrir o arquivo %s no modo %s !\n"  NOME DE ARQUIVO, OU MODO, OU PERMISSAO DE EDICAO/LEITURA PROVOCANDO ERRO