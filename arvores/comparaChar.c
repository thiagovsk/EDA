#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//estrutura da arvore
struct Tno{
    
    struct Tno* esquerda;
    struct Tno* direita;
    struct Elemento *elemento;
    
};

typedef struct Tno Tno;

struct Elemento{
    char *codigo;
    char *titulo;
    char *midia;
    char *genero;
    char *preco;

};


typedef struct Elemento Elemento;

FILE *arquivoEntrada;    
FILE *arquivoSaida;
Elemento *elemento;

Tno *Inserir_no(Tno *noArvore, char *codigo, char *titulo, char *midia, char *preco, char *genero){
   
    if(noArvore != NULL){

        if(strcmp(codigo, noArvore->elemento->codigo) <= 0){
            noArvore->esquerda = Inserir_no(noArvore->esquerda, codigo, titulo, midia, preco, genero);
        }
        else{
            noArvore->direita = Inserir_no(noArvore->direita, codigo, titulo, midia, preco, genero);
        }        
        return noArvore;
    }
    else{
        
        noArvore = (Tno *) malloc(sizeof(Tno));
        elemento = (Elemento *) malloc(sizeof(Elemento));

        elemento->codigo = codigo;
        elemento->titulo = titulo;
        elemento->midia = midia;
        elemento->preco = preco;
        elemento->genero = genero;
        noArvore->elemento = elemento;

        noArvore->esquerda = NULL;
        noArvore->direita = NULL;
        return noArvore;
    }
}

void PreFixesquerda(Tno *noArvore){
      if(noArvore != NULL){
          PreFixesquerda(noArvore->esquerda);
          fprintf(arquivoSaida, "%s %s %s %s %s\n", noArvore->elemento->codigo, noArvore->elemento->titulo, noArvore->elemento->midia, noArvore->elemento->preco, noArvore->elemento->genero);
          PreFixesquerda(noArvore->direita);
      }
}

int main(){

    //declarando a raiz NULL
    Tno *noArvore = NULL;
       
    //alocando memoria para os campos da struct e o nome do arquivo a ser lido
    char *nomeArquivo = (char*) malloc(sizeof(char)*15);
    
    printf("\nDigite o arquivo de entrada : ");
    scanf("%s",nomeArquivo);


    //Abrindo arquivo
    arquivoEntrada = fopen(nomeArquivo,"r");
    if (arquivoEntrada == NULL) {
        printf("\n%s\n", "Arquivo nao encontrado");
    }

    arquivoSaida = fopen("VIDEOS_CODIGO.txt","w");
     if (arquivoEntrada == NULL)
    {
        printf("\n%s\n", "Arquivo nao criado");
    }
    

    //Contar o tamanho do arquivo
    char caractere = getc(arquivoEntrada);
    int linhas = 0;
    while(caractere != EOF){
        if(caractere == '\n'){
            caractere = getc(arquivoEntrada);
            linhas++;  
        }
        else 
             caractere = getc(arquivoEntrada);
    }


    //abrindo arquivo modo leitura
    fclose(arquivoEntrada);
    arquivoEntrada = fopen("Videos.txt","r");

    //Lendo cabeçalho para teste de leitura
    char codigoCabebcalho[10],  tituloCabecalho[10],  midiaCabebcalho[10];
    char precoCabecalho[10],  generoCabecalho[10];

    fscanf(arquivoEntrada,"%s %s %s %s %s\n",codigoCabebcalho, tituloCabecalho, midiaCabebcalho, precoCabecalho, generoCabecalho);

    // vetor de copias dos elementos
    char copiaTitulo[linhas][100];
    char copiaMedia[linhas][100];
    char copiaPreco[linhas][10];
    char copiaGenero[linhas][100];
    char copiaCodigo[linhas][50];
    
    int iterator;

    char codigo[50];
    char titulo[100];
    char midia[10];
    char preco[10];
     char genero[50];
    
    float precoI;
    for (iterator = 0; iterator < linhas; ++iterator)
    {
        fscanf(arquivoEntrada,"%s %s %s %s %s\n", codigo, titulo, midia, preco, genero);

        //copiar elementos para não atrapalahar os ponteiros
        strcpy(copiaCodigo[iterator], codigo);
        strcpy(copiaTitulo[iterator], titulo);
        strcpy(copiaMedia[iterator], midia);
        strcpy(copiaPreco[iterator], preco);
        strcpy(copiaGenero[iterator], genero);
        noArvore = Inserir_no(noArvore , copiaCodigo[iterator], copiaTitulo[iterator], copiaMedia[iterator], copiaPreco[iterator], copiaGenero[iterator]);
    }

    PreFixesquerda(noArvore);

    printf("Arquivo exportado com sucesso procure por : VIDEOS_CODIGO.txt");
    return 0;
}