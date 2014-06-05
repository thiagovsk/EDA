typedef struct ponto Ponto;

//cria um novo ponto
Ponto* ponto_criar(float x, float y);

//libera um ponto
void ponto_liberar(Ponto* p);

//Acessa os valores do ponto por referencia
void ponto_acessar(Ponto* p,float* x,float* y);

//Acessa os valores do ponto por parametro
 void ponto_atribuir(Ponto* p,float x,float y);

//calcula a distancia de 2 pontos
float ponto_distancia(Ponto* p1, Ponto* p2);
