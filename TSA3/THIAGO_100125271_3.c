#include<stdio.h>
#include<stdlib.h>

typedef struct Tno{


    long int endereco;
    long int quantidadeBytes;
    struct Tno *proximo;

}Tno ;

int vazia(Tno *cabeca){

    if(cabeca == NULL)
       printf("\n Pilha vazia! ");
     return 0;
} 


void imprimir(Tno *cabeca){

    Tno *iterator;
    iterator = (Tno *) malloc(sizeof(Tno));

    iterator = cabeca;

    while(iterator != NULL){

        printf("\nEndereco = %ld  Quantidade de bytes = %ld \n",iterator->endereco,iterator->quantidadeBytes );
        iterator = iterator->proximo;

    }

}

Tno *empilhar(Tno *cabeca, long int endereco, long int quantidadeBytes ){

    Tno *novo;
    novo = (Tno *) malloc(sizeof(Tno));

    novo->endereco = endereco;
    novo->quantidadeBytes = quantidadeBytes;
    
    novo->proximo = cabeca;
    cabeca = novo;

    return cabeca;

}




Tno * desempilhar(Tno *cabeca){

  Tno *iterator;

  iterator = (Tno *) malloc(sizeof(Tno));
  
  iterator = cabeca;

  if(iterator->proximo == NULL){
    free(iterator);
    cabeca = NULL;
  }else{

    cabeca = iterator->proximo;
    cabeca->proximo = iterator->proximo->proximo;

    free(iterator);
  }
  return cabeca;

}


int main (){

    Tno *cabeca;
    int opcao;
    long int endereco;
    long int quantidadeBytes;
    
      do{


        printf("\n 1-Empilhar \n 2- Desempilhar \n 3- imprimir \n 0- Sair \n ");
        scanf("%d",&opcao);

        switch(opcao){

          case 1:
            printf("\n Endereco de memoria : \n");
            scanf("%ld",&endereco);


            printf("\n Quantidade de Bytes : \n");
            scanf("%ld",&quantidadeBytes);

            cabeca = empilhar(cabeca,endereco,quantidadeBytes);

          break;
        
          case 2:
              

             cabeca = desempilhar(cabeca);

          break;
      

          case 3:
            
            vazia(cabeca);
            imprimir(cabeca);
          
          break;
        
      }

    }while(opcao);
        
    
return 0;

}
