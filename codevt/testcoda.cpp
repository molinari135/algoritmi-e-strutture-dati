#include "codavt.h"
#include <iostream>

using namespace std;

int main(){

  Coda<int> C(3);

  C.inCoda(1);
  C.inCoda(2);
  C.inCoda(3);

  Coda<int> B=C;
  cout << ((B==C) ? "VERO" : "FALSO") << endl;
  B.fuoriCoda();
  cout << ((B==C) ? "VERO" : "FALSO") << endl;
  cout << B.leggiCoda() << endl;
  B.fuoriCoda();
  cout << C.leggiCoda() << endl;
  C.fuoriCoda();
  cout << C.leggiCoda() << endl;
}
