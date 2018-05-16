

void insereRegistro(Pessoa *l){
     //Declarações
     FILE *p_arq;
     Pessoa pessoa;
     //Instruções
     if ((p_arq=fopen("contatos.txt","a+"))==NULL)
     {
         printf("Arquivo nao pode ser aberto.");
         system("pause");
     }
     else
     {
         printf("Nome: ");
         limpaBuffer();
         fgets(pessoa.nome,MAX_CARACTER,stdin);
         tiraTerminador(pessoa.nome);
         trocaEspaco(pessoa.nome);
         leTelefone(pessoa.telefone);
         printf("Endereco: ");
         fflush(stdin);
         fgets(pessoa.endereco,MAX_CARACTER,stdin);
         tiraTerminador(pessoa.endereco);
         trocaEspaco(pessoa.endereco);
         printf("CEP: ");
         scanf("%u",&pessoa.cep);
         printf("Data de nascimento: ");
         limpaBuffer();
         fgets(pessoa.dtNasc,11,stdin);
         tiraTerminador(pessoa.dtNasc);
         trocaEspaco(pessoa.dtNasc);
         limpaTela();
         mostraRegistro(&pessoa);

         l = alocaEmOrdem(l,&pessoa);

     }
     fclose(p_arq);
}
