
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
      //pausar("cacando bugs");
       //fscanf(p_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
       //temp.nome,temp.telefone,temp.endereco,&temp.cep,temp.dtNasc);
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
