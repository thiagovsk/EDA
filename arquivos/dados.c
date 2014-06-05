#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "video.h"

FILE *fileVideo;
FILE *fileSaida;

Tvideo *instala(Tvideo *raiz, char *codigo, char *titulo, char *midia, char *preco, char *genero){
    if(raiz != NULL){
        if(strcmp(codigo, raiz->codigo) <= 0){
            raiz->esq = instala(raiz->esq, codigo, titulo, midia, preco, genero);
            //printf("\ncodigo <= raiz->codigo: %s\n",raiz->nome);
        }
        else{
            raiz->dir = instala(raiz->dir, codigo, titulo, midia, preco, genero);
            //printf("\nelse: %s\n",raiz->nome);
        }        
        return raiz;
    }
    else{
        raiz = (Tvideo *) malloc(sizeof(Tvideo));
        raiz->codigo = codigo;
        raiz->titulo = titulo;
        raiz->midia = midia;
        raiz->preco = preco;
        raiz->genero = genero;
        raiz->esq = NULL;
        raiz->dir = NULL;
        return raiz;
    }
}

void PreFixEsq(Tvideo *raiz){
      if(raiz != NULL){
          PreFixEsq(raiz->esq);
          printf("\n%s\t%s\t%s\t%s\t%s\n", raiz->codigo, raiz->titulo, raiz->midia, raiz->preco, raiz->genero);
          fprintf(fileSaida, "%s\t%s\t%s\t%s\t%s\n", raiz->codigo, raiz->titulo, raiz->midia, raiz->preco, raiz->genero);
          PreFixEsq(raiz->dir);
      }
}

int main(){
    /*char *filme1 = "A.";
    char *filme2 = "A,";

    //strcmp(raiz->nome,nome) == 1 || strcmp(raiz->nome,nome) == 0
    printf("\n\t%d\n", strcmp(filme1,filme2));*/
    
    //Digite o nome do arquivo
    char nomeArquivo[50];
    printf("\nDigite o nome do arquivo com extensao: ");
    scanf("%s",nomeArquivo);

    Tvideo *raiz = NULL;

    //Abrindo arquivo
    fileVideo = fopen(nomeArquivo,"r");
    if (fileVideo == NULL)
    {
        printf("\n%s\n", "Arquivo nao encontrado");
    }

    fileSaida = fopen("VIDEOS_CODIGO.txt","w");
     if (fileVideo == NULL)
    {
        printf("\n%s\n", "Arquivo nao criado");
    }
    

    //Contando quantidade de linhas no arquivo
    char caractere = getc(fileVideo);
    int linhas = 0;
    while(caractere != EOF){
        if(caractere == '\n'){
            caractere = getc(fileVideo);
            linhas++;  
        }
        else 
             caractere = getc(fileVideo);
    }


    //restando o ponteiro do arquivo
    fclose(fileVideo);
    fileVideo = fopen("Videos.txt","r");
    if (fileVideo == NULL)
    {
        printf("\n%s\n", "Arquivo nao encontrado");
    }

    //Lendo cabeçalho para teste de leitura
    char codigoP[20];
    char tituloP[20];
    char midiaP[20];
    char precoP[20];
    char generoP[20];
    fscanf(fileVideo,"%s %s %s %s %s\n",codigoP, tituloP, midiaP, precoP, generoP);
    printf("\n%s\t%s\t%s\t%s\t%s\n", codigoP, tituloP, midiaP, precoP, generoP);

    //Construindo a arvore
    int espaco_codigo = 15, espaco_titulo = 100, espaco_midia = 10, espaco_preco = 10, espaco_genero = 30;  
    char videos_titulo[linhas][espaco_titulo];
    char videos_midia[linhas][espaco_midia];
    char videos_preco[linhas][espaco_preco];
    char videos_genero[linhas][espaco_genero];
    char videos_codigo[linhas][espaco_codigo];
    int i;
    char codigo[espaco_codigo], titulo[espaco_titulo], midia[espaco_midia], preco[espaco_preco], genero[espaco_genero];
    float precoI;
    for (i = 0; i < linhas; ++i)
    {
        fscanf(fileVideo,"%[A-Z0-9] %s %[0-9A-Z-/+] %[0-9.] %[A-Z]\n", codigo, titulo, midia, preco, genero);
        //printf("\n%s\t%s\t%s\t%s\t%s\n", codigo, titulo, midia, preco, genero);
        //Copiando os dados para as tabelas
        strcpy(videos_codigo[i], codigo);
        strcpy(videos_titulo[i], titulo);
        strcpy(videos_midia[i], midia);
        strcpy(videos_preco[i], preco);
        strcpy(videos_genero[i], genero);
        //printf("\n%s\t%s\t%s\t%s\t%s\n", videos_codigo[i], videos_titulo[i], videos_midia[i], videos_preco[i], videos_genero[i]);
        raiz = instala(raiz, videos_codigo[i], videos_titulo[i], videos_midia[i], videos_preco[i], videos_genero[i]);
    }

    PreFixEsq(raiz);



    printf("\n\n\tFIM\n\n");
    return 0;
}