#include <stdio.h>
#include "list.hh"
#include "dynamic_array.hh"
#include "generator.hh"

int main(){
  const size_t rozmiar = 21;
  int min = -50;
  int max = 250;
  int danestartowe[rozmiar];
  
  generujDane(danestartowe, rozmiar, 2137, min, max);

  List lista;
  DynamicArray tablica;
  
  for(size_t i=0;i<rozmiar;i++){
    lista.push_back(danestartowe[i]);
    tablica.push_back(danestartowe[i]);
  }

  std::cout << "Na pozycji 3 w tablicy: " << tablica.at_position(3) << "\n";
  // lista.at_position(3);

  tablica._show();
  lista._show();
  return 0;
}
