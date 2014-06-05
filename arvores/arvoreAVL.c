/* arvores binárias de pesquisa - balanceamento dinâmico pelo processo
AVL (Adelson-Velskii e Landis)
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
  char dado;
  int fatbal;
  struct nodo *esq, *dir;
} arvoreAVL;

//-------------------------------------------
void LeArv(arvoreAVL **eainicio) {
  if (*eainicio == NULL) 
    printf (".");
  else {
    printf ("%c" , (*eainicio)->dado);
    LeArv (&((*eainicio)->esq));
    LeArv (&((*eainicio)->dir));  
  }
}

void InicializaAVL (arvoreAVL **eainicio){
  *eainicio = malloc (sizeof (arvoreAVL));
  (*eainicio)->esq = NULL;
  (*eainicio)->dir = NULL;
  }

void InsereAVL (arvoreAVL *adesc, char dadonovo) {
  arvoreAVL *paux, *pant, *pP, *pQ, *pantP, *pnovo;
  int poschave;
  int achou; 

void RotacaoSimples (){
  if (pP->fatbal == 1) {
    pP->dir = pQ->esq;
    pQ->esq = pP;
  }
  else {
    pP->esq = pQ->dir;
    pQ->dir = pP;
  }
  paux = pQ;
  pP->fatbal = 0;
  pQ->fatbal = 0;
}

void RotacaoDupla (){
  if (pP->fatbal == 1) {
    paux = pQ->esq;
    pQ->esq = paux->dir;
    paux->dir = pQ;
    pP->dir = paux->esq;
    paux->esq = pP;
  }
  else {
    paux = pQ->dir;
    pQ->dir = paux->esq;
    paux->esq = pQ;
    pP->esq = paux->dir;
    paux->dir = pP;
  }
  if (paux->fatbal == -poschave){
    pP->fatbal = 0;
    pQ->fatbal = poschave;
  }
  else 
    if (paux->fatbal == 0) {
      pP->fatbal = 0;
      pQ->fatbal = 0;
    }
    else {
      pP->fatbal = -poschave;
      pQ->fatbal = 0;
    }
  paux->fatbal = 0;
}

void AjustaFatoresAVL (){
  if (dadonovo < pP->dado){
    pQ = pP->esq;
    paux = pP->esq;
  }
  else {
    pQ = pP->dir;
    paux = pP->dir;
  }
  while (paux->dado != dadonovo)
    if (dadonovo < paux->dado) {
      paux->fatbal = paux->fatbal - 1;
      paux = paux->esq;
    }
    else {
      paux->fatbal = paux->fatbal + 1;
      paux = paux->dir;
    }
}
void BalanceiaAVL (){
  if (dadonovo < pP->dado)
    poschave = -1;
  else
    poschave = 1;
  if (pP->fatbal == 0)
    pP->fatbal = poschave;
  else 
    if (pP->fatbal == -poschave)
      pP->fatbal = 0;
    else {
      if (pQ->fatbal * poschave > 0)
        RotacaoSimples ();
      else
        RotacaoDupla ();
      if (pantP->dir == pP)
        pantP->dir = paux;
      else
        pantP->esq = paux;
    }
}
  paux = adesc->dir;
  pP = paux;
  pant = adesc;
  pantP = adesc;
  achou = 0;
  while ((!achou) && (paux != NULL)) {
    if (paux->fatbal != 0) {
      pP = paux;
      pantP = pant;
    }
    pant = paux;
    if (dadonovo == paux->dado)
      achou = 1;
    else
      if (dadonovo < paux->dado)
        paux = paux->esq;
      else
        paux = paux->dir;
  }
  if (achou)
    printf("este dado ja esta presente na arvore\n");
  else {
    pnovo = malloc (sizeof (arvoreAVL));
    pnovo->dado = dadonovo;
    pnovo->esq = NULL;
    pnovo->dir = NULL;
    pnovo->fatbal = 0;
    if (adesc->dir == NULL)
      adesc->dir = pnovo;
    else {
      if (dadonovo < pant->dado)
        pant->esq = pnovo;
      else
        pant->dir = pnovo;
      AjustaFatoresAVL ();
      BalanceiaAVL ();
    }
  }
}

//--------------------------------------------
main ()
{
  arvoreAVL *aini;
  char c, resp;
  
  InicializaAVL (&aini);  
  printf ("deseja entrar um primeiro valor na arvore? (s/n)\n");
  fflush(stdin);
  scanf ("%c" , &resp);
  while (resp == 's') {
    printf ("entre com valor a ser inserido na arvore\n");
    fflush(stdin);
    scanf ("%c" , &c);  
    InsereAVL (aini, c);
    printf ("deseja entra mais algum valor? (s/n)\n");
    fflush(stdin);
    scanf ("%c" , &resp);
  }

  LeArv (&((aini)->dir));

}