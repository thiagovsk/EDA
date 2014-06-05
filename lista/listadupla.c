#include<stdio.h>
#include<stdlib.h>

typedef struct Tno{


    int numero;
    struct Tno *proximo;
    struct Tno *anterior;

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

    while(iterator->proximo != NULL){

        printf("%d ",iterator->numero );
        iterator = iterator->proximo;
        
    }

}

Tno *incluirCabeca(Tno *lista, int valor){

    Tno *novo;
    novo = (Tno *) malloc(sizeof(Tno));

    novo->numero = valor;
    novo->anterior = NULL;  
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
    novo->anterior = lista;

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
    novo->anterior = iterator;
    iterator->proximo->anterior = novo;

    iterator->proximo = novo;
    
    return lista;

}


Tno * ExcluiCabeca(Tno *lista){


  lista = lista->proximo;

  free(lista->anterior);

  lista->anterior = NULL;

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

  Tno *iterator;

  iterator = (Tno *) malloc(sizeof(Tno));
  
  iterator = lista;

  while(iterator->numero == chave){

    iterator = iterator->proximo;
  }

  iterator->proximo->anterior = iterator->proximo;
  iterator->anterior->proximo = iterator->anterior;

  free(iterator);
  
  return lista;

}


int main (){

    Tno *lista;
    
    lista = incluirCabeca(lista,1);
    incluirCalda(lista,2);
    incluirCalda(lista,3);
    incluirCalda(lista,4);
    incluirCalda(lista,5);

    //ExcluiCabeca(lista);
    //Excluicalda(lista);

  
    imprimir(lista);


return 0;

}
