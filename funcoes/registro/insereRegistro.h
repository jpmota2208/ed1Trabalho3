
Pessoa *insereRegistro(Pessoa *l){
   //Declarações
   Pessoa pessoa;
   //Instruções
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

   limpaBuffer();
   leData(pessoa.dtNasc);

   limpaTela();
   mostraRegistro(&pessoa);

   l = insereEmOrdem(l,&pessoa);
   pausar("");
   return l;
}
