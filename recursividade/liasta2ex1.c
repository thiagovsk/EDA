#include<stdio.h>
#include<stdlib.h>

int compara(char *string,char *string2){
 	
 	 int result;
	 if (*string == '\0' || *string2 == '\0')
	 	return 1;
 	
 	if(*string > *string2)
 		return 0;
 		
 	
 	if(*string < *string2)
 		return 0;
 		
 	return compara(string+1,string2+1);
 	
}
int main(){
	
	char nome[30] = "pato";
	char nome2[30] = "pata";
		
	printf("%d",compara(nome,nome2));
	
 return 0;
}
