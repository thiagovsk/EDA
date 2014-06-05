#include<stdio.h>
#include<stdlib.h>

int calcula(int numero){

	if(numero == 0){
	
		return 0;
	}
	
	return numero+(numero-1);
}

int main(){



	printf("%d \n",calcula(0));
	printf("%d \n",calcula(1));
	printf("%d \n",calcula(2));
	printf("%d \n",calcula(3));
	printf("%d \n",calcula(4));
	
	

return 0;

}
