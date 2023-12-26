#include <stdio.h> //biblioteca de comunicação com o usuário

#include <stdlib.h> //biblioteca de alocação de espaço em memória

#include <locale.h> //biblioteca de alocações de texto por região

#include <string.h> // biblioteca de conjunto de caracteres (strings)

#include <stdbool.h> //Biblioteca des Booleans

int registrar()
{ 

setlocale(LC_ALL, "Portuguese");//Referencia de biblioteca

    char arquivo[100];//Variavéis
    char nome[40];
    char sobrenome[40];
    char cpf[40];
    char cargo[40];
    char choice[10];

    printf("Qual o seu CPF?: ");//Inicio do cadastro
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Qual o seu nome?: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Qual o seu sobrenome?: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Qual o cargo desejado?: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Verifique se seus dados estão corretos\n\nDigite 'yes' para 'dados corretos'\n\nDigite 'no' para preencher os dados novamente: ");
    scanf("%s", choice);//Fim do cadastro

    if (strcmp(choice, "yes") == 0) {
        printf("Seus dados foram salvos no sistema!\n\n");
    } 
	else if (strcmp(choice, "no") == 0) 
	{
        printf("Seus dados não foram salvos no sistema!\n\n");

        if (remove(arquivo) == 0) {
            printf("Arquivo excluído com sucesso.\n");
        } else {
            printf("Erro ao excluir o arquivo.\n");
        }
    }

    return 0;

int consultar()
{

setlocale (LC_ALL, "Portuguese");//Referencia de biblioteca


	char cpf[40];//Variaveis
	char conteudo [200];
	char *token;
	
	
	printf ("Digite o CPF que deseja consultar: ");//Inicio da consulta
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Não foi possível encontrar o CPF digitado, não localizado no sistema!\n\n");
	}
	
	while (fgets (conteudo, 200, file) != NULL)
	{
		printf("\nEstas são as informações sobre o usuario cadastrado: \n\n");
		
		token = strtok(conteudo, ",");
		printf("CPF: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("Cargo: %s\n", token);
		
		
	}
	
printf ("\n\n");
system ("pause"); //Fim da consulta
}

int deletar()
{
	char cpf[40];//Variaveis
	char choice[10];
	
	
	printf("Digite o CPF do usuário a ser deletado: ");//Inicio do "Deletar"
    scanf("%s", cpf);
    
	FILE *file;
    file = fopen(cpf, "r");
    remove (cpf);

    if (file == NULL) {
        printf("O usuário não foi encontrado.\n\n");
        system("pause");
    } else {
        fclose(file);
        
        if (remove(cpf) == 0) {
            printf("O usuário foi deletado.\n\n");
            system("pause");
        } else {
            printf("Erro ao deletar o usuário.\n\n");
            system("pause");
        }
        
		  }
 return 0; //Fim do "Deletar"
}


int main () 
{
     int opcao=0;// Variavel
     int x=1;
     
    for(x=1;x=1;)
    {
	 
        system("cls");
        setlocale (LC_ALL, "Portuguese");//Referencia de biblioteca


    	printf ("### CARTORIO DA EBAC ###\n\n");//Inicio do menu
    	printf ("Escolha a opção desejada\n\n");
    	printf ("\t1-Registrar nomes\n");
    	printf ("\t2-Consultar nomes\n");
        printf ("\t3-Deletar nomes\n\n");
    	printf ("Opção:" );// Fim do menu

        scanf("%d", &opcao);
    
        system ("cls");
    
        switch (opcao) //inicio da seleção
    	{
    	case 1: 
    	registrar();
        break;
         
        case 2:
        consultar();
		break;
		 
		case 3: 
	    deletar();
		break;
		
       	 default: 
    	    printf("Esta opção não está disponível para o usuário!\n");
            system ("pause");	
        break;
        } //Fim da seleção
    }
} 
