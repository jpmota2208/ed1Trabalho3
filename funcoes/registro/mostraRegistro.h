void printaString(char *string)
{
  char *letra;
  for (letra = string; *letra; letra++) {
    if(*letra == '_') printf(" ");
    else printf("%c", *letra);
  }
  printf("\n");
}

void mostraRegistro (Pessoa *pessoa)
{
  //Instruções
  printf("Nome: "); printaString(pessoa->nome);
  printf("Telefone: "); printaString(pessoa->telefone);
  printf("Endereco: "); printaString(pessoa->endereco);
  printf("CEP: %u\n",pessoa->cep);
  printf("Data de Nascimento: "); printaString(pessoa->dtNasc);
  printf("\n\n");
}
