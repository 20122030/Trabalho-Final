#include <iostream>
#include <fstream>

using namespace std;

struct tCircuito{
  
  int valorR1;
  int valorR2;
  int valorFonte;
};

//código ensinado pelo professor

struct tNo{
  tCircuito data;
  tNo* proximo;
};
tNo* criaNo(int r1, int r2, int fonte){
  tNo* no = new tNo;

  no -> data.valorR1 = r1;
  no -> data.valorR2 = r2;
  no -> data.valorFonte = fonte;
  no -> proximo = NULL;

  return no;
}

struct tLista{
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho;
};

void inicializaLista(tLista* pLista){
  pLista -> primeiro = NULL;
  pLista -> ultimo = NULL;
  pLista -> marcador = NULL;
  pLista -> tamanho = 0;
}

int obterTamanho(tLista* pLista){
  return pLista->tamanho;
}

bool listaVazia(tLista* pLista){
  return (pLista -> tamanho == 0);
}

bool finalLista(tLista* pLista){
  return (pLista->marcador == NULL);
}

void incluirNoFim(tLista* pLista, int r1, int r2, int fonte){
  tNo* no;
  no = criaNo(r1,r2,fonte);

  if(listaVazia(pLista)){
    pLista -> primeiro = no;
  }
  else{
    pLista -> ultimo -> proximo = no;
  }

  pLista -> ultimo = no;
  pLista -> marcador = no;
  pLista -> tamanho++;
}
