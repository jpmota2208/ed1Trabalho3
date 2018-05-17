void visualizaRegistro(Pessoa *l)
{
  //Declarações
  char nome[MAX_CARACTER];
  Pessoa *aux = l;
  //Instruções
  if (l == NULL) {
    printf("\nNinguem cadastrado!\n");
  } else {
    printf("Informe o nome da pessoa que quer pesquisar: ");
    limpaBuffer();
    fgets(nome,MAX_CARACTER,stdin);
    tiraTerminador(nome);
    trocaEspaco(nome);

    while(aux != NULL) {
      if (strcmp(nome,aux->nome) == 0) {
        printf("\nPessoa encontrada:\n==================\n");
        mostraRegistro(aux);
        printf("\n");
        pausar("");
        break;
      }
      aux = aux->prox;
    }
    pausar("Nao ha pessoas cadastradas com esse nome");
  }
}
