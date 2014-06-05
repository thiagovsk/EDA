

#include<stdio.h>
#include<stdlib.h>

typedef struct Tno{

    long int endereco;
    long int quantidadeBytes;
    int id;
    struct Tno *proximo;

}Tno ;

void imprimir(Tno *cabeca){

    Tno *iterator;
    iterator = (Tno *) malloc(sizeof(Tno));

    iterator = cabeca;

    if (iterator->proximo == NULL)
    {
      printf("FILA VAZIA ");

    }


    while(iterator != NULL){

        if (iterator->id == 0)
        {
          printf("\n FILA de Enderecos \n");
        }else{
         printf("\n ID = %ld Endereco = %ld  Quantidade de bytes = %ld \n",iterator->id,iterator->endereco,iterator->quantidadeBytes );
        }

        iterator = iterator->proximo;


        if (iterator->id == cabeca->id){
            printf("\nFim de execução\n");
            break;
        }
    }

}

Tno *enfileirarPrimeiro(Tno *cabeca, int id, long int endereco, long int quantidadeBytes){

    Tno *novo;
    novo = (Tno *) malloc(sizeof(Tno));

    novo->id = id;
    novo->endereco = endereco;
    novo->quantidadeBytes = quantidadeBytes;
    
    novo->proximo = cabeca;
    cabeca = novo;

    return cabeca;

}

Tno *enfileirar(Tno *cabeca, int id, long int endereco, long int quantidadeBytes){

    Tno *novo,*iterator;

    novo = (Tno *) malloc(sizeof(Tno));
    novo->id = id;
    novo->endereco = endereco;
    novo->quantidadeBytes = quantidadeBytes;


    iterator = cabeca;

    while(iterator->proximo  != NULL){

        iterator = iterator->proximo;
        
        if(iterator->proximo == cabeca){


          iterator->proximo = novo;
          novo->proximo = cabeca;
          break;
        }
    }

    iterator->proximo = novo;
    novo->proximo = cabeca;

    return cabeca;

}




Tno * desenfileirar(Tno *cabeca){

 Tno *iterator;

  iterator = (Tno *) malloc(sizeof(Tno));
  
  iterator = cabeca;

  cabeca = iterator->proximo;
  cabeca->proximo = iterator->proximo->proximo;

  free(iterator);

  return cabeca;


  
  return cabeca;


}

  


int main (){

    Tno *cabeca;
    
    

    cabeca = enfileirarPrimeiro(cabeca,0,0,0);
    enfileirar(cabeca,1,1,1);
    enfileirar(cabeca,2,2,2);
    enfileirar(cabeca,3,3,3);
    enfileirar(cabeca,4,4,4);
    enfileirar(cabeca,5,5,5);
    enfileirar(cabeca,6,6,6);
    enfileirar(cabeca,7,7,7);

  
    imprimir(cabeca);

    desenfileirar(cabeca);
    desenfileirar(cabeca);
    desenfileirar(cabeca);
    desenfileirar(cabeca);
    desenfileirar(cabeca);
    desenfileirar(cabeca);
    desenfileirar(cabeca);
    desenfileirar(cabeca);


    imprimir(cabeca);

return 0;

}
