#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARACTER 101
typedef struct registro{
  char nome[MAX_CARACTER];
  char telefone[11];
  char endereco[MAX_CARACTER];
  unsigned int cep;
  char dtNasc[11];
} Pessoa;

void  limpaBuffer() {
  char lixo;

  do
  {
    scanf("%c",&lixo);
  }while (lixo != '\n');
}

int mostraMenu(){
    int opcao;
    system("clear");
    printf(">>>>>>> Menu <<<<<<<<<\n");
    printf("1 - Inserir novo registro\n");
    printf("2 - Remover registro\n");
    printf("3 - Visualizar registro individual\n");
    printf("4 - Visualizar registros\n");
    printf("0 - Sair\n");
    scanf("%d",&opcao);
    return opcao;
}
void tiraTerminador(char *texto)
{

	if(texto[strlen(texto)-1] == '\n')
	{
		texto[strlen(texto)-1] = '\0';
	}
}
void trocaEspaco(char *texto){
  int i;
  for(i = 0; i < strlen(texto);i++)
  {
    if(texto[i] == ' ')
      texto[i] = '_';
  }
}
void insereRegistro(Pessoa *pessoa){
     //Declarações
     FILE *p_arq;
     //Instruções
     if ((p_arq=fopen("contatos.txt","a+"))==NULL)
     {
         printf("Arquivo nao pode ser aberto.");
         system("pause");
     }
     else
     {
         printf("Nome: ");
         limpaBuffer();
         fgets(pessoa->nome,MAX_CARACTER,stdin);
         tiraTerminador(pessoa->nome);
         trocaEspaco(pessoa->nome);
         printf("Telefone: ");
         fflush(stdin);
         fgets(pessoa->telefone,11,stdin);
         tiraTerminador(pessoa->telefone);
         trocaEspaco(pessoa->telefone);
         printf("Endereco: ");
         fflush(stdin);
         fgets(pessoa->endereco,MAX_CARACTER,stdin);
         tiraTerminador(pessoa->endereco);
         trocaEspaco(pessoa->endereco);
         printf("CEP: ");
         scanf("%u",&pessoa->cep);
         printf("Data de nascimento: ");
         limpaBuffer();
         fgets(pessoa->dtNasc,11,stdin);
         tiraTerminador(pessoa->dtNasc);
         trocaEspaco(pessoa->dtNasc);
         system("clear");
         fprintf(p_arq,"%s\n%s\n%s\n%d\n%s\n$\n",
         pessoa->nome,pessoa->telefone,pessoa->endereco,pessoa->cep,pessoa->dtNasc);
     }
     fclose(p_arq);
}
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
void ordenaRegistros(){
  FILE *p_arq;
  Pessoa temp;
  int registros = contaRegistros(),i = 0,j;
  Pessoa pessoas[registros];
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
      pessoas[i].nome,pessoas[i].telefone,pessoas[i].endereco,&pessoas[i].cep,pessoas[i].dtNasc);
      i++;
      printf("vc caiu no loop infinito\n");
    }
    fclose(p_arq);
    if ((p_arq=fopen("contatos.txt","w"))==NULL)
    {
        printf("Arquivo nao pode ser aberto.");
        system("pause");
    }
    else
    {
      for(i = 0;i < registros;i++)
      {
        j = i;
        while(j-1 >= 0)
        {
          while(strcmp(pessoas[j-1].nome,pessoas[j].nome) > 0)
          {
            temp = pessoas[j];
            pessoas[j] = pessoas[j-1];
            pessoas[j-1] = temp;
            j--;
          }
        }
      }
      for(i = 0;i < registros;i++)
      {
        fprintf(p_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
        pessoas[i].nome,pessoas[i].telefone,pessoas[i].endereco,pessoas[i].cep,pessoas[i].dtNasc);
      }
      fclose(p_arq);
    }
  }

}
void mostraRegistro (Pessoa *pessoa)
{
     //Instruções
     printf("Nome: %s\n",pessoa->nome);
     printf("Telefone: %s\n",pessoa->telefone);
     printf("Endereco: %s\n",pessoa->endereco);
     printf("CEP: %u\n",pessoa->cep);
     printf("Data de Nascimento: %s\n\n",pessoa->dtNasc);
}
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
        system("clear");
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
           	 system("clear");
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
void removeRegistro()
{
    //Declarações
    FILE *p_arq,*t_arq;
    char nome[MAX_CARACTER];
    Pessoa temp;
    int existe,pause;
    //Instruções
    if ((p_arq=fopen("contatos.txt","r"))==NULL)
    {
        system("clear");
        printf("nao ha pessoas cadastradas\n\n\n\n");
    }
    else
    {
        if ((t_arq= fopen("temp.txt","a+"))==NULL)
        {
            system("clear");
            printf("Erro ao abrir arquivo temporario\n\n\n\n");
        }
        else
        {
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
             else
               fprintf(t_arq,"%s\n%s\n%s\n%u\n%s\n$\n",
               temp.nome,temp.telefone,temp.endereco,temp.cep,temp.dtNasc);
          }
          if(!existe)
          {
             puts("Nao ha pessoas cadastradas com esse nome");
          }
          remove("contatos.txt");
          rename("temp.txt","contatos.txt");
          fclose(t_arq);
        }
        fclose(p_arq);
    }
}
void listaRegistros()
{
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
           mostraRegistro(&temp);
        }
        printf("Digite um numero e de enter pra continuar\n");
        scanf("%d",&pause);
        fclose(p_arq);
    }
}
int main()
{
  int opcao;
  Pessoa pessoa;

  do
  {
    opcao = mostraMenu();
    system("clear");
    switch(opcao)
    {
      case 1:
        insereRegistro(&pessoa);
        ordenaRegistros();
        break;
      case 2:
        removeRegistro();
        break;
      case 3:
        visualizaRegistro();
        break;
      case 4:
        listaRegistros();
        break;
      default:
        puts("Tchau");
    }
  }while(opcao != 0);
  return 0;
}
