#include "testy.hh"
#include <sstream>

const size_t rozmiar = 50000;
int min = -10000;
int max = 10000;
const size_t ilesrednia = 5; //z ilu pomiarow liczymy srednia
const size_t coilelog = 100; //co ile bierzemy probke, dla 50 000 da to 500 próbek

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
  
  int danestartowe[rozmiar];
  std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
  std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
  generujDane(danestartowe, rozmiar, seed, min, max);

  //tyle razy z ilu bierzemy srednia
  for(size_t j = 0; j < ilesrednia; ++j) {
    List lista;
    DynamicArray tablica;
    //i teraz uzupelniamy tablice
    for(size_t i=0;i<rozmiar;i++){
      if(i%coilelog == 0) { //log co co_ile
	start = std::chrono::high_resolution_clock::now();
	lista.push_front(danestartowe[i]);
	stop = std::chrono::high_resolution_clock::now();
	pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	start = std::chrono::high_resolution_clock::now();
	tablica.push_front(danestartowe[i]);
	stop = std::chrono::high_resolution_clock::now();
	pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      }
      else {
	lista.push_front(danestartowe[i]);
	tablica.push_front(danestartowe[i]);
      }
    }
  }
  
  for(size_t i = 0; i < rozmiar/coilelog; ++i) {
    output << i*coilelog << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
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
  
  int danestartowe[rozmiar];
  std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
  std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
  generujDane(danestartowe, rozmiar, seed, min, max);

  //tyle razy z ilu bierzemy srednia
  for(size_t j = 0; j < ilesrednia; ++j) {
    List lista;
    DynamicArray tablica;
    //i teraz uzupelniamy tablice
    for(size_t i=0;i<rozmiar;i++){
      if(i%coilelog == 0) { //log co co_ile
	start = std::chrono::high_resolution_clock::now();
	lista.push_back(danestartowe[i]);
	stop = std::chrono::high_resolution_clock::now();
	pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	start = std::chrono::high_resolution_clock::now();
	tablica.push_back(danestartowe[i]);
	stop = std::chrono::high_resolution_clock::now();
	pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      }
      else {
	lista.push_back(danestartowe[i]);
	tablica.push_back(danestartowe[i]);
      }
    }
  }
  
  for(size_t i = 0; i < rozmiar/coilelog; ++i) {
    output << i*coilelog << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
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

  int danestartowe[rozmiar];
  std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
  std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  //tyle razy z ilu bierzemy srednia
  for(size_t j = 0; j < ilesrednia; ++j) {
    List lista;
    DynamicArray tablica;
    //bo zeby wstawiac na srodek to cos musi juz byc
    for(size_t i=0;i<=2;i++){
      lista.push_front(danestartowe[i]);
      tablica.push_front(danestartowe[i]);
    }
    //i teraz uzupelniamy tablice
    for(size_t i=3;i<rozmiar;i++){
      if((i-3)%coilelog == 0) { //log co co_ile
	start = std::chrono::high_resolution_clock::now();
	lista.push_at(int(i/2), danestartowe[i]);
	stop = std::chrono::high_resolution_clock::now();
	pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	start = std::chrono::high_resolution_clock::now();
	tablica.push_at(int(i/2), danestartowe[i]);
	stop = std::chrono::high_resolution_clock::now();
	pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      }
      else { //wydaje mi sie ze to nic nie zmienia jesli tu dam push_back, a bedzie na pewno szybciej bo to O(1)
	lista.push_back(danestartowe[i]);
	tablica.push_back(danestartowe[i]);
      }
    }
  }
  
  for(size_t i = 0; i < rozmiar/coilelog; ++i) {
    output << i*coilelog + 3 << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
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
    
    int danestartowe[rozmiar];
    std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
    std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
    generujDane(danestartowe, rozmiar, seed, min, max);
  
    //tyle razy z ilu bierzemy srednia
    for(size_t j = 0; j < ilesrednia; ++j) {
      List lista;
      DynamicArray tablica;
      //bo zeby usuwac to trzeba miec z czego
      for(size_t i=0;i<rozmiar;i++){
	lista.push_back(danestartowe[i]);
	tablica.push_back(danestartowe[i]);
      }
      //i teraz usuwamy z tablicy, ALE DLA ZERO NIE DA SIE USUNAC (kto by sie spodziewał?)
      for(size_t i=rozmiar;i>0;i--){
	if(i%coilelog == 0) { //log co co_ile
	  start = std::chrono::high_resolution_clock::now();
	  lista.remove_front();
	  stop = std::chrono::high_resolution_clock::now();
	  pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	  start = std::chrono::high_resolution_clock::now();
	  tablica.remove_front();
	  stop = std::chrono::high_resolution_clock::now();
	  pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	}
	else { 
	  lista.remove_back();
	  tablica.remove_back();
	}
      }
    }
  
    for(size_t i = 1; i < rozmiar/coilelog; ++i) {
      output << i*coilelog << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
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
  
  int danestartowe[rozmiar];
  std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
  std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  //tyle razy z ilu bierzemy srednia
  for(size_t j = 0; j < ilesrednia; ++j) {
    List lista;
    DynamicArray tablica;
    //bo zeby usuwac to trzeba miec z czego
    for(size_t i=0;i<rozmiar;i++){
      lista.push_back(danestartowe[i]);
      tablica.push_back(danestartowe[i]);
    }
    //i teraz usuwamy z tablicy, ALE DLA ZERO NIE DA SIE USUNAC (kto by sie spodziewał?)
    for(size_t i=rozmiar;i>0;i--){
      if(i%coilelog == 0) { //log co co_ile
	start = std::chrono::high_resolution_clock::now();
	lista.remove_back();
	stop = std::chrono::high_resolution_clock::now();
	pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	start = std::chrono::high_resolution_clock::now();
	tablica.remove_back();
	stop = std::chrono::high_resolution_clock::now();
	pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      }
      else { 
	lista.remove_back();
	tablica.remove_back();
      }
    }
  }
  
  for(size_t i = 1; i < rozmiar/coilelog; ++i) {
    output << i*coilelog << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
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

  int danestartowe[rozmiar];
  std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
  std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  //tyle razy z ilu bierzemy srednia
  for(size_t j = 0; j < ilesrednia; ++j) {
    List lista;
    DynamicArray tablica;
    //bo zeby usuwac to trzeba miec z czego
    for(size_t i=0;i<rozmiar;i++){
      lista.push_back(danestartowe[i]);
      tablica.push_back(danestartowe[i]);
    }
    //i teraz usuwamy z tablicy, ALE DLA ZERO NIE DA SIE USUNAC (kto by sie spodziewał?)
    for(size_t i=rozmiar;i>1;i--){
      if(i%coilelog == 0) { //log co co_ile
	start = std::chrono::high_resolution_clock::now();
	lista.remove_at(int(i/2));
	stop = std::chrono::high_resolution_clock::now();
	pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	start = std::chrono::high_resolution_clock::now();
	tablica.remove_at(int(i/2));
	stop = std::chrono::high_resolution_clock::now();
	pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      }
      else {
	lista.remove_back();
	tablica.remove_back();
      }
    }
  }
  
  for(size_t i = 1; i < rozmiar/coilelog; ++i) {
    output << i*coilelog << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
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

  int danestartowe[rozmiar];
  std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
  std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  //tyle razy z ilu bierzemy srednia
  for(size_t j = 0; j < ilesrednia; ++j) {
    List lista;
    DynamicArray tablica;
    //równolegle dodajemy elementy i szukamy srodkowego po wartosci, jak i jest zero to dla n=1, wiec w zapisywaniu teoretycznie musi byc +1
    for(size_t i=0;i<rozmiar;i++){
      lista.push_front(danestartowe[i]);
      tablica.push_front(danestartowe[i]);
      int val = lista.at_position(int(i/2))->value();
      int wartosc = tablica.at_position(int(i/2));
      if(i%coilelog == 0) { //log co co_ile
	start = std::chrono::high_resolution_clock::now();
	lista.find(val);
	stop = std::chrono::high_resolution_clock::now();
	pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	start = std::chrono::high_resolution_clock::now();
	tablica.find(wartosc);
	stop = std::chrono::high_resolution_clock::now();
	pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      }
    }
  }
  
  for(size_t i = 0; i < rozmiar/coilelog; ++i) {
    output << (i*coilelog)+1 << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
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
  
  int danestartowe[rozmiar];
  std::chrono::nanoseconds pomiarylista[rozmiar/coilelog] {};
  std::chrono::nanoseconds pomiarytablica[rozmiar/coilelog] {};
  generujDane(danestartowe, rozmiar, seed, min, max);
  
  //tyle razy z ilu bierzemy srednia
  for(size_t j = 0; j < ilesrednia; ++j) {
    List lista;
    DynamicArray tablica;
    //równolegle dodajemy elementy i szukamy srodkowego, jak i jest zero to dla n=1, wiec w zapisywaniu teoretycznie musi byc +1
    for(size_t i=0;i<rozmiar;i++){
      lista.push_front(danestartowe[i]);
      tablica.push_front(danestartowe[i]);
      if(i%coilelog == 0) { //log co co_ile
	start = std::chrono::high_resolution_clock::now();
	lista.at_position(i/2);
	stop = std::chrono::high_resolution_clock::now();
	pomiarylista[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
   
	start = std::chrono::high_resolution_clock::now();
	tablica.at_position(i/2);
	stop = std::chrono::high_resolution_clock::now();
	pomiarytablica[i/coilelog] += std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
      }
    }
  }
  
  for(size_t i = 0; i < rozmiar/coilelog; ++i) {
    output << (i*coilelog)+1 << ";" << pomiarylista[i].count()/ilesrednia  << ";"  << pomiarytablica[i].count()/ilesrednia << "\n";
  }
  
  output.close();
  return 0;
}
