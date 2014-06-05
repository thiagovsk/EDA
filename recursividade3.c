#include <stdio.h>
#include <stdlib.h>

int calcula(unsigned int x){
	
	if(x == 1 ){
		return 1;
	}
	
	if(x == 0){
		return 0;
	}
	
	return x+calcula(x-1);
	
}


int main(){

	printf("Numero e  %d \n ",calcula(5,3));
	
return 0;
}
