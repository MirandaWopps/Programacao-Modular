struct jogo {
	char nome[20];
    int codigo;
	int disponibilidade;
};typedef struct jogo Jogo;

struct estoque{
    Jogo dados;
    struct estoque* prox;
};typedef struct estoque Estoque;