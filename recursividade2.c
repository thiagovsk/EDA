#include <stdio.h>
#include <stdlib.h>

int fb(int x){
	
	if(x == 1 || x=0){
		return 1;
	}

	return f(x-1)+ f(x-2);
	
}


int main(){

	printf("Numero e  %d \n ",fb(4));
	printf("Numero e  %d \n ",fb(0));
	printf("Numero e  %d \n ",fb(1));
	
return 0;
}
