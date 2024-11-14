#include <stdio.h> // Biblioteca de comunica��o com usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca que cuida das strings

int criacao() // Fun��o que cadastra o usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	//Cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o n�mero do cpf a ser cadastrado:"); // Coleta das informa��es do usu�rio
	scanf("%s", cpf); // %s = string
	
	strcpy(arquivo, cpf); //Copiar os valores das strings
	
	FILE*file; //Cria��o do arquivo
	file = fopen(arquivo, "w"); //Cria��o do arquivo // "w" = write
	fprintf(file,cpf); //Salvar o valor da vari�vel
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
	
	if(file== NULL) // Condi��o
	{
		printf("Arquivo n�o localizado!");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // La�o de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	

}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser exclu�do: ");
	scanf("%s", cpf);
	
	remove(cpf); // Deletar vari�vel
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("Usu�rio n�o encontrado!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	    system("cls"); // Limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
 	    printf("Login EBAC\n\n"); //In�cio do menu
	    printf("Menu de op��es:\n\n"); 
	    printf("1 - Criar conta\n");
	    printf("2 - Consultar conta\n");
 	    printf("3 - Excluir conta\n\n");
		printf("4 - Sair do sistema\n\n"); //Fim do menu
	    printf("Selecione uma das op��es:");
	
	    scanf("%d", &opcao); //Armazenamento da escolha do usu�rio
	
	    system("cls");
	
	switch(opcao) //In�cio da sele��o
	{
		case 1:
		criacao(); // Chamada de fun��es
		break;
		
		case 2:
		consulta(); // Chamada de fun��es
		break;
		
		case 3:
		excluir(); // Chamada de fun��es
		break;
		
		case 4:
		printf("Obrigado! Por utilizar o sistema.");
		return 0;
		break;
		
		default:
		printf("Op��o inexistente!\n");
		system("pause");
		break;
	} //Fim da sele��o
	
	}

}
