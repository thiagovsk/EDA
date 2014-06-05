#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noArv
{
	char *codigo;
	char *titulo;
	char *midia;
	char *genero;
	double preco;

	struct noArv* esquerda;
	struct noArv* direita;
	
};

typedef struct noArv NoArv;

NoArv* criar (void){

	return NULL;
}

//arvore,codigo,titulo,midia,preco,genero
NoArv* inserir(NoArv* arvore , char *codigo,char *titulo,char *midia, double preco ,char *genero ){

	if (arvore == NULL){

		arvore = (NoArv *) malloc(sizeof(NoArv));
		
		printf(" CODIGO %s INSERIDO \n",codigo);
		arvore->codigo = codigo;
		arvore->titulo = titulo;
		arvore->midia = midia;
		arvore->preco = preco;
		arvore->genero = genero;

		arvore->esquerda = NULL; 
		arvore->direita = NULL;


	}else if (strcmp( arvore->codigo,codigo) > 0){
		printf(" PASSOU AQUI <<<<<<<<<<<<<<<<<<<<<<<<<<");
				
		arvore->esquerda = inserir(arvore->esquerda,arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);

	}else{

		arvore->direita = inserir(arvore->direita,arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);
	}

	return arvore;
}
void imprimirSimetrico(NoArv *arvore, FILE *arquivo){

		
	if (arvore != NULL){

		imprimirSimetrico(arvore->esquerda,arquivo);
	
		printf("%s %s %s %lf %s",arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);
		fprintf(arquivo,"%s %s %s %lf %s \n",arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);
	
		imprimirSimetrico(arvore->direita,arquivo);
		
	}

}


void imprimirPosOrdem(NoArv *arvore, FILE *arquivo){

	if (arvore != NULL){
		imprimirPosOrdem(arvore->esquerda,arquivo);
		imprimirPosOrdem(arvore->direita,arquivo);
	
		printf("%s %s %s %lf %s",arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);
		fprintf(arquivo,"%s %s %s  %lf %s \n",arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);
	

	}

}


void imprimirPreOrdem(NoArv *arvore, FILE *arquivo){

	if (arvore != NULL){

		printf("%s %s %s %2.2lf %s",arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);

		fprintf(arquivo,"%s %s %s %2.2lf %s \n",arvore->codigo,arvore->titulo,arvore->midia,arvore->preco,arvore->genero);
	
		imprimirPreOrdem(arvore->esquerda,arquivo);
		imprimirPreOrdem(arvore->direita,arquivo);

	}

}


 int main()
{

	FILE *arquivoSimetrico;
	FILE *arquivoPreOrdem;
	FILE *arquivoPosOrdem;
	FILE *arquivoEntrada;
	
	arquivoSimetrico = fopen("VIDEOS_CODIGO.txt","w");
	arquivoPreOrdem = fopen("imprimirPreOrdem.txt","w");	
	arquivoPosOrdem = fopen("SaidaPosOrdem.txt","w");
	//criando arvore	
	NoArv *arvore =  criar();

	//alocando atributos	
	char *codigo = (char*) malloc(sizeof(char)*10);
	char *titulo = (char*) malloc(sizeof(char)*100);
	char *midia  = (char*) malloc(sizeof(char)*10);
	char *genero = (char*) malloc(sizeof(char)*50);
	double preco;
	//declarando variaveis de apoio	
	char codigo_recebido[10];
	char titulo_recebido[100];
	char midia_recebido[100];
	char genero_recebido[100] ;
	double valor_recebido;
	

	//atributo para menu
	int opcao;
	double preco;

	//alocando memoria para os campos da struct e o nome do arquivo a ser lido
	char *nomeArquivo = (char*) malloc(sizeof(char)*40);
		
	do{

	

		printf("\n 0- Finalizar e gerar Arquivo SaidaPosOrdem \n 1- Carregar Arquivo \n 2- Imprimir dados \n");
		scanf("%d",&opcao);


		switch (opcao){

		 case 1:
	
				printf("Digite um nome do arquivo \n");
				scanf(" %40[^\n]",nomeArquivo);
	
				arquivoEntrada = fopen(nomeArquivo,"r");

				if (arquivoEntrada == NULL){
					printf("Arquivo Inexistente \n");
				}
				

					printf("\n Arquivo  importado ");
				
				while( (fscanf(arquivoEntrada,"%s %s %s %lf %s",codigo_recebido,titulo_recebido,midia_recebido,&valor_recebido,genero_recebido)) != EOF ){
	

					printf("Lendo o codigo : %s titulo %s media %s genero %s preco %2.2lf \n",codigo_recebido,titulo_recebido,midia_recebido,valor_recebido,genero_recebido);
					strcpy(codigo, codigo_recebido);
					strcpy(titulo, titulo_recebido);
					strcpy(midia, midia_recebido);
					preco=valor_recebido;
					strcpy(genero, genero_recebido);

					arvore = inserir(arvore,codigo,titulo,midia,preco,genero);

				}
				break;
			case 2:
				imprimirSimetrico(arvore,arquivoSimetrico);
				break;

			
			default:
				printf("\n Ok Saindo...\n ");				
		}
	}while( opcao != 0 );

	fclose(arquivoSimetrico);
	fclose(arquivoPreOrdem);
	fclose(arquivoPosOrdem);
	fclose(arquivoEntrada);
	free(nomeArquivo);
	free(codigo);
	free(titulo);
	free(midia);
	free(genero);
	



	return 0;
}