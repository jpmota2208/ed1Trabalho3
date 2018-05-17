
Pessoa *insereEmOrdem(Pessoa *a, Pessoa *n) {
  Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
  Pessoa *aux = a;

  if(novo == NULL) {
    printf("nao foi possivel alocar memoria\n");
    return a;
  }

  strcpy(novo->nome,n->nome);
  strcpy(novo->telefone,n->telefone);
  strcpy(novo->endereco,n->endereco);
  novo->cep = n->cep;
  strcpy(novo->dtNasc,n->dtNasc);
  novo->prox = NULL;
  novo->ant = NULL;

  if(a == NULL)
    return novo;

  while (strcmp(novo->nome,aux->nome) > 0)
  {
    if (aux->prox == NULL)
    {
      aux->prox = novo;
      novo->ant = aux;
      novo->prox = NULL;
      return a;
    }
    aux = aux->prox;
  }

  if(aux->ant != NULL)
  {
    novo->prox = aux;
    novo->ant = aux->ant;
    (novo->ant)->prox = novo;
    (novo->prox)->ant = novo;
    return a;
  }
  else
  {
    aux->ant = novo;
    novo->prox = aux;
    novo->ant = NULL;
    a = novo;
    return a;
  }
}
