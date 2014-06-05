#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

	FILE *arquivo;
	
	char *nome;
	char c;
	float numero,soma;
	
	nome = (char*) malloc(sizeof(char)*40);
		
	printf("Digite um nome do arquivo \n");
	scanf(" %40[^\n]",nome);
	
	arquivo = fopen(nome,"r");
	
	soma = 0;
	while( fscanf(arquivo,"%f",&numero) != EOF ){
		
		soma = soma +numero;
		
	}	
	
	printf("%10.2f \n",numero);
	fclose(arquivo);
	
	free(nome);
	
}
