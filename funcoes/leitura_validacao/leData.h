

int dataValida(char *data) {
  int vData[] = {0, 0, 0}; // dia mes ano
  int i, tamanho = strlen(data);

  /*if (tamanho != 10) {
    printf("\ninvalido! digite nesse formato (dd/mm/aaaa), ex: 01/07/1952\n");
    return 0;
  }*/

  //data[2] = '1';
  //data[5] = '1';

  /*for ( i = 0; i < tamanho-1; i++) {
    if (data[i] < '0' || data[i] > '9' ) {
      printf("\ninvalido! digite apenas numeros .%c. i=%d\n",data[i],i);
      return 0;
    }
  }
  vData[0] = (int)(data[0]-'0')*10 + (int)(data[1]-'0');
  vData[1] = (int)(data[3]-'0')*10 + (int)(data[4]-'0');
  vData[2] = (int)(data[6]-'0')*1000 + (int)(data[7]-'0')*100 + (int)(data[8]-'0')*10 + (int)(data[9]-'0');

  if ((vData[0]*vData[1]*vData[2]) == 0) {
    printf("\ninvalido! digite valores maiores que zero\n");
    return 0;
  } else if (vData[0] > 31 || vData[1] > 12 || vData[2] > 2017 || vData[2] < 1901) {
    printf("\ninvalido! digite data valida\n");
    return 0;
  }
  data[2] = '/';
  data[5] = '/';
  */
  return 1;
}

void leData(char *data)  {
  printf("Digite a data (dd/mm/aaaa)\nExemplos: 01/12/1998\t17/03/1988\n");
  do {
    scanf("%s", data);
    tiraTerminador(data);
  } while(!dataValida(data));
}
