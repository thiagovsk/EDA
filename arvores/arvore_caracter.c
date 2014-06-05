#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elemento
{
	char *codigo;
	char *titulo;
	char *midia;
	char *genero;
	double preco;
	
};

typedef struct Elemento Elemento;

struct noArv
{
	Elemento *elemento;
	struct noArv* esquerda;
	struct noArv* direita;
	
};

typedef struct noArv NoArv;

NoArv* criar (void){

	return NULL;
}

//arvore,codigo,titulo,midia,preco,genero
NoArv *inserir(NoArv* arvore , char *codigo,char *titulo,char *midia, double preco ,char *genero ){
	
	Elemento *elemento = (Elemento *) malloc(sizeof(Elemento));
	
	elemento->codigo = codigo;
	elemento->titulo = titulo;
	elemento->preco  = preco;
	elemento->midia  = midia;
	elemento->genero = genero;

	if (arvore == NULL){

		arvore = (NoArv *) malloc(sizeof(NoArv));
		arvore->elemento = elemento;

		printf(" CODIGO %s INSERIDO \n",codigo);
	
		arvore->esquerda = NULL; 
		arvore->direita = NULL;


	}else if (strcmp( arvore->elemento->codigo , codigo) <= 0){
				
		arvore->esquerda = inserir(arvore->esquerda,arvore->elemento->codigo,arvore->elemento->titulo,arvore->elemento->midia,arvore->elemento->preco,arvore->elemento->genero);

	}else{

		arvore->direita = inserir(arvore->direita,arvore->elemento->codigo,arvore->elemento->titulo,arvore->elemento->midia,arvore->elemento->preco,arvore->elemento->genero);
	}

	return arvore;
}
void imprimirPreFixadoEsq(NoArv *arvore, FILE *arquivo){

		
	if (arvore != NULL){

		imprimirPreFixadoEsq(arvore->esquerda,arquivo);

		printf("%s %s %s %2.2lf %s \n",arvore->elemento->codigo,arvore->elemento->titulo,arvore->elemento->midia,arvore->elemento->preco,arvore->elemento->genero);
		fprintf(arquivo,"%s %s %s %2.2lf %s \n",arvore->elemento->codigo,arvore->elemento->titulo,arvore->elemento->midia,arvore->elemento->preco,arvore->elemento->genero);

		imprimirPreFixadoEsq(arvore->direita,arquivo);
	
	}

}

 int main()
{

	FILE *arquivoSimetrico;
	FILE *arquivoEntrada;

	arquivoSimetrico = fopen("VIDEOS_CODIGO.txt","w");
	

	
	
	//criando arvore	
	NoArv *arvore =  criar();

	//alocando atributos	
	char *codigo = (char*) malloc(sizeof(char)*10);
	char *titulo = (char*) malloc(sizeof(char)*100);
	char *midia  = (char*) malloc(sizeof(char)*10);
	char *genero = (char*) malloc(sizeof(char)*50);
	
	//copias
	char codigo_copia[10]; 
	char titulo_copia[100];
	char midia_copia[10];
	char genero_copia[20];


	//atributo para menu
	int opcao;
	double preco;

	//alocando memoria para os campos da struct e o nome do arquivo a ser lido
	char *nomeArquivo = (char*) malloc(sizeof(char)*40);
		
	do{

		printf("\n 0- Finalizar e gerar Arquivo VENDAS_CODIGO \n 1- Carregar Arquivo \n 2- Imprimir dados \n");
		scanf("%d",&opcao);

				
						
		switch (opcao){

		 case 1:
	
				printf("Digite um nome do arquivo \n");
				scanf(" %40[^\n]",nomeArquivo);
	
				arquivoEntrada = fopen(nomeArquivo,"r");
		
				if (arquivoEntrada == NULL)
				printf("\n Nome do arquivo incorreto ");
		

				while( (fscanf(arquivoEntrada,"%s %s %s %lf %s",codigo,titulo,midia,&preco,genero)) != EOF ){
	
					printf("Lendo o codigo : %s titulo %s media %s genero %s preco %2.2lf \n",codigo,titulo,midia,genero,preco );

					strcpy(codigo_copia, codigo);
        			strcpy(titulo_copia, titulo);
        			strcpy(midia_copia , midia);
        			strcpy(genero_copia, genero);
        			
					arvore = inserir(arvore,codigo_copia,titulo_copia,midia_copia,preco,genero_copia);
					
				}

				break;
			
			case 2:
				imprimirPreFixadoEsq(arvore,arquivoSimetrico);
				break;
			
			default:
				printf("\n Ok Saindo...\n ");				
		}
	}while( opcao != 0 );

	fclose(arquivoSimetrico);
	fclose(arquivoEntrada);
	free(nomeArquivo);
	free(codigo);
	free(titulo);
	free(midia);
	free(genero);
	
	return 0;
}