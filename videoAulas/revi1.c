#include <stdio.h>
#include <stdlib.h>

int main (){

	float celsius;
	float farer;
	char c;

	do{
	
	printf("Digite o valor em celsius \n");
	scanf(" %f",&celsius);
	 __fpurge(stdin);

	farer =( celsius*1.8) + 32;
	
	printf("%.2f \n",farer);

	printf("\n Deseja continuar? s ou n \n");

	c = getchar();

	}while(c == 's');

return 0;
}

