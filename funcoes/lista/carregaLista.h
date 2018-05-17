
Pessoa *carregaLista(Pessoa *l){
  //Declarações
  FILE *p_arq;
  Pessoa temp;
  int pause;
  //Instruções

  if ((p_arq=fopen("contatos.txt","r"))==NULL)
  {
      return NULL;
  }
  else
  {
    while(!feof(p_arq))
    {
       fscanf(p_arq, "%s\n" ,temp.nome);
       fscanf(p_arq, "%s\n" ,temp.telefone);
       fscanf(p_arq, "%s\n" ,temp.endereco);
       fscanf(p_arq, "%u\n" ,&temp.cep);
       fscanf(p_arq, "%s\n$\n" ,temp.dtNasc);
       l = insereEmOrdem(l,&temp);
    }
    fclose(p_arq);
    return l;
  }
}
