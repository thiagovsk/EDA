#include <stdio.h>
#include <stdio.h>


main(){

	int quantidade;
	char nome[40];
	float media;
	int contador =0;
	
	FILE *arquivo;
	
	arquivo = fopen("meusalunos.txt","w");
	
	printf("Quantos alunos para cadastrar jovem ?");
	scanf(" %d",&quantidade);
	
	fprintf(arquivo,"%i \n ",quantidade);
	
	
	for (contador ; contador < quantidade ; contador++){
	
		printf("Nome");
		scanf(" %[^\n]s",nome);
		
		printf("Media");
		scanf(" %f",&media);
		
		
		fprintf(arquivo,"%s %f",nome,media);
	
	
	}
	fclose(arquivo);
} 
