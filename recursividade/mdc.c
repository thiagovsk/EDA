#include<stdio.h>
#include<stdlib.h>

int calcula(int p ,int q){

	if( q  == 0 ){
	
		return p;	
	}else
	
	return calcula(q, p%q);
}

int main(){


	printf("%d \n",calcula(348,156));
	
	printf("%d \n",calcula(6,12));
	
	printf("%d \n",calcula(36,90));
	
	printf("%d \n",calcula(12,20));
	
	
return 0;

}
