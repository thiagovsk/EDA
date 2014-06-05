#include<stdio.h>
#include<stdlib.h>

void compara(char *string){
 
 	
	 if (*string != '\0'){
	 
	 	compara(string+1);
  		putchar(*string);
 	} 
}
int main(){
	
	char nome[30] = "pato";
		
	compara(nome);
	
 return 0;
}
