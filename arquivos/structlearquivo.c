#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

	int numero;
	char nome[40];
	float media;
	FILE *arquivo;
	
	arquivo = fopen("notas.txt","r");
	
	numero = 0;
	while( numero < 3  ){
		
	fscanf(arquivo,"%i %s %f",&numero,nome,&media);
	printf("%i %s %f",numero,nome,media);		
	numero++;
	
}	
}

