#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

	FILE *arquivo;
	
	char *nome;
	char *frase;
	
	
	nome = (char*) malloc(sizeof(char)*40);
	
	frase = (char*) malloc(sizeof(char)*40);
	
	
	printf("Digite um nome do arquivo \n");
	scanf(" %[^\n]",nome);
	
	arquivo = fopen(nome,"w+");
	 
	printf("Digite a frase \n");
	scanf(" %40[^\n]",frase);
	
	fprintf(arquivo,frase);
	
	fclose(arquivo);
	free(nome);
	free(frase);

	
	
}
