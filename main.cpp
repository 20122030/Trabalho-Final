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