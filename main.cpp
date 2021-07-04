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

void imprimirLista(tLista* pLista){
  pLista->marcador = pLista->primeiro;

  while(!finalLista(pLista)){
    //uma variavel pra cada dado
    int res1 = pLista->marcador->data.valorR1;
    int res2 = pLista->marcador->data.valorR2;
    int vFonte = pLista->marcador->data.valorFonte;
    cout << "R1: " << res1 <<" ";
    cout << "R2: " << res2 <<" ";
    cout << "Fonte: " << vFonte <<endl;
    
    pLista->marcador = pLista->marcador->proximo;
  }
}

void gravarDados(tLista* pLista){

  ofstream banco("bancoDeDados.txt");
  //enquanto n for o final da lista, gravar no arquivo
  
  pLista->marcador = pLista->primeiro;
  int ultimaLinha= obterTamanho(pLista);
  int aux=0;

  while(!finalLista(pLista)){
        
    banco << pLista->marcador->data.valorR1 <<" "<<pLista->marcador->data.valorR2<<" "<<pLista->marcador->data.valorFonte;
      
    if(aux < ultimaLinha-1){
      banco << endl;
      aux++;
    }
      pLista->marcador = pLista->marcador->proximo;
    
  }

  banco.close();

}

void excluirPosicao(tLista* pLista){
  tNo* anterior;
  tNo* aux;
  tNo* apagado;

  if(!listaVazia(pLista)){
    pLista->marcador = pLista->primeiro;

    while(!finalLista(pLista)){
      aux = pLista->marcador->proximo;
      apagado = pLista->marcador;
      free(apagado);
      pLista->marcador = aux;
        
    }
    inicializaLista(pLista);
   
  }
}







int main() {

  int r1,r2,fonte,opcao;

  tLista* circuito = new tLista;
