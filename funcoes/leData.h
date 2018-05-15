

int dataValida(char *data) {
  int dia=0, mes=0, ano=0;
  static int chamadas = 0;
  char *letra;

  if (data[2] != '/' || data[5] != '/' ) {
    printf("\ninvalido! digite nesse formato (dd/mm/aaaa), ex: 01/07/1952\n");
    return 0;
  }

  data[2] = '0';
  data[5] = '0';

  for (letra = data; *letra; letra++) {
    if (*letra < '0' || *letra > '9') {
      printf("\ninvalido! digite apenas numeros! digite novamente: \n");
      return 0;
    }
  }

  //fflush(stdin);
  //limpaBuffer();
  data[2] = '/';
  data[5] = '/';

  chamadas++;
  return 1;
}

void leData(char *data)  {
  int i = 0;
  printf("Digite a data (dd/mm/aaaa)\nExemplos: 01/12/1998\t17/03/1988\n");
  do {

    //limpaBuffer();
    //fflush(stdin);
    //__fpurge(stdin);
    fgets(data,11,stdin);
    tiraTerminador(data);
    if(i) limpaBuffer();
    if (data[0] == '\0') {
      printf("ele eh \\0\n");
    }
    printf("\n#%d vc digitou {%s}\n",i, data );
    i++;
  } while(!dataValida(data));
}
