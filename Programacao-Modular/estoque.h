#include <conio.h>
struct jogo {               // Estrutura jogo
	char nome[20];          //   Nome - 20 caracteres 
    int codigo;             //   codigo                        - int
	int disponibilidade;    //   disponibilidade ou quantidade - int
    float preco;
};typedef struct jogo Jogo; //

struct estoque{
    Jogo dados;
    struct estoque* prox;
};typedef struct estoque Estoque;

Jogo preencheDado(char* nome, int codigo, int qntd);
Estoque* criaNo(Jogo dado);
void insereNo(Estoque** lista, Jogo dado);
void imprimeEstoque(Estoque* lista);
void registraAluguel(char* cpf, int dias, char* nomeJogo);
