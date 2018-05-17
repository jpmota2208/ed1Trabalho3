void escreveLista(Pessoa *l){
     //Declarações
     FILE *p_arq;
     Pessoa *pessoa = l,*aux;
     //Instruções
     if ((p_arq=fopen("contatos.txt","w"))==NULL)
     {
         printf("Arquivo nao pode ser aberto.");
         system("pause");
     }
     else
     {
       while (pessoa != NULL) {
         fprintf(p_arq,"%s\n%s\n%s\n%d\n%s\n$\n",
         pessoa->nome,pessoa->telefone,pessoa->endereco,pessoa->cep,pessoa->dtNasc);
         aux = pessoa;
         pessoa = pessoa->prox;
         free(aux);
       }
     }
     fclose(p_arq);
}
