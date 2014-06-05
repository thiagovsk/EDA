#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double soma(double a, double b){

   return a + b;

}

double subtracao(double a, double b){

   return a - b;
}

double multiplicacao(double a , double b){

   
   return a*b;

}

double divisao(double a, double b){

   return a / b;
}

int main(){
	
	char *opcao;
	double valor1,valor2,resultado;

	double (*psoma)(double , double );
	psoma = &soma;

	
	printf("digite o primeiro valor \n");
	scanf("%lf",&valor1);
	
	printf("digite o segundo valor \n");
        scanf("%lf",&valor2);
	
	printf(" Qual opecarao ? \n Soma \n Subtracao \n Multiplicaao \n Divisao \n" );
	scanf("%s",opcao);


	if(strcmp(opcao,"soma") == 0 ){
		
		resultado = psoma(valor1,valor2);
		printf(" %2.lf \n",resultado);	
		

	}
	
	else if(strcmp(opcao,"subtracao") == 0 ){	
	resultado = subtracao(valor1,valor2);
	printf(" %2.lf \n",resultado);
	}	
	
	else if(strcmp(opcao,"multiplicacao") == 0 ){
	resultado = multiplicacao(valor1,valor2);
        printf(" %2.lf \n",resultado);
	}
	
	else if (strcmp(opcao,"divisao") == 0 ){
	resultado = divisao(valor1,valor2);
        printf("%2.lf \n",resultado);
	}

 return 0;
}



