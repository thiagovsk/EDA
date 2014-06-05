#include <stdio.h>
#include <stdlib.h>
void valorEstoque(){

	
	int codigo;
	int estoque;
	int preco;
	char tipo[1], nome[40];
	FILE *mercearia;
	double total = 0;

	mercearia = fopen("mercearia2.txt","r");

	while( fscanf(mercearia,"%d %s %s %d %d \n",&codigo,tipo,nome,&estoque,&preco) != EOF ){
	
	printf("preco = %d estoque = %d \n",preco,estoque);
	total = (preco + estoque) + total;
		
	printf("\n total = %2.lf",total);
	}
	
	fclose(mercearia);
}


void cadastrar(){

	int codigo;
	int estoque;
	int preco;
	char tipo[1], nome[40];
	
	FILE *arquivo;

	arquivo = fopen("mercearia2.txt","a");

	printf("Digite o codigo \n");
	scanf(" %d",&codigo);

	printf("Digite a quantidade de estoque \n");
	scanf(" %d",&estoque);

	printf("Digite o preco \n");
	scanf(" %d",&preco);

	printf("Digite o tipo \n");
	scanf(" %s",tipo);

	printf("Digite o Nome \n");
	scanf(" %s",nome);

	fprintf(arquivo,"%d %s %s %d %d \n",codigo,tipo,nome,estoque,preco);
	fclose(arquivo);

}

int main(){

	
	int menu;
	
	do{
	
	printf("1- Cadastrar \n 2-Calcular valor total \n");
	scanf("%d",&menu);
	
	if(menu ==1 ){

		cadastrar();

	}else if(menu == 2){

		valorEstoque();	
	}

	}while(menu >0 && menu <3);


			
return 0;	

}
