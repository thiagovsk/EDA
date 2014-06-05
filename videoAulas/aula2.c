#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "aula2.h"

//definicao do tipo de dados

struct ponto{
   float x;
   float y;
};

Ponto* ponto_criar(float x, float y){
   //alocar ponto

   Ponto* p = (Ponto*) malloc(sizeof(Ponto));
   
   if(p != NULL){
	p-> x = x;
	p->y = y;
   }

   return p;
}

void ponto_liberar(Ponto* p){
   free(p);
}
//recuperar por referencia 
void ponto_acessar(Ponto* p , float* x , float* y){
   *x = p->x ;
   *y = p-> y;
}		
//recuperar por parametro   
void ponto_atribuir(Ponto* p , float x , float y){
   p->x = x;
   p->y = y;
}

float ponto_distancia(Ponto* p1 , Ponto* p2){
   float raiz;
   float dx = (p1->x - p2->y);
   float dy = (p2->x - p2->y);

   raiz =  sqrt((dx*dx) + (dy*dy));	
   return raiz;
}


int main(){

   float distancia;
   Ponto *p,*q;

   p = ponto_criar(10,21);
   q = ponto_criar(7,25);


   distancia = ponto_distancia(p,q);

   printf("Distancia entre 2 pontos e %f",distancia);
   ponto_liberar(q);
   ponto_liberar(p);

return 0;

}

