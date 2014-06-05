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

void primeiro(Tno *lista){

    
    printf("Prieiro elemento da fila %d\n",lista->numero );
    
    
}


Tno *incluirCabeca(Tno *lista, int valor){

    Tno *novo;
    novo = (Tno *) malloc(sizeof(Tno));

    novo->numero = valor;
    
    novo->proximo = lista;
    lista = novo;

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


int main (){

    Tno *lista,*cabeca;
    
    

    lista = incluirCabeca(lista,1);
    lista = incluirCabeca(lista,1);
    lista = incluirCabeca(lista,1);
    lista = incluirCabeca(lista,1);
      
  
    imprimir(lista);
    primeiro(lista);

return 0;

}
