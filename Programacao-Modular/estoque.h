struct jogo {               // Estrutura jogo
	char nome[20];          //   Nome - 20 caracteres 
    int codigo;             //   codigo                        - int
	int disponibilidade;    //   disponibilidade ou quantidade - int
};typedef struct jogo Jogo; //

struct estoque{                   // Lista encadeada de jogos      
    Jogo dados;                   // 
    struct estoque* prox;         // 
};typedef struct estoque Estoque; //  