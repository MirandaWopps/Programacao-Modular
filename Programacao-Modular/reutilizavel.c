#include <stdio.h>
#include "reutilizavel.h"

/* abreArq: Funcao dedicada a lidar com arquivos com tratamento de erros incluso. */

/* Requisitos 
	- Abrir um arquivo em algum modo da linguagem C.
* /

/* Assertivas de entrada 
     - Lidar com determinado arquivo e seu modo de abertura.
   Assertivas de saida 
     - o programa aborta com saída -1.
	 - O retorna arquivo aberto no modo escolhido. 
*/

// Interface com o usuário:  "Erro ao abrir o arquivo  <NOME DE ARQUIVO> no modo  <MODO DE ABERTURA>  ! Parametro 'nome' nulo.\n"

FILE* abreArq(char* arqNome, char* mode) { // Parametro 'arqNome' recebe o nome do arquivo e 'mode' o modo de acesso, isto e, leitura, escrita, append ...
	FILE* arq = fopen(arqNome, mode); // A variavel arq recebe o arquivo aberto pelo comando fopen conforme os parametros da funcao.
	if (arq == NULL) { // Se a variavel for NULL a funcao nao conseguiu adquirir tudo que precisava.
		printf("Erro ao abrir o arquivo %s no modo %s ! Parametro 'nome' nulo.\n", arqNome, mode);
		exit(-1); // Encerra programa.
	}
	return arq;   // Retorna parametro
}
