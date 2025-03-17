#include <iostream>
#include "list.hh"

List::List() { head = nullptr; }
List::~List() {
  //DELETE WSZYSTKO, ZEBY NIE BYLO WYCIEKU PAMIECI
}

void List::push_back(int val) {
  Node* newNode = new Node(val);
  if(head == nullptr) { //dodajemy na pierwszą pozycję, na head
    head = newNode;
  }
  else {
    Node* iter = head;
    while(iter->next != nullptr)
      iter = iter->next;

    iter->next = newNode;
  }
  
}

void List::push_front(int val) {
  Node* newNode = new Node(val);
  newNode->next = head; 
  head = newNode;
}

void List::push_at(unsigned int n, int val) {}

int List::remove_back() {}
int List::remove_front() {}
int List::remove_at(unsigned int n) {}

int List::find(int val) const {}
int List::at_position(unsigned int n) const {}

void List::_show() {
  Node* iter = head;
  if(iter != nullptr) {
    do {
      std::cout << iter->val << "->";
      iter = iter->next;
    } while(iter != nullptr);
    std::cout << "/0\n";
  }
  else
    std::cout << "Lista jest pusta!" << std::endl;
}
