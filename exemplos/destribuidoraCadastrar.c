#include <stdio.h>
#include <stdlib.h>


int main(){

	int codigo;
	char tipo[40];
	int estoque;
	double valor;
	char nome[40];
	int contado=0;
	double total=0;
		
	FILE *arquivo;
	FILE *arquivo2;
	
	arquivo = fopen("estoque.txt","a+");
	
	while(contado <2){
	printf("Digite o codigo do produto");
	scanf(" %d",&codigo);
	
	printf("Digite o tanto que tem no estoque");
	scanf(" %d",&estoque);
	
	printf("Digite o valor do produto");
	scanf(" %lf",&valor);
	
	printf("Digite o tipo");
	scanf(" %[^\n]s",tipo);
	
	if(strcmp(tipo,"bala") == 0){
	
		arquivo2 = fopen("bala.txt" , "a+");
		
	fprintf(arquivo2,"%d %s  %s %d %lf\n",codigo,tipo,nome,estoque,valor);
	
	
	}
	
	printf("Digite o nome");
	scanf(" %[^\n]s",nome);
	
	
	
	
	fprintf(arquivo,"%d %s  %s %d %lf\n",codigo,tipo,nome,estoque,valor);
	
	contado++;
	total = total + valor*estoque;
	
	}
		
	fprintf(arquivo,"Valor do estoque e :%lf \n",total);
	fclose(arquivo);
	





}
