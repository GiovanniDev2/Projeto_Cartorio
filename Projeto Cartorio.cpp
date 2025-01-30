#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por regioão
#include <string.h> //biblioteca responsavel por cuida das strings

int registro() //Responsavel por fazer o cadastro
{
	char arquivo[40]; //Criação de variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //Final da criação
	
	printf("Digite o CPF a ser cadastrado: "); //Pegando informação do usuario
	scanf("%s", cpf);// %s refere-se a string/salva strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar valor das strings
	
	FILE *file; //criando o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo "w" Significa escrever
	fprintf(file,cpf); //salvo o valor variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir o aquivo e "a" de atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); //Salva strings
	
	file = fopen(arquivo, "a"); //Abrindo e atualizando
	fprintf(file,nome); //salvar o valor da variavel
	fclose(file); //fechando
	
	file = fopen(arquivo, "a"); //Abrindo e atualizando
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);	
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //Salva strings
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso nulo
	{
		printf("CPF não cadastrado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informação de usuario:\n\n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40]; 
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf); //Salva strings
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Lendo "r"
	
	if(file == NULL) //Caso for nulo
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}	
	
	else
	
	{
		remove(cpf); 
		printf("Usuário deletado!\n");
		system("Pause");
	}
	
}


int main()
	{
	int opcao=0; //definindo variavel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	system("cls"); //Limpando a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo idioma
	
	printf("### Cartório da EBAC\n\n"); //inicio
	printf("Escolha a opção desejada do menu\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Opção: "); //final menu
	
	scanf("%d", &opcao); //armazena a escolha
	
	system("cls"); //clean
	
	
	 switch(opcao) //Seleção do menu
	 {
		case 1:
		registro(); //Chamando função
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Essa opção não está disponivel\n");
		system("pause");
		break;
		//Fim
	 }
	
	}
}
