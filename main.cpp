#include <stdio.h>
#include <fstream>
#include "list.hh"
#include "dynamic_array.hh"
#include "generator.hh"
#include "testy.hh"
#include <chrono>

// int main(){
//   // Zapis do pliku
//   std::ofstream output("wyniki.csv");
//   if (!output.is_open()) {
//     std::cerr << "Błąd otwierania." << std::endl;
//     return 1;
//   }
//   output << "n;Lista wiązana;Tablica dynamiczna\n";
//   // Zapis do pliku

//   // const size_t ile_powtorek = 100; // Przydałoby się chyba zrobić jakąś średnią z tych pomiarów co nie, ale nie wiem jak
  
//   const size_t rozmiar = 50000;
//   int min = -1000;
//   int max = 1000;
//   int danestartowe[rozmiar];
  
//   generujDane(danestartowe, rozmiar, 2137, min, max);

//   List lista;
//   DynamicArray tablica;
  
//   auto start = std::chrono::high_resolution_clock::now();
//   auto stop = std::chrono::high_resolution_clock::now();
//   auto czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//   auto czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//   for(size_t i=0;i<rozmiar;i++){
//     start = std::chrono::high_resolution_clock::now();
//     // lista.push_back(danestartowe[i]);
//     lista.push_front(danestartowe[i]);
//     stop = std::chrono::high_resolution_clock::now();
//     czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
//     start = std::chrono::high_resolution_clock::now();
//     // tablica.push_back(danestartowe[i]);
//     tablica.push_front(danestartowe[i]);
//     stop = std::chrono::high_resolution_clock::now();
//     czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//     output << i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
//   }

//   // std::cout << "Na pozycji 3 w tablicy: " << tablica.at_position(3) << "\n";
//   // // lista.at_position(3);

//   tablica._show();
//   lista._show();
//   output.close();
//   return 0;
// }

int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Wszystkie testy [0] |\nPush_front() [1]| Push_back() [2] | Push_at() [3] |\nRemove_front() [4] | Remove_back() [5] | Remove_at() [6] |\nat_position() [7] | find() [8]\n";
    return 1;
  }
  int test = std::stoi(argv[1]);
  int (*funkcje[])() = {push_front, push_back, push_at, remove_front, remove_back, remove_at, at_position};
  
  if(test == 0){
    for(int i=0;i<7;i++){
      funkcje[i]();
      std::cout << i << " zrobione pomyślnie!\n";
    }
    std::cout << "Sukces!\n";
  } else {
    funkcje[test-1]();
    std::cout << "Sukces!\n";
  }
  return 0;
}

// auto start = std::chrono::high_resolution_clock::now();
// xyz
// auto stop = std::chrono::high_resolution_clock::now();
// auto merge = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
