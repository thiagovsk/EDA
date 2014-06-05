#include <stdio.h>
#include <stdlib.h>

struct noArv
{
	int numero;
	char letra[40];
	struct noArv* esquerda;
	struct noArv* direita;

	contendo os campos: CODIGO TITULO MIDIA PRECO GENERO
	
};

typedef struct noArv NoArv;

NoArv* criar (void){

	return NULL;
}


NoArv* inserir(NoArv* arvore , int numero, char letra[]){

	if (arvore == NULL){
		arvore = (NoArv *) malloc(sizeof(NoArv));
		arvore->numero = numero;
		arvore->letra[0] = letra[0];
		arvore->esquerda = NULL; 
		arvore->direita = NULL;

	}
	else if ( numero < arvore->numero){
		
		arvore->esquerda = inserir(arvore->esquerda,numero,letra);

	}else{

		arvore->direita = inserir(arvore->direita,numero,letra);
	}

	return arvore;
}
void imprimirSimetrico(NoArv *arvore, FILE *arquivo){

		
	if (arvore != NULL){

		imprimirSimetrico(arvore->esquerda,arquivo);
		printf("%d  %c \n",arvore->numero, arvore->letra[0]);
		fprintf(arquivo,"%d %c \n",arvore->numero,arvore->letra[0]);
		imprimirSimetrico(arvore->direita,arquivo);
		
	}

}


void imprimirPosOrdem(NoArv *arvore, FILE *arquivo){

	if (arvore != NULL){
		imprimirPosOrdem(arvore->esquerda,arquivo);
		imprimirPosOrdem(arvore->direita,arquivo);
		printf("%d  %c \n",arvore->numero, arvore->letra[0] );
		fprintf(arquivo,"%d %c \n",arvore->numero,arvore->letra[0]);
	

	}

}


void imprimirPreOrdem(NoArv *arvore, FILE *arquivo){

	if (arvore != NULL){

		printf("%d  %c \n",arvore->numero, arvore->letra[0]);
		fprintf(arquivo,"%d %c \n",arvore->numero,arvore->letra[0]);
	
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
	
	arquivoSimetrico = fopen("imprimirSimetrico.txt","w");
	arquivoPreOrdem = fopen("imprimirPreOrdem.txt","w");	
	arquivoPosOrdem = fopen("imprimirPosOrdem.txt","w");

	
	NoArv *arvore =  criar();

	int opcao;
	int numero;

	char *letra= (char*) malloc(sizeof(char)*40);
	char *nomeArquivo = (char*) malloc(sizeof(char)*40);
	
	do{

		printf("\n 0-Sair \n 1-Inserir \n 2- Remover \n 3-Buscar \n 4- imprimirSimetrico \n 5- imprimirPreOrdem \n 6- imprimirPosOrdem \n 7- Ler de Arquivo de Entrada");
		scanf("%d",&opcao);


		switch (opcao){

			case 1:

				printf("\n Digite o a informação do nó \n ");
				scanf("%d",&numero);
				printf("\n Digite o a letra do nó \n ");
				scanf(" %[^\n]",letra);

				

				arvore = inserir(arvore,numero,letra);

				break;


			case 3:
				printf("\n Digite o a informação do nó \n ");
				scanf("%d",&numero);
				buscar(arvore,numero);
				break;

			case 4:
				printf("\n Imprimindo Simetrico \n");
				imprimirSimetrico(arvore,arquivoSimetrico);
				break;

			case 5:
				printf("\n Imprimindo Pré Ordem  \n");
				imprimirPreOrdem(arvore,arquivoPreOrdem);
				break;

			case 6:
				printf("\n Imprimindo Pós Ordem \n");
				imprimirPosOrdem(arvore,arquivoPosOrdem);
				break;

			case 7:
	
				printf("Digite um nome do arquivo \n");
				scanf(" %40[^\n]",nomeArquivo);
	
				arquivoEntrada = fopen(nomeArquivo,"r");
	
				while( (fscanf(arquivoEntrada,"%d %c",&numero,letra)) != EOF ){
	

					arvore = inserir(arvore,numero,letra);

				}
	
	
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
				


	return 0;
}