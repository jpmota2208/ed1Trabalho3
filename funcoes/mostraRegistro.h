void mostraRegistro (Pessoa *pessoa)
{
     //Instruções
     printf("Nome: %s\n",pessoa->nome);
     printf("Telefone: %s\n",pessoa->telefone);
     printf("Endereco: %s\n",pessoa->endereco);
     printf("CEP: %u\n",pessoa->cep);
     printf("Data de Nascimento: %s\n\n",pessoa->dtNasc);
}
