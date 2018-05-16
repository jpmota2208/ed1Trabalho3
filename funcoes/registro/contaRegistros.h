int contaRegistros()
{
  FILE *p_arq;
  Pessoa temp;
  int registros = 0;
  //Instruções
  if ((p_arq=fopen("contatos.txt","r"))==NULL)
  {
      printf("Arquivo nao pode ser aberto.");
      system("pause");
  }
  else
  {
    while(!feof(p_arq))
    {
       fscanf(p_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
       temp.nome,temp.telefone,temp.endereco,&temp.cep,temp.dtNasc);
       registros++;
    }
  }
  return registros;
}
