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

  struct registro *ant;
  struct registro *prox;
} Pessoa;

void pausar(char *msg) {
  int i;
  printf("%s\ndigite um numero e aperte ENTER para continuar\n",msg);
  //scanf("%d", &i);
}

void limpaTela() {
  //s-ystem("clear");
}

#include "./funcoes/funcoes.h"


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
void listaRegistros(Pessoa *l)
{
    //Declarações
    Pessoa *pessoa = l;
    int pause;
    //Instruções
    int i = 0;
    printf("\n\n=========== lista de contatos =============\n\n");
    while (pessoa != NULL) {
      mostraRegistro(pessoa);
      pessoa = pessoa->prox;
    }
    printf("\n\n\nDigite um numero e de enter pra continuar\n");
    scanf("%d",&pause);
}
int main()
{
  int opcao;
  Pessoa *l = NULL;
  l = carregaLista(l);
  //printf("\nnone lido => %s\n", l->prox->nome);
  do
  {
    opcao = mostraMenu();
    limpaTela();
    switch(opcao)
    {
      case 1:
        insereRegistro(l);
        //ordenaRegistros();
        break;
      case 2:
        removeRegistro();
        break;
      case 3:
        visualizaRegistro();
        break;
      case 4:
        listaRegistros(l);
        break;
      case 0:
        escreveLista(l);
    }
  }while(opcao != 0);
  return 0;
}
