#include <stdio.h> // Biblioteca de comunicação com usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca que cuida das strings

int criacao() // Função que cadastra o usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//Criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o número do cpf a ser cadastrado:"); // Coleta das informações do usuário
	scanf("%s", cpf); // %s = string
	
	strcpy(arquivo, cpf); //Copiar os valores das strings
	
	FILE*file; //Criação do arquivo
	file = fopen(arquivo, "w"); //Criação do arquivo // "w" = write
	fprintf(file,cpf); //Salvar o valor da variável
	fclose(file); // Fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // Parar a tela
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //Leitura do arquivo // "r" = read
	
	if(file== NULL) // Condição
	{
		printf("Arquivo não localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // Laço de repetição
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	

}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser excluído: ");
	scanf("%s", cpf);
	
	remove(cpf); // Deletar variável
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("Usuário não encontrado!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	    system("cls"); // Limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
 	    printf("Login EBAC\n\n"); //Início do menu
	    printf("Menu de opções:\n\n"); 
	    printf("1 - Criar conta\n");
	    printf("2 - Consultar conta\n");
 	    printf("3 - Excluir conta\n\n");
		printf("4 - Sair do sistema\n\n"); //Fim do menu
	    printf("Selecione uma das opções:");
	
	    scanf("%d", &opcao); //Armazenamento da escolha do usuário
	
	    system("cls");
	
	switch(opcao) //Início da seleção
	{
		case 1:
		criacao(); // Chamada de funções
		break;
		
		case 2:
		consulta(); // Chamada de funções
		break;
		
		case 3:
		excluir(); // Chamada de funções
		break;
		
		case 4:
		printf("Obrigado! Por utilizar o sistema.");
		return 0;
		break;
		
		default:
		printf("Opção inexistente!\n");
		system("pause");
		break;
	} //Fim da seleção
	
	}

}
