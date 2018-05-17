//Alunos: Fabiana Luiza Vasconcelos Pfeilsticker Ribas
//        Joao Pedro Mota Jardim
//        Marcelo Araujo dos Santos

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
        removeRegistro(l);
        break;
      case 3:
        visualizaRegistro(l);
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
