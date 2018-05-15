#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tiraTerminador(char *texto) {
	if(texto[strlen(texto)-1] == '\n')
		texto[strlen(texto)-1] = '\0';
}

void  limpaBuffer() {
  char lixo;
  do{
    scanf("%c",&lixo);
  }while (lixo != '\n');
}

#include "./funcoes/leData.h"

int main() {

  char data[11];

  leData(data);


  printf("\n\nvoce digitou %s\nfinalizando programa!\n", data);







  return 0;
}
