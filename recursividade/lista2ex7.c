#include<stdio.h>
#include<stdlib.h>

double calcula(numero1 ,numero2){

	double soma = 0;
	if( numero1 == 0  && numero2 ==0){
		
			
		return soma;
		
	}else if (numero1 > soma && numero2 > soma){  
		soma = calcula(numero1 -1 , numero2 -1);
		soma ++;
	}
	return ;
}

int main(){

	printf("%lf \n",calcula(0,0));
	printf("%lf \n",calcula(1,1));
	printf("%lf \n",calcula(2,2));
	printf("%lf \n",calcula(3,3));
return 0;

}
