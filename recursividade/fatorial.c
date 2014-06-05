#include<stdio.h>
#include<stdlib.h>

int calcula(int numero){

	if( numero == 1 || numero ==0 ){
	
		return 1;	
	}else
	
	return numero * calcula(numero-1);
}

int main(){


	printf("%d \n",calcula(0));
	printf("%d \n",calcula(1));
	printf("%d \n",calcula(2));
	printf("%d \n",calcula(3));
	printf("%d \n",calcula(4));
	printf("%d \n",calcula(5));
	printf("%d \n",calcula(6));
	printf("%d \n",calcula(7));
	printf("%d \n",calcula(8));
	printf("%d \n",calcula(9));
	printf("%d \n",calcula(10));
	
return 0;

}
