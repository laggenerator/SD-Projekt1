#ifndef LISTA_H
#define LISTA_H

struct Node {
  int val;
  Node* next;
  
  Node(int v) : val(v), next(nullptr) {} // Konstruktor węzła
};

// Lista jednokierunkowa
class List {
private:
  Node* head; // Wskaźnik na początek listy

public:
  List();
  ~List(); 

  void push_back(int val);
  void push_front(int val);
  void push_at(unsigned int n, int val);

  int remove_back();
  int remove_front();
  int remove_at(unsigned int n);

  int find(int val) const;
  int at_position(unsigned int n) const;

  void _show();
};

#endif
