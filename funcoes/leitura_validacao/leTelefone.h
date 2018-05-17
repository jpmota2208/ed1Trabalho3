void leTelefone(char *telefone){
  int i, erro,numeros,tamanho;
  char telTemp[11];
  do
  {
    numeros = 0;
    erro = 0;
    printf("Telefone: ");
    fflush(stdin);
    fgets(telTemp,11,stdin);
    tiraTerminador(telTemp);
    if(strlen(telTemp) < 9)
    {
      printf("Insira um numero valido(9 digitos)\n");
      erro = 1;
    }
    else
    {
      for(i = 0; i < strlen(telTemp);i++)
      {
        if (telTemp[i] >= '0' && telTemp[i] <= '9')
          numeros++;
      }
      if(numeros < 9)
      {
        printf("Informe apenas numeros\n");
        erro = 1;
      }
      else
      {
         for(i = 0;i < 10;i++)
         {
           if(i < 5)
            telefone[i] = telTemp[i];
           if(i > 5)
            telefone[i] = telTemp[i-1];
         }
         telefone[5] = '-';
         telefone[11] = '\n';
      }
    }
  }while(erro == 1);
}
