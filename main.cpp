#include <stdio.h>
#include "list.hh"
#include "dynamic_array.hh"

int main(){
  List lista;
  DynamicArray tablica;

  lista.push_back(10);
  lista.push_back(5);
  lista.push_back(1);
  lista.push_front(-2);
  lista.push_front(-1);

  tablica.push_back(10);
  tablica.push_back(5);
  tablica.push_back(1);
  tablica.push_front(-2);
  tablica.push_front(-1);

  std::cout << "Na pozycji 3 w tablicy: " << tablica.at_position(3) << "\n";
  // lista.at_position(3);

  tablica._show();
  lista._show();
  return 0;
}
