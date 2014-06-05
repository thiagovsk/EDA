#include<stdio.h>
#include<stdlib.h>

typedef struct Tno{


    int numero;
    struct Tno *proximo;

}Tno ;

int vazia(Tno *lista){

    if(lista == NULL)
        return 0;

    else
        return 1;
}


void imprimir(Tno *lista){

    Tno *iterator;
    iterator = (Tno *) malloc(sizeof(Tno));

    iterator = lista;

    while(iterator != NULL){

        printf("%d ",iterator->numero );
        iterator = iterator->proximo;

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
    iterator = lista;

    novo->numero = valor;
    novo->proximo = NULL;

    iterator = lista;

    while(iterator->proximo  != NULL){

        iterator = iterator->proximo;
    }

    iterator->proximo = novo;

    return lista;

}


Tno *incluirChave(Tno *lista, int valor, int chave){

    Tno *novo,*iterator;

    novo = (Tno *) malloc(sizeof(Tno));
  
    iterator = lista;

    novo->numero = valor;
  
    iterator = lista;

    while(iterator->proximo->numero  != chave){

        iterator = iterator->proximo;
    }

    novo->proximo = iterator->proximo;

    iterator->proximo = novo;
    
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


Tno * ExcluiChave(Tno *lista,int chave){

  Tno *anterior,*posterior;

  anterior = (Tno *) malloc(sizeof(Tno));
  posterior = (Tno *) malloc(sizeof(Tno));
  
  anterior = lista;

  while(anterior->proximo->numero != chave){

    anterior = anterior->proximo;

  }
  
  posterior = anterior->proximo->proximo;



  free(anterior->proximo);
  anterior->proximo = posterior;

  
  return lista;


}


int main (){

    Tno *lista,*cabeca;
    
    

    lista = incluirCabeca(lista,1);
    incluirCalda(lista,2);
    incluirCalda(lista,3);
    incluirCalda(lista,4);
    incluirCalda(lista,5);

  
    imprimir(lista);


return 0;

}
