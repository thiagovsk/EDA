#include <stdio.h>
#include <stdlib.h>

int fb(int x){
	int contador;
	if(x == 1 || x == 0){
		return 1;
	}
	contador++;
	printf("%d \n",contador);

	return fb(x-1)+ fb(x-2);
	
}

int main(){

	printf("Numero e  %d \n ",fb(45));
	
return 0;
}
