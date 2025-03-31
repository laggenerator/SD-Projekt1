#include "testy.hh"

const size_t rozmiar = 50000;
int min = -10000;
int max = 10000;

auto start = std::chrono::high_resolution_clock::now();
auto stop = std::chrono::high_resolution_clock::now();
auto czas_lista = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
auto czas_tablica = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

// Wiadomo
int push_front(){
  // Zapis do pliku
  std::ofstream output("push_front.csv");
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, 2137, min, max);

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
int push_back(){
  // Zapis do pliku
  std::ofstream output("push_back.csv");
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, 2137, min, max);

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
int push_at(){
  // Zapis do pliku
  std::ofstream output("push_at.csv");
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, 2137, min, max);
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
int remove_front(){
    // Zapis do pliku
    std::ofstream output("remove_front.csv");
    if (!output.is_open()) {
      std::cerr << "Błąd otwierania." << std::endl;
      return 1;
    }
    output << "n;Lista wiązana;Tablica dynamiczna\n";
    // Zapis do pliku  
  
    List lista;
    DynamicArray tablica;
    
    int danestartowe[rozmiar];
    generujDane(danestartowe, rozmiar, 2137, min, max);
    
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
int remove_back(){
  // Zapis do pliku
  std::ofstream output("remove_back.csv");
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, 2137, min, max);
  
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
int remove_at(){
  // Zapis do pliku
  std::ofstream output("remove_at.csv");
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, 2137, min, max);
  
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

// Nie wiem co wymyslic do tego
int find(){
  // Zapis do pliku
  std::ofstream output("remove_back.csv");
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, 2137, min, max);
  
  // NIE CHCE MI SIE MYSLEC CZEGO SZUKAC

  output.close();
  return 0;
}

// Szuka wartosci na srodku
int at_position(){
  // Zapis do pliku
  std::ofstream output("at_position.csv");
  if (!output.is_open()) {
    std::cerr << "Błąd otwierania." << std::endl;
    return 1;
  }
  output << "n;Lista wiązana;Tablica dynamiczna\n";
  // Zapis do pliku

  List lista;
  DynamicArray tablica;
  
  int danestartowe[rozmiar];
  generujDane(danestartowe, rozmiar, 2137, min, max);
  
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