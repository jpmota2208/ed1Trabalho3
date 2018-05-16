void visualizaRegistro()
{
  //Declarações
  FILE *p_arq;
  char nome[MAX_CARACTER];
  Pessoa temp;
  int existe,pause;
  //Instruções
  if ((p_arq=fopen("contatos.txt","r"))==NULL)
  {
    limpaTela();
    printf("nao ha pessoas cadastradas\n\n\n\n");
  }
  else
  {
    existe = 0;
    printf("Informe o nome da pessoa desejada: ");
    limpaBuffer();
    fgets(nome,MAX_CARACTER,stdin);
    tiraTerminador(nome);
    trocaEspaco(nome);
    while(!feof(p_arq))
    {
       fscanf(p_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
       temp.nome,temp.telefone,temp.endereco,&temp.cep,temp.dtNasc);
       if(strcmp(nome,temp.nome) == 0)
       {
       	 existe = 1;
       	 limpaTela();
         mostraRegistro(&temp);
         printf("Digite um numero e de enter pra continuar\n");
         scanf("%d",&pause);
  	   }
    }
    if(!existe)
    {
       puts("Nao ha pessoas cadastradas com esse nome");
    }
    fclose(p_arq);
  }
}
