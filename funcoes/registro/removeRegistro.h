void removeRegistro(Pessoa *l)
{
  //Declarações
  char nome[MAX_CARACTER];
  Pessoa *aux = l;
  //Instruções
  if (l == NULL) {
    printf("\nNinguem cadastrado!\n");
  } else {
    printf("Informe o nome da pessoa que quer remover: ");
    limpaBuffer();
    fgets(nome,MAX_CARACTER,stdin);
    tiraTerminador(nome);
    trocaEspaco(nome);

    while(aux != NULL) {
      if (strcmp(nome,aux->nome) == 0) {
        printf("Apagando pessoa %s...\n", nome);
        if (aux->ant == NULL) {
          l = l->prox;
          free(aux);
          l->ant = NULL;
        }
        pausar("");
        if (aux->prox == NULL) {
          aux = aux->ant;
          free(aux->prox);
          aux->prox = NULL;
        } else {
          (aux->ant)->prox = aux->prox;
          (aux->prox)->ant = aux->ant;
          free(aux);
        }
        break;
      }
      aux = aux->prox;
    }
    pausar("Nao ha pessoas cadastradas com esse nome!");
  }
}
