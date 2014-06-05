#include<stdio.h> 
float exemplo(int n1, int n2) 
{ 
 return 3.14159*n1*n2; 
} 
 
main() 
{ 
 float R, R2; 
 float (*p) (int i, int j); 
 p = exemplo; 
 R = p(12,45); 
 R2 = (*p)(12,45); 
 printf("R= %f, R2 = %f", R, R2); 
} 
