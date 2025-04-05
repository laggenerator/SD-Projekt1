#ifndef LISTA_H
#define LISTA_H

struct Node {
private:
  int val;
  Node* next;

public:
  Node(int v, Node* n = nullptr) : val(v), next(n) {} // Konstruktor węzła
  int value() { return val; }

  friend class List;
};

// Lista jednokierunkowa
class List {
private:
  size_t size;
  Node* head; // Wskaźnik na początek listy
  Node* tail; // Wskaźnik na koniec listy
  
public:
  List();
  ~List(); 

  void push_back(int val);
  void push_front(int val);
  void push_at(const size_t n, int val);

  int remove_back();
  int remove_front();
  int remove_at(size_t n);

  Node* find(int val) const; //po prostu zwraca wskaznik na element jesli go znajdzie, inaczej nullptr
  size_t find_index(int val) const; //zwraca „indeks” elementu jesli go znajdzie, inaczej zwroci size
  Node* at_position(size_t n) const;
  size_t get_size() { return size; }

  void _show();
};

#endif
