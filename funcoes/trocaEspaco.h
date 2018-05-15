void trocaEspaco(char *texto){
  int i;
  for(i = 0; i < strlen(texto);i++)
  {
    if(texto[i] == ' ')
      texto[i] = '_';
  }
}
