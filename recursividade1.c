#include <stdio.h>
#include <stdlib.h>

int calcula(int x){
	
	if(x == 0){
		return 1;
	}

	return 2*(calcula(x-1));
}


int main(){

	printf("Numero e  %d \n ",calcula(0));
	printf("Numero e  %d \n ",calcula(1));
	printf("Numero e  %d \n ",calcula(2));
	printf("Numero e  %d \n ",calcula(3));
	
return 0;
}
