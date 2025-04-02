#include "testy.hh"
#include <sstream>

const size_t rozmiar = 50000;
int min = -10000;
int max = 10000;

auto start = std::chrono::high_resolution_clock::now();
auto stop = std::chrono::high_resolution_clock::now();
auto czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
auto czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

// Wiadomo
int push_front(uint16_t seed, uint8_t proba){
  // Zapis do pliku
  std::ostringstream filename;
  filename << "push_front" << static_cast<int>(proba) << ".csv"; 
  std::ofstream output(filename.str());
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, seed, min, max);

  for(size_t i=0;i<rozmiar;i++){
    start = std::chrono::high_resolution_clock::now();
    lista.push_front(danestartowe[i]);
    stop = std::chrono::high_resolution_clock::now();
    czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    start = std::chrono::high_resolution_clock::now();
    tablica.push_front(danestartowe[i]);
    stop = std::chrono::high_resolution_clock::now();
    czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    output << i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
  }
  output.close();
  return 0;
}

// Wiadomo
int push_back(uint16_t seed, uint8_t proba){
  // Zapis do pliku
  std::ostringstream filename;
  filename << "push_back" << static_cast<int>(proba) << ".csv"; 
  std::ofstream output(filename.str());
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, seed, min, max);

  for(size_t i=0;i<rozmiar;i++){
    start = std::chrono::high_resolution_clock::now();
    lista.push_back(danestartowe[i]);
    stop = std::chrono::high_resolution_clock::now();
    czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    start = std::chrono::high_resolution_clock::now();
    tablica.push_back(danestartowe[i]);
    stop = std::chrono::high_resolution_clock::now();
    czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    output << i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
  }
  output.close();
  return 0;
}

// Wstawia wartosc na srodek
int push_at(uint16_t seed, uint8_t proba){
  // Zapis do pliku
  std::ostringstream filename;
  filename << "push_at" << static_cast<int>(proba) << ".csv"; 
  std::ofstream output(filename.str());
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, seed, min, max);
  for(size_t i=0;i<=2;i++){
    lista.push_front(danestartowe[i]);
    tablica.push_front(danestartowe[i]);
  }
  for(size_t i=3;i<rozmiar;i++){
    start = std::chrono::high_resolution_clock::now();
    lista.push_at(int(i/2), danestartowe[i]);
    stop = std::chrono::high_resolution_clock::now();
    czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    start = std::chrono::high_resolution_clock::now();
    tablica.push_at(int(i/2), danestartowe[i]);
    stop = std::chrono::high_resolution_clock::now();
    czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    output << i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
  }
  output.close();
  return 0;
}

// Wiadomo
int remove_front(uint16_t seed, uint8_t proba){
    // Zapis do pliku
    std::ostringstream filename;
    filename << "remove_front" << static_cast<int>(proba) << ".csv"; 
    std::ofstream output(filename.str());
    if (!output.is_open()) {
      std::cerr << "Błąd otwierania." << std::endl;
      return 1;
    }
    output << "n;Lista wiązana;Tablica dynamiczna\n";
    // Zapis do pliku  
  
    List lista;
    DynamicArray tablica;
    
    int danestartowe[rozmiar];
    generujDane(danestartowe, rozmiar, seed, min, max);
    
    for(size_t i=0;i<rozmiar;i++){
      lista.push_back(danestartowe[i]);
      tablica.push_back(danestartowe[i]);
    }
    
    for(size_t i=0;i<rozmiar;i++){
      start = std::chrono::high_resolution_clock::now();
      lista.remove_front();
      stop = std::chrono::high_resolution_clock::now();
      czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      
      start = std::chrono::high_resolution_clock::now();
      tablica.remove_front();
      stop = std::chrono::high_resolution_clock::now();
      czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      output << rozmiar-i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
    }
    output.close();
    return 0;
}

// Wiadomo
int remove_back(uint16_t seed, uint8_t proba){
  // Zapis do pliku
  std::ostringstream filename;
  filename << "remove_back" << static_cast<int>(proba) << ".csv"; 
  std::ofstream output(filename.str());
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  for(size_t i=0;i<rozmiar;i++){
    lista.push_back(danestartowe[i]);
    tablica.push_back(danestartowe[i]);
  }
  
  for(size_t i=0;i<rozmiar;i++){
    start = std::chrono::high_resolution_clock::now();
    lista.remove_back();
    stop = std::chrono::high_resolution_clock::now();
    czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    start = std::chrono::high_resolution_clock::now();
    tablica.remove_back();
    stop = std::chrono::high_resolution_clock::now();
    czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    output << rozmiar-i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
  }
  output.close();
  return 0;
}

// Usuwa ze srodka
int remove_at(uint16_t seed, uint8_t proba){
  // Zapis do pliku
  std::ostringstream filename;
  filename << "remove_at" << static_cast<int>(proba) << ".csv"; 
  std::ofstream output(filename.str());
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  for(size_t i=0;i<rozmiar;i++){
    lista.push_back(danestartowe[i]);
    tablica.push_back(danestartowe[i]);
  }
  
  for(size_t i=0;i<rozmiar;i++){
    start = std::chrono::high_resolution_clock::now();
    lista.remove_at(int((rozmiar-i)/2));
    stop = std::chrono::high_resolution_clock::now();
    czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    start = std::chrono::high_resolution_clock::now();
    tablica.remove_at(int((rozmiar-i)/2));
    stop = std::chrono::high_resolution_clock::now();
    czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    output << rozmiar-i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
  }
  output.close();
  return 0;
}

// Nie wiem co wymyslic do tego -- jednak wymyslilem, bedzie znajdowac to co na srodku ale po wartosci
// NEURON ACTIVATION
int find(uint16_t seed, uint8_t proba){
  // Zapis do pliku
  std::ostringstream filename;
  filename << "find" << static_cast<int>(proba) << ".csv"; 
  std::ofstream output(filename.str());
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  for(size_t i=0;i<rozmiar;i++){
    lista.push_front(danestartowe[i]);
    tablica.push_front(danestartowe[i]);
    int val = lista.at_position(int(i/2))->val;
    int wartosc = tablica.at_position(int(i/2));

    start = std::chrono::high_resolution_clock::now();
    lista.find(val);
    stop = std::chrono::high_resolution_clock::now();
    czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    start = std::chrono::high_resolution_clock::now();
    tablica.find(wartosc);
    stop = std::chrono::high_resolution_clock::now();
    czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    output << i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
  }

  output.close();
  return 0;
}

// Szuka wartosci na srodku
int at_position(uint16_t seed, uint8_t proba){
  // Zapis do pliku
  std::ostringstream filename;
  filename << "at_position" << static_cast<int>(proba) << ".csv"; 
  std::ofstream output(filename.str());
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  for(size_t i=0;i<rozmiar;i++){
    lista.push_front(danestartowe[i]);
    tablica.push_front(danestartowe[i]);

    start = std::chrono::high_resolution_clock::now();
    lista.at_position(int(i/2));
    stop = std::chrono::high_resolution_clock::now();
    czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    
    start = std::chrono::high_resolution_clock::now();
    tablica.at_position(int(i/2));
    stop = std::chrono::high_resolution_clock::now();
    czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    output << i << ";" << czas_lista.count()  << ";"  << czas_tablica.count() << "\n";
  }
  
  output.close();
  return 0;
}