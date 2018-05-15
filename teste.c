#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void tiraTerminador(char *texto)
{
	if(texto[strlen(texto)-1] == '\n')
		texto[strlen(texto)-1] = '\0';
}

void main(){
  int i, erro,compara;
  char telefone[11];
  do
  {
    erro = 0;
    printf("Telefone: ");
    fflush(stdin);
    fgets(telefone,11,stdin);
    tiraTerminador(telefone);
    printf("Como q esta sendo lido o telefone: %s\n",telefone);
    /*for(i = 0; i < strlen(telefone)-1;i++)
    {
      if(i != 5)
      {
        /*if(telefone[i] != '0' && telefone[i] != '1' && telefone[i] != '2'
        && telefone[i] != '3' && telefone[i] != '4' && telefone[i] != '5'
        && telefone[i] != '6' && telefone[i] != '7' && telefone[i] != '8'
        && telefone[i] != '9')
        {
          erro = 1;
        }
        compara = telefone[i];
        if (compara < 48 && compara > 57)
          erro = 1;
      }
    }*/
    if(telefone[5] != '-')
      erro = 1;
    if(erro = 1)
      printf("Informe no formato XXXXX-XXXX\n");
  }while(erro = 1);
}
