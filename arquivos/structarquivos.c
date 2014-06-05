#include <stdio.h>

main(){

typedef struct{

	int numero;
	char nomer[41];
	float media;

}t_lista;


	t_lista a[2] = {{1, "Maria luiza" , 7},{2, "Ana maria ",8}};
	
	FILE *arquivo;
	
	arquivo = fopen("notas.txt","w");
	
	fprintf(arquivo,"%10i %-40s %8.2f ",a[0].numero,a[0].nomer,a[0].media);
	
	fprintf(arquivo,"%10i %-40s %8.2f ",a[1].numero,a[1].nomer,a[1].media);
	
	
	
	
	
	fclose(arquivo);
}
