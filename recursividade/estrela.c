#include<stdio.h>
#include<stdlib.h>

void estrela(int x,int y, int r){
 
	 if ( r > 0 ){
  
	 estrela(x-r, y+r, r / 2); 
	 estrela(x+r, y+r, r / 2); 
	 estrela(x-r, y-r, r / 2); 
	 estrela(x+r, y-r, r / 2); 
	 box(x, y, r); 
 } 
}
int main(){
	estrela(4,4,4);	
 return 0; 
}
