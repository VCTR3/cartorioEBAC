#include <stdio.h> //biblioteca de comunica��o com o usu�rio

#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria

#include <locale.h> //biblioteca de aloca��es de texto por regi�o

#include <string.h> // biblioteca de conjunto de caracteres (strings)

#include <stdbool.h> //Biblioteca des Booleans

int registrar()
{ 

setlocale(LC_ALL, "Portuguese");

    char arquivo[100];
    char nome[40];
    char sobrenome[40];
    char cpf[40];
    char cargo[40];
    char choice[10];

    printf("Qual o seu CPF?: ");
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

    printf("Verifique se seus dados est�o corretos\n\nDigite 'yes' para 'dados corretos'\n\nDigite 'no' para preencher os dados novamente: ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        printf("Seus dados foram salvos no sistema!\n\n");
    } 
	else if (strcmp(choice, "no") == 0) 
	{
        printf("Seus dados n�o foram salvos no sistema!\n\n");

        if (remove(arquivo) == 0) {
            printf("Arquivo exclu�do com sucesso.\n");
        } else {
            printf("Erro ao excluir o arquivo.\n");
        }
    }

    return 0;
}

int consultar()
{

setlocale (LC_ALL, "Portuguese");//Referencia de biblioteca


	char cpf[40];
	char conteudo [200];
	char *token;
	
	
	printf ("Digite o CPF que deseja consultar: ");
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel encontrar o CPF digitado, n�o localizado no sistema!\n\n");
	}
	
	while (fgets (conteudo, 200, file) != NULL)
	{
		printf("\nEstas s�o as informa��es sobre o usuario cadastrado: \n\n");
		
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
system ("pause");
}

int deletar()
{
	char cpf[40];
	char choice[10];
	
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
	FILE *file;
    file = fopen(cpf, "r");
    remove (cpf);

    if (file == NULL) {
        printf("O usu�rio n�o foi encontrado.\n\n");
        system("pause");
    } else {
        fclose(file);
        
        if (remove(cpf) == 0) {
            printf("O usu�rio foi deletado.\n\n");
            system("pause");
        } else {
            printf("Erro ao deletar o usu�rio.\n\n");
            system("pause");
        }
        
		  }
 return 0;
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
    	printf ("Escolha a op��o desejada\n\n");
    	printf ("\t1-Registrar nomes\n");
    	printf ("\t2-Consultar nomes\n");
        printf ("\t3-Deletar nomes\n\n");
    	printf ("Op��o:" );// Fim do menu

        scanf("%d", &opcao);
    
        system ("cls");
    
        switch (opcao) //inicio da sele��o
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
    	    printf("Esta op��o n�o est� dispon�vel para o usu�rio!\n");
            system ("pause");	
        break;
        } //Fim da sele��o
    }
} 
