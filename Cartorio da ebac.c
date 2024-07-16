#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("não foi possivel abrir o arquivo,não localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nessas são as informsções do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
    system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	fclose(file);
	
}

int main()
{
    int opcao=0;
    int laco=1;
    
    for(laco=1;laco=1;)
    {
        
        system("cls"); 

        setlocale(LC_ALL, "portuguese");
    
        printf("### CARTÓRIO DA EBAC ###\n\n");
        printf("Escolha a opção desejada no menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - sair do sistema\n\n");
        printf("opção: ");
    
        scanf("%d", &opcao);
    
        system("cls");
        
        switch(opcao)
        {
            case 1:
            registro();
            break;
            
            case 2:
            consulta();
            break;
            
            case 3:
            deletar();
            break;
            
            case 4:
            printf("obrigado por utilizar o sistema!\n");
            return 0;
            break;
            
            default:
            printf("Essa opção não está disponivel!\n");
            system("pause");
            break;    
        }


    }
}
