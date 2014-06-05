#include<stdio.h>
#include<stdlib.h>

typedef struct Tno{


    int numero;
    struct Tno *proximo;

}Tno ;

void imprimir(Tno *lista){

    Tno *iterator;
    iterator = (Tno *) malloc(sizeof(Tno));

    iterator = lista;



    while(iterator != NULL){


        printf("%d ",iterator->numero );
        iterator = iterator->proximo;

        if (iterator->numero == lista->numero){
            printf("\nFim de execução\n");
            break;
        }
    }

}

Tno *incluirCabeca(Tno *lista, int valor){

    Tno *novo;
    novo = (Tno *) malloc(sizeof(Tno));

    novo->numero = valor;
    
    novo->proximo = lista;
    lista = novo;

    return lista;

}

Tno *incluirCalda(Tno *lista, int valor){

    Tno *novo,*iterator;

    novo = (Tno *) malloc(sizeof(Tno));

    novo->numero = valor;
    iterator = lista;

    while(iterator->proximo  != NULL){

        iterator = iterator->proximo;
        
        if(iterator->proximo == lista){


          iterator->proximo = novo;
          novo->proximo = lista;
          break;
        }
    }

    iterator->proximo = novo;
    novo->proximo = lista;

    return lista;

}



Tno * ExcluiCabeca(Tno *lista){

  Tno *iterator;

  iterator = (Tno *) malloc(sizeof(Tno));
  
  iterator = lista;

  lista = iterator->proximo;
  lista->proximo = iterator->proximo->proximo;

  free(iterator);

  return lista;


}

Tno * Excluicalda(Tno *lista){

  Tno *iterator;

  iterator = (Tno *) malloc(sizeof(Tno));
  
  iterator = lista;

  while(iterator->proximo->proximo != NULL){

    iterator = iterator->proximo;
  }

  free(iterator->proximo);
  iterator->proximo = NULL;

  
  return lista;


}

  


int main (){

    Tno *lista,*cabeca;
    
    

    lista = incluirCabeca(lista,0);
    incluirCalda(lista,2);
    incluirCalda(lista,3);
    incluirCalda(lista,4);
    incluirCalda(lista,5);

  
    imprimir(lista);


return 0;

}
