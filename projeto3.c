#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTER 101
typedef struct registro{
  char nome[MAX_CARACTER];
  char telefone[12];
  char endereco[MAX_CARACTER];
  unsigned int cep;
  char dtNasc[11];
  struct registro *ant,*prox;
} Pessoa;
void  limpaBuffer() {
  char lixo;

  do
  {
    scanf("%c",&lixo);
  }while (lixo != '\n');
}
#include "./funcoes/funcoes.h"

Pessoa *insereLista(Pessoa *l, Pessoa temp)
{
  Pessoa *registro = (Pessoa*)malloc(sizeof(Pessoa)*contatos);
  
}
Pessoa *carregaLista(Pessoa *lista, int contatos){
  //Declarações
  FILE *p_arq;
  Pessoa temp;
  Pessoa *contatos = (Pessoa*)malloc(sizeof(Pessoa)*contatos);
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
         l = insereLista(l,temp);
      }
      printf("Digite um numero e de enter pra continuar\n");
      scanf("%d",&pause);
      fclose(p_arq);
  }
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
      printf("Travou\n");
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
  int opcao,contatos = contaRegistros();

  Pessoa pessoa,*l = NULL;
  if (contatos != 0)
      l = carregaLista(l,contatos);
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
