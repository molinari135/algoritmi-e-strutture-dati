#include <cstring>
#include <iostream>
#include "codavt.h"
#include "pilavt.h"

using namespace std;

int valuta_polacca(Coda<char> post) {
  Pila<int> pila;
  pila.creaPila();
  while (!post.codaVuota()) {
    char t=post.leggiCoda();
    post.fuoriCoda();
    if (t>='0' && t<='9') {
      int n=t-'0';
      while (t!=' ') {
        t=post.leggiCoda();
        post.fuoriCoda();
        if (t>='0' && t<='9') {
          n=n*10+(t-'0');
        }
      }
      cout << n << endl;
      pila.inPila(n);
    } else if (t=='+' || t=='-' || t=='*' || t=='/') {
      double numtop = pila.leggiPila();
      pila.fuoriPila();
      double numsuc = pila.leggiPila();
      pila.fuoriPila();
      double ris;
      if (t == '+')
        ris = numsuc + numtop;
      if (t == '-')
        ris = numsuc - numtop;
      if (t == '*')
        ris = numsuc * numtop;
      if (t == '/')
        ris = numsuc / numtop;
      pila.inPila(ris);
    }
  }
  int ris=pila.leggiPila();
  return ris;
}

int main(int argc, char *argv[]) {
	if (argc>1) {
		char *a = argv[1]; int N = strlen(a);
		Coda<char> coda(N);
		for (int i=0;i<N;i++) {
			coda.inCoda(a[i]);
		}
		cout << valuta_polacca(coda) << endl;
	}
	return 0;
}
