#include<stdio.h>
#include<stdlib.h>

double calcula(numero){

	double resultado;
	if( numero == 0 ){
	
		return 1 / 3;
		
	}
	
	resultado = (double)(numero*numero + 1) / (numero+3) + calcula(numero-1);
	return resultado;
}

int main(){



	printf("%lf \n",calcula(1));
	printf("%lf \n",calcula(2));
	printf("%lf \n",calcula(3));
	printf("%lf \n",calcula(4));
return 0;

}
