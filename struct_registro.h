
typedef struct registro{
  char nome[MAX_CARACTER];
  char telefone[12];
  char endereco[MAX_CARACTER];
  unsigned int cep;
  char dtNasc[11];

  struct registro *ant;
  struct registro *prox;
} Pessoa;
