#include <conio.h>
struct jogo {               // Estrutura jogo
	char nome[20];          //   Nome - 20 caracteres 
    int codigo;             //   codigo                        - int
	int disponibilidade;    //   disponibilidade ou quantidade - int
    float preco;
};typedef struct jogo Jogo; //

<<<<<<< HEAD
struct estoque{
    Jogo dados;
    struct estoque* prox;
};typedef struct estoque Estoque;

Jogo preencheDado(char* nome, int codigo, int qntd);
Estoque* criaNo(Jogo dado);
void insereNo(Estoque** lista, Jogo dado);
void imprimeEstoque(Estoque* lista);
=======
struct estoque{                   // Lista encadeada de jogos      
    Jogo dados;                   // 
    struct estoque* prox;         // 
};typedef struct estoque Estoque; // 

void registraAluguel(char* cpf, int dias, char* nomeJogo);
>>>>>>> Controle de aluguel pronto e função inútil no módulo cliente apagada.
