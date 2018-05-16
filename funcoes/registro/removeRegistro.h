void removeRegistro()
{
  //Declarações
  FILE *p_arq,*t_arq;
  char nome[MAX_CARACTER];
  Pessoa temp;
  int existe,pause;
  //Instruções
  existe = 0;
  printf("Informe o nome da pessoa que quer remover: ");
  limpaBuffer();
  fgets(nome,MAX_CARACTER,stdin);
  tiraTerminador(nome);
  trocaEspaco(nome);
  while(!feof(p_arq))
  {
    fscanf(p_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
    temp.nome,temp.telefone,temp.endereco,&temp.cep,temp.dtNasc);
    if(strcmp(nome,temp.nome) == 0)
      existe = 1;
    else {
      fprintf(t_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
      temp.nome,temp.telefone,temp.endereco,temp.cep,temp.dtNasc);
    }
  }
  if(!existe)
     puts("Nao ha pessoas cadastradas com esse nome");
}
