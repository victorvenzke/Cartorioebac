#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Começo do registro de nomes
	{
		char arquivo[40];//Comando char para string para abrir arquivo de dados
	    char cpf[40];//Comando char com base em string para criar cpf
	    char nome[40]; //Comando char com base em string para criar nome
	    char sobrenome[40]; //Comando char com base em string para criar sobrenome
	    char cargo[40]; //comando char com base em string para criar cargo
	    
	    printf("Digite o CPF a ser cadastrado: "); //Fazer a máquina memorizar a opção de cadastrar cpf
	    scanf("%s", cpf); //Fazer o usuário inserir o string de variáveis INT para memorização da máquina
	    
	    strcpy(arquivo, cpf);//copiar os valores das strings 
	    
	    FILE *file; // cria o arquivo
	    file = fopen(arquivo, "w"); // abre o arquivo para criar
	    fprintf(file, cpf); //salva a string de variáveis
	    fclose(file); // fecho o arquivo
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, ","); //Faz o arquivo memorizar a vírgula inserida
	    fclose(file); //fecha o arquivo

	    printf("Digite o nome a ser cadastrado: "); //Fazer a máquina memorizar a opção de cadastrar nome
	    scanf("%s", nome); //Fazer o usuário inserir o string de variáveis CHAR para memorização da máquina
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, nome); //salva a string de variáveis
	    fclose(file); //fecha o arquivo
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, ","); //Faz o arquivo memorizar a vírgula inserida
	    fclose(file); //fecha o arquivo
	    
	    printf("Digite o sobrenome a ser cadastrado: "); //Fazer a máquina memorizar a opção de cadastrar sobrenome
	    scanf("%s", sobrenome); //Fazer o usuário inserir o string de variáveis CHAR para memorização da máquina
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, sobrenome); //salva a string de variáveis
	    fclose(file); //fecha o arquivo
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, ","); //Faz o arquivo memorizar a vírgula inserida
	    fclose(file); //fecha o arquivo
	    
	    printf("Digite o cargo a ser cadastrado: "); //Fazer a máquina memorizar a opção de cadastrar cargo
	    scanf("%s", cargo); //Fazer o usuário inserir o string de variáveis CHAR para memorização da máquina
	    
	    file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	    fprintf(file, cargo); //salva a string de variáveis
	    fclose(file); //fecha o arquivo
	    
	    system("pause"); //evitar que o sistema volte ao seu início imediato sem o controle do usuário
	    
	}


int consulta()
	{
		
		setlocale(LC_ALL, "Portuguese"); //Altera o idioma para o português
		
		char cpf[40]; //Estabelece o CPF como fonte do usuário
		char conteudo[200]; //Conteudo do dado
		
		printf("Digite o CPF a ser consultado: "); 
		scanf("%s", cpf); //Interação do usuário usando string CPF
		
		FILE*file; //Abre o arquivo
		file = fopen(cpf, "r"); // lê o arquivo
		
		if(file == NULL) //Se não há nada no arquivo
		{
			printf("Esse arquivo não foi localizado!\n"); // Não foi localizado ou não existe
		}
		
		while(fgets(conteudo, 100, file) != NULL) // Se obter informações no CPF 
		{
			printf("\nEssas são as informações do usuário:\n");
			printf("%s", conteudo); //Mostra a string em texto para o usuário através dos dados acessados
			printf("\n\n");
		}
		
		system("pause"); //Pausa o sistema pro usuário ler e interagir
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
	    	printf("Esse usuário não foi encontrado!\n");
	    	system("pause");
		}
		
		remove(cpf);
		
		if(file != NULL)
		
	{
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	    
		
	}
		
	



int main()
{
	int opcao=0; //Definindo as variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
	    system("cls");
	     
	    setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
	    printf("### Cartório da EBAC ###\n\n"); //início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Opção: "); //Fim do menu
	
	     scanf("%d", &opcao); //armazenando as informações, dando a interação pro usuário
	
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
			printf("Essa opção não está disponível\n");
		    system("pause");
		    break;	
		    
		    //fim do programa
		 }
}

}

