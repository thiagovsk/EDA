#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

	FILE *arquivo;
	
	char *nome;
	char c;
	
	nome = (char*) malloc(sizeof(char)*40);
		
	printf("Digite um nome do arquivo \n");
	scanf(" %40[^\n]",nome);
	
	arquivo = fopen(nome,"r");
	
	while((c= getc(arquivo)) != EOF ){
	
		printf("%c",c);
		
	}
	
	
	fclose(arquivo);
	
	free(nome);
	
}
