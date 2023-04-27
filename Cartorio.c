#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaõ em memória
#include <locale.h> // biblioteca de alocações de texto por região
// \t é para alinhar a frase/letra no centro
#include <string.h> //biblioteca responsãvel por cuidar das strings

int registro() // função responsável por cadastrar os usuários no sistema
{	
	// inicio criaação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criaação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado:  ");// coletando informações do usuário
	scanf("%s", cpf); // salvando em uma string
	
	strcpy(arquivo, cpf);// responsável por copiar os valores das strings, copiando do cpf para o arquivo
	
	// procedimento para criar um arquivo, abrir o arquivo, salvar dentro dele e fechar.
	FILE *file;// acessa o FILE e cria o arquivo file
	file = fopen(arquivo, "w");// criou o file e ele vai usar o f.open para abrir o arquivo, que é a variável arquivo neste caso. o w é de write( para escrever nele)
	fprintf(file, cpf);// um print f que salva dentro do arquivo. Salvando no file, a variável cpf
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // esse "a" agora é porque queremos atualizar a informação, em vez de criar uma nova
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;// abrindo o FILE e consultando dentro do file
	file = fopen(cpf, "r"); // neste caso o ele vai abrir o file e na variável cpf vai ler o que tem dentro(reading)
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");

	}
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto tiver escrevendo em conteudo, até 200 valores que estão dentro do arquivo, enquanto for diferente de nulo
	{
		printf("\n Essas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");

}								

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:  ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) 
	{	
		printf("Usuário não encontrado!\n");
		system("pause");
	}

}


int main()
{
	
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)// repetir quando o laço for 1 e enquanto o laço for 1
	{
		
	
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
		system("cls");
		printf("###Cartório da EBAC###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - REGISTRAR NOMES\n");
		printf("\t2 - CONSULTAR OS NOMES\n");
		printf("\t3 - DELETAR OS NOMES\n\n");
		printf("Opção:\n"); 
		
		
		scanf("%d",  &opcao); //armazenando a escolha do usuário
		
		system("cls");// reponsável por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consultar();
			break;
				
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
			
		}
		
		
	}	
}
