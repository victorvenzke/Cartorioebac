#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Come�o do registro de nomes
	{
		char arquivo[40];//Comando char para string para abrir arquivo de dados
	    char cpf[40];//Comando char com base em string para criar cpf
	    char nome[40]; //Comando char com base em string para criar nome
	    char sobrenome[40]; //Comando char com base em string para criar sobrenome
	    char cargo[40]; //comando char com base em string para criar cargo
	    
	    printf("Digite o CPF a ser cadastrado: "); //Fazer a m�quina memorizar a op��o de cadastrar cpf
	    scanf("%s", cpf); //Fazer o usu�rio inserir o string de vari�veis INT para memoriza��o da m�quina
	    
	    strcpy(arquivo, cpf);//copiar os valores das strings 
	    
	    FILE *file; // cria o arquivo
	    file = fopen(arquivo, "w"); // abre o arquivo para criar
	    fprintf(file, cpf); //salva a string de vari�veis
	    fclose(file); // fecho o arquivo
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, ","); //Faz o arquivo memorizar a v�rgula inserida
	    fclose(file); //fecha o arquivo

	    printf("Digite o nome a ser cadastrado: "); //Fazer a m�quina memorizar a op��o de cadastrar nome
	    scanf("%s", nome); //Fazer o usu�rio inserir o string de vari�veis CHAR para memoriza��o da m�quina
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, nome); //salva a string de vari�veis
	    fclose(file); //fecha o arquivo
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, ","); //Faz o arquivo memorizar a v�rgula inserida
	    fclose(file); //fecha o arquivo
	    
	    printf("Digite o sobrenome a ser cadastrado: "); //Fazer a m�quina memorizar a op��o de cadastrar sobrenome
	    scanf("%s", sobrenome); //Fazer o usu�rio inserir o string de vari�veis CHAR para memoriza��o da m�quina
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, sobrenome); //salva a string de vari�veis
	    fclose(file); //fecha o arquivo
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, ","); //Faz o arquivo memorizar a v�rgula inserida
	    fclose(file); //fecha o arquivo
	    
	    printf("Digite o cargo a ser cadastrado: "); //Fazer a m�quina memorizar a op��o de cadastrar cargo
	    scanf("%s", cargo); //Fazer o usu�rio inserir o string de vari�veis CHAR para memoriza��o da m�quina
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, cargo); //salva a string de vari�veis
	    fclose(file); //fecha o arquivo
	    
	    system("pause"); //evitar que o sistema volte ao seu in�cio imediato sem o controle do usu�rio
	    
	}


int consulta()
	{
		
		setlocale(LC_ALL, "Portuguese"); //Altera o idioma para o portugu�s
		
		char cpf[40]; //Estabelece o CPF como fonte do usu�rio
		char conteudo[200]; //Conteudo do dado
		
		printf("Digite o CPF a ser consultado: "); 
		scanf("%s", cpf); //Intera��o do usu�rio usando string CPF
		
		FILE*file; //Abre o arquivo
		file = fopen(cpf, "r"); // l� o arquivo
		
		if(file == NULL) //Se n�o h� nada no arquivo
		{
			printf("Esse arquivo n�o foi localizado!\n"); // N�o foi localizado ou n�o existe
		}
		
		while(fgets(conteudo, 100, file) != NULL) // Se obter informa��es no CPF 
		{
			printf("\nEssas s�o as informa��es do usu�rio:\n");
			printf("%s", conteudo); //Mostra a string em texto para o usu�rio atrav�s dos dados acessados
			printf("\n\n");
		}
		
		system("pause"); //Pausa o sistema pro usu�rio ler e interagir
	}
	
	
int deletar()	
    {
	    char cpf[40];
	    
	    printf("Digite o CPF a ser deletado: ");
	    scanf("%s", cpf);
	    
	    FILE*file;
	    file = fopen(cpf, "r");
	    
	    if(file == NULL)
	    {
	    	printf("Esse usu�rio n�o foi encontrado!\n");
	    	system("pause");
		}
		
		remove(cpf);
		
		if(file != NULL)
		
	{
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
	    
		
	}
		
	



int main()
{
	int opcao=0; //Definindo as vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		
	    system("cls");
	     
	    setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
	    printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Op��o: "); //Fim do menu
	
	     scanf("%d", &opcao); //armazenando as informa��es, dando a intera��o pro usu�rio
	
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
			
			default:	
			printf("Essa op��o n�o est� dispon�vel\n");
		    system("pause");
		    break;	
		    
		    //fim do programa
		 }
}

}

