#include <iostream>
#include "list.hh"

List::List() { head = nullptr; tail = nullptr; size = 0;}
List::~List() {
  Node* iter = head;
  while (iter != nullptr) {
    Node* temp = iter;
    iter = iter->next;
    delete temp;
  }
}

void List::push_back(int val) {
  Node* newNode = new Node(val);
  if (head == nullptr) { // Lista jest pusta
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
  size++;
}

void List::push_front(int val) {
  Node* newNode = new Node(val, head);
  if(head == nullptr) { //dodajemy pierwszy element
    tail = newNode;
  }
  head = newNode;
  size++;
}

void List::push_at(const size_t n, int val) { //nowy element staje sie n-tym w liscie
  if(n <= size) { //indeksujemy oczywiscie od 0, wiec jeszcze jako n element mozna dodac, po prostu nowy na koncu
    if(n == 0)
      push_front(val);
    else if(n == size)
      push_back(val);
    else {
      Node* iter = head;
      for(size_t i = 0; i < n-1; ++i)
	iter = iter->next;
      Node* newNode = new Node(val, iter->next);
      iter->next = newNode;
      size++;
    }
  }
  else {
    throw std::invalid_argument("Indeks poza zakresem listy!");
  }
}

int List::remove_back() {
  if(size == 0)
    throw std::out_of_range("Nie ma czego usuwać!");

  int result;
  if(size == 1) {
    result = head->val;
    delete head;
    head = nullptr;
    tail = nullptr;
  }
  else {
    Node* iter = head;
    while(iter->next != tail)
      iter = iter->next;
    result = tail->val;
    tail = iter;
    delete tail->next;
    tail->next = nullptr;
  }
  size--;
  return result;
}

int List::remove_front() {
  if (size == 0) {
    throw std::out_of_range("Nie ma czego usuwać!");
  }

  int result = head->val;
  Node* temp = head;
  head = head->next;
  delete temp;
  
  if (--size == 0) { //jeśli lista stała się pusta, zresetuj `tail`
    tail = nullptr;
  }

  return result;
}

int List::remove_at(size_t n) {
  if(n >= size)
    throw std::invalid_argument("Indeks poza zakresem listy!");

  int result;
  if(n < size) { //indeksujemy oczywiscie od 0, wiec juz n nie mozna usunac: size = 3, 0 -> 1 -> 2 -> NULL
    if(n == 0)
      return remove_front();
    else if(n == size-1)
      return remove_back();
    else {
      Node* iter = head;
      for(size_t i = 0; i < n-1; ++i)
	iter = iter->next;
      Node* temp = iter->next; //usuwany element
      result = temp->val;
      iter->next = temp->next;
      delete temp;
      size--;
    }
  }

  return result;
}

Node* List::find(int val) const {
  if(size == 0)
    return nullptr;

  Node* iter = head;
  while(iter != nullptr) {
    if(iter->val == val)
      return iter;
    iter = iter->next;
  }
  
  return nullptr;
}

size_t List::find_index(int val) const {
  if(size == 0)
    return size;
  
  Node* iter = head;
  int i = 0;
  while(iter->val != val) {
    iter = iter->next;
    ++i;
    if(iter == nullptr)
      return size;
  }
  
  return i;
}

Node* List::at_position(size_t n) const {
  if(n >= size)
    throw std::out_of_range("Indeks jest poza zakresem!");

  Node* iter = head;
  for(size_t i = 0; i < n; ++i)
    iter = iter->next;

  return iter;
}

void List::_show() {
  Node* iter = head;
  if(iter != nullptr) {
    do {
      std::cout << iter->val << "->";
      iter = iter->next;
    } while(iter != nullptr);
    std::cout << "/0\n";
    std::cout << "head: " << head->val << " " << "tail: " << tail->val << std::endl;
  }
  else
    std::cout << "Lista jest pusta!" << std::endl;
}
