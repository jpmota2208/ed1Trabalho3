
Pessoa *carregaLista(Pessoa *l){
  //Declarações
  FILE *p_arq;
  Pessoa temp;
  int pause;
  //Instruções
  if ((p_arq=fopen("contatos.txt","r"))==NULL)
  {
      system("clear");
      printf("nao ha pessoas cadastradas\n\n\n\n");
  }
  else
  {
      while(!feof(p_arq))
      {
         fscanf(p_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
         temp.nome,temp.telefone,temp.endereco,&temp.cep,temp.dtNasc);
         l = alocaEmOrdem(l,&temp);
      }
      fclose(p_arq);
  }
}
