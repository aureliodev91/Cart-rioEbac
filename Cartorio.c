#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa� em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
// \t � para alinhar a frase/letra no centro
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	// inicio criaa��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criaa��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado:  ");// coletando informa��es do usu�rio
	scanf("%s", cpf); // salvando em uma string
	
	strcpy(arquivo, cpf);// respons�vel por copiar os valores das strings, copiando do cpf para o arquivo
	
	// procedimento para criar um arquivo, abrir o arquivo, salvar dentro dele e fechar.
	FILE *file;// acessa o FILE e cria o arquivo file
	file = fopen(arquivo, "w");// criou o file e ele vai usar o f.open para abrir o arquivo, que � a vari�vel arquivo neste caso. o w � de write( para escrever nele)
	fprintf(file, cpf);// um print f que salva dentro do arquivo. Salvando no file, a vari�vel cpf
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // esse "a" agora � porque queremos atualizar a informa��o, em vez de criar uma nova
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
	file = fopen(cpf, "r"); // neste caso o ele vai abrir o file e na vari�vel cpf vai ler o que tem dentro(reading)
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");

	}
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto tiver escrevendo em conteudo, at� 200 valores que est�o dentro do arquivo, enquanto for diferente de nulo
	{
		printf("\n Essas s�o as informa��es do usu�rio:  ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");

}								

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:  ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) 
	{	
		printf("Usu�rio n�o encontrado!\n");
		system("pause");
	}

}


int main()
{
	
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)// repetir quando o la�o for 1 e enquanto o la�o for 1
	{
		
	
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
		system("cls");
		printf("###Cart�rio da EBAC###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - REGISTRAR NOMES\n");
		printf("\t2 - CONSULTAR OS NOMES\n");
		printf("\t3 - DELETAR OS NOMES\n\n");
		printf("Op��o:\n"); 
		
		
		scanf("%d",  &opcao); //armazenando a escolha do usu�rio
		
		system("cls");// repons�vel por limpar a tela
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
				
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		}
		
		
	}	
}
