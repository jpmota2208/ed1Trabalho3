

Pessoa *alocaMemoria() {
  return (Pessoa*)malloc(sizeof(Pessoa));
}

// ====================================
int nulo(Pessoa *a) {
  return (a == NULL);
}
// ====================================

// ====================================
Pessoa *iniciaPessoa() {
  return NULL;
}

// ====================================
Pessoa *alocaEmOrdem(Pessoa *a, Pessoa *n) {
  Pessoa *novo = alocaMemoria();
  Pessoa *aux = a;
  int i = 0;

  if(nulo(novo)) {
    printf("nao foi possivel alocar memoria\n");
    return a;
  }

  strcpy(novo->nome,n->nome);
  strcpy(novo->telefone,n->telefone);
  strcpy(novo->endereco,n->endereco);
  novo->cep = n->cep;
  strcpy(novo->dtNasc,n->dtNasc);
  novo->prox = NULL; // aponta para nulo temporariamente
  novo->ant = NULL;

  if(nulo(a)) {
    //printf("Lista estah vazia, alocando item no comeco\n");
    return novo;
  }

  i = 0;
  while (strcmp(novo->nome,aux->nome) > 0) {
    //aux = aux->prox;

    if (nulo(aux->prox)) {
      //printf("valor dado fora do tamanho da Pessoa!\n");
      //printf("inserindo item no fim.\n");
      aux->prox = novo;
      novo->ant = aux;
      novo->prox = NULL;
      return a;
    }



    aux = aux->prox;
    // verif se chegou no fim
  }

  if(aux->ant != NULL)
  {
    if (strcmp(novo->nome, "joao") == 0) {
      printf("joao entrando depois do === %s\n", aux->ant->nome);
      i++;
    }
    novo->prox = aux;
    novo->ant = aux->ant;

    (novo->ant)->prox = novo;
    (novo->prox)->ant = novo;

    return a;
  }
  else
  {
    //pausar("aux anterior eh nulo");
    //printf("veja o nome :) => %s\n", novo->nome);
    aux->ant = novo;
    novo->prox = a;
    novo->ant = NULL;
    return novo;
  }

}

// ====================================
/*Pessoa *libera(Pessoa *a) {
  Pessoa *aux = a;

  while (!nulo(aux)) {
    aux = aux->prox;
    free(a);
    a = aux;
  }
  return NULL;
}*/
