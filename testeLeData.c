#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tiraTerminador(char *texto) {
	if(texto[strlen(texto)] == '\n')
		texto[strlen(texto)] = '\0';
	if(texto[strlen(texto)-1] == '\n')
		texto[strlen(texto)-1] = '\0';
	if(texto[strlen(texto)-2] == '\n')
		texto[strlen(texto)-2] = '\0';
}
void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
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
