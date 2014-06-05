#include<stdio.h>
#include<stdlib.h>

int main(){

	int *a,*aux,i;
	
	a = (int*) malloc(sizeof(int)*5);
	
	for( i = 0 ; i<5 ; i++){
	printf("digite o valor \n");
	scanf("%d",&a[i]);
	}
		
	
	for(i = 0 ; i<5 ; i++){
	
	printf("%d \n",a[i]);
	}

	

return 0;
}
