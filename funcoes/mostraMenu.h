int mostraMenu(){
    int opcao;
    limpaTela();
    printf(">>>>>>> Menu <<<<<<<<<\n");
    printf("1 - Inserir novo registro\n");
    printf("2 - Remover registro\n");
    printf("3 - Visualizar registro individual\n");
    printf("4 - Visualizar registros\n");
    printf("0 - Sair\n");
    scanf("%d",&opcao);
    return opcao;
}
