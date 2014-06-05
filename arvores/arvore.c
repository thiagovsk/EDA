#include <stdio.h>
#include <stdlib.h>

struct noArv
{
	int numero;
	char *letra;
	struct noArv* esquerda;
	struct noArv* direita;
	
};

typedef struct noArv NoArv;

NoArv* criar (void){

	return NULL;
}

int Altura(NoArv* arvore){	

 	int iEsq,iDir;	
		
	 if (arvore == NULL)	
	 return 0;	
			
	 iEsq = Altura(arvore->esquerda);	
	 iDir = Altura(arvore->direita);	
		
 	if ( iEsq > iDir )	
 		return iEsq + 1;	
 	else	
 		return iDir + 1;	
}	

int FB (NoArv* arvore){	

	if (arvore == NULL)	
 	return 0;	
 	
 	return Altura(arvore->esquerda) - Altura(arvore->direita);	
}




NoArv* inserir(NoArv* arvore , int numero, char *letra){

	if (arvore == NULL){
		arvore = (NoArv *) malloc(sizeof(NoArv));
		arvore->numero = numero;
		arvore->letra = letra;
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

void imprimirSimetrico(NoArv *arvore){

	if (arvore != NULL){

		imprimirSimetrico(arvore->esquerda);
		printf("%d  %c \n",arvore->numero, arvore->letra[0] );
		imprimirSimetrico(arvore->direita);
	}

}


void imprimirPosOrdem(NoArv *arvore){

	if (arvore != NULL){
		imprimirPosOrdem(arvore->esquerda);
		imprimirPosOrdem(arvore->direita);
		printf("%d  %c \n",arvore->numero, arvore->letra[0] );

	}

}


NoArv* buscar(NoArv *arvore, int numero){

	if (arvore == NULL)	{
		
		return NULL;


	}
	else if (arvore->numero > numero){
	
		return buscar(arvore->esquerda,numero);
	
	}
	else if (arvore->numero < numero){
		
		return buscar(arvore->direita, numero);
	}else{

		printf("\n Numero encontrado %d sua letra e \n",arvore->numero,arvore->letra);
		return arvore;

	} 
}


void imprimirPreOrdem(NoArv *arvore){

	if (arvore != NULL){

		printf("%d  %c \n",arvore->numero, arvore->letra[0]);
		imprimirPreOrdem(arvore->esquerda);
		imprimirPreOrdem(arvore->direita);

	}

}

NoArv *remover(NoArv *arvore , int numero, char letra[1]){

	if (arvore == NULL)
		return NULL;

	else if (arvore->numero > numero)
		arvore->esquerda = remover(arvore->esquerda,numero,letra);

	else if (arvore->numero < numero)
		arvore->direita = remover(arvore->direita,numero,letra);
	
	else{//achou o nó a ser removido temos 3 casos

		//caso 1 nó sem filho
		if (arvore->esquerda == NULL && arvore->direita == NULL){
			
			free(arvore);
			arvore = NULL;
		}
		//nó so tem filho a direita
		else if (arvore->esquerda == NULL){
			NoArv *auxiliar = arvore;
			arvore = arvore->direita;
			free(auxiliar);
		}//nó so tem filho a esquerda
		else if (arvore->direita == NULL){
			NoArv *auxiliar = arvore;
			arvore = arvore->esquerda;
			free(auxiliar);
		}//nó tem os 2 filhos o mais a direita do nó da esquerda
		else{

			NoArv *auxiliar = arvore->esquerda;

			while(auxiliar->direita !=NULL){
				auxiliar = auxiliar->direita;
			}

			arvore->numero = auxiliar->numero;
			arvore->letra[1] = auxiliar->letra[1];
			auxiliar->numero = numero;
			auxiliar->letra[1] = letra[1];
			arvore->esquerda = remover(arvore->esquerda,numero,letra);



		}


	}	 

	return arvore;
}



 int main()
{
	NoArv *arvore =  criar();
	int numero;
	int opcao;
	int alturaArvore;
	char *letra= (char*) malloc(sizeof(char)*40);

	do{

		printf("\n 1-Inserir \n 2- Remover \n 3-Buscar \n 4- imprimirSimetrico \n 5- imprimirPreOrdem \n 6- imprimirPosOrdem \n");
		scanf("%d",&opcao);


		switch (opcao){

			case 1:

				printf("\n Digite o a informação do nó \n ");
				scanf("%d",&numero);
				printf("\n Digite o a letra do nó \n ");
				scanf(" %[^\n]",letra);

				
				arvore = inserir(arvore,numero,letra);
				alturaArvore = Altura(arvore);
				printf("  A Altura %d\n",alturaArvore );
				break;

			case 2:
				printf("\n Digite o a informação do nó \n");
				scanf("%d",&numero);
				printf("\n Digite o a letra do nó \n ");
				scanf("%[^\n]s",letra);
				
				remover(arvore,numero,letra);
				break;

			case 3:
				printf("\n Digite o a informação do nó \n ");
				scanf("%d",&numero);
				buscar(arvore,numero);
				break;

			case 4:
				printf("\n Imprimindo Simetrico \n");
				imprimirSimetrico(arvore);
				break;

			case 5:
				printf("\n Imprimindo Pré Ordem  \n");
				imprimirPreOrdem(arvore);
				break;

			case 6:
				printf("\n Imprimindo Pós Ordem \n");
				imprimirPosOrdem	(arvore);
				break;
			
			default:
				printf("\n Opção Invalida \n ");				
		}
	}while( opcao != 0 );


	return 0;
}