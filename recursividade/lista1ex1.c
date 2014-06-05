#include<stdio.h>
#include<stdlib.h>

int calcula(int numero){

	if(numero == 0){
	
		return 1;
	}else if( numero == 1){
	
		return 2;
	}else
	
	return 2*calcula(numero-1);
}

int main(){



	printf("%d \n",calcula(0));
	printf("%d \n",calcula(1));
	printf("%d \n",calcula(2));
	printf("%d \n",calcula(2));
	printf("%d \n",calcula(3));
	printf("%d \n",calcula(4));
	
	

return 0;

}
