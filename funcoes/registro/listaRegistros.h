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
