#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTER 101

#include "./struct_registro.h"
#include "./funcoes/funcoes.h"

int main()
{
  int opcao;
  Pessoa *l = NULL;
  l = carregaLista(l);

  do
  {
    opcao = mostraMenu();
    limpaTela();
    switch(opcao)
    {
      case 1:
        insereRegistro(l);
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
