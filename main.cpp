#include <stdio.h>
#include "list.hh"

int main(){
  List lista;

  lista.push_back(10);
  lista.push_back(5);
  lista.push_back(1);
  lista.push_front(-2);
  lista.push_front(-1);

  lista._show();
  return 0;
}
