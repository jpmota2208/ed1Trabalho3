

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
         system("clear");
         mostraRegistro(&pessoa);
         printf("\n\npause: \n");
         int oi;
         scanf("%d\n", &oi);

         l = alocaEmOrdem(l,&pessoa);
         //fprintf(p_arq,"%s\n%s\n%s\n%d\n%s\n$\n",
         //pessoa->nome,pessoa->telefone,pessoa->endereco,pessoa->cep,pessoa->dtNasc);
         /*for(i = 0; i < strlen(pessoa->nome);i++){
           if(pessoa->nome[i] != '_')
            fprintf(p_arq,"%c",pessoa->nome[i]);
           else
            fprintf(p_arq," ");
         }
         */
     }
     fclose(p_arq);
}
